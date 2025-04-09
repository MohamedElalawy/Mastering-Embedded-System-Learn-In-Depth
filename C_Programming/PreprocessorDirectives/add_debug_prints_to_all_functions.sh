
## Shell script that recursively searches through all C/C++ source files in a folder (.c, .cpp, .h, .hpp), detects function definitions, and inserts a debug print using your DPRINTF macro :
```bash
#!/bin/bash

DEBUG_LEVEL=3

find . -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) | while read -r file; do
    echo "Processing $file..."

    awk -v debug_level="$DEBUG_LEVEL" '
    BEGIN {
        inside_func = 0
        brace_depth = 0
        funcname = ""
    }

    function trim(s) {
        sub(/^[ \t]+/, "", s)
        sub(/[ \t]+$/, "", s)
        return s
    }

    # Detect function definition and opening brace
    /^[a-zA-Z_][a-zA-Z0-9_ \t\*]*\([^\)]*\)[ \t]*\{/ {
        funcname = gensub(/^.*\b([a-zA-Z_][a-zA-Z0-9_]*)[ \t]*\(.*/, "\\1", "g", $0)
        inside_func = 1
        brace_depth = 1
        print
        next
    }

    inside_func == 1 {
        open_count = gsub(/\{/, "{", $0)
        close_count = gsub(/\}/, "}", $0)
        brace_depth += open_count - close_count

        if (brace_depth == 0 && trim($0) == "}") {
            printf("    DPRINTF(%d, \"Exiting %s\\n\");\n", debug_level, funcname)
            print $0
            inside_func = 0
            next
        }
        print
        next
    }

    { print }
    ' "$file" > "$file.tmp" && mv "$file.tmp" "$file"
done

echo "DPRINTF inserted at the end of functions."
```
![Screenshot 2025-04-09 190642](https://github.com/user-attachments/assets/43b89904-e341-4580-9ced-c74ff7143bf9)

![Screenshot 2025-04-09 190707](https://github.com/user-attachments/assets/b83b31bd-09b6-4fd4-ad38-779d86ba430c)
