file_path = r"C:\Users\mm\STM32CubeIDE\Embedded\Drivers\stm32f103c6Drivers\inc\stm32f103c6_EXTI_Driver.h"

define_template = (
    "#define EXTI{n}P{port}{n} (EXTI_GPIO_MAPPING_t){{EXTI{n}, GPIO{port}, GPIO_PIN_{n}, EXTI{n}_IRQ}}\n"
)

lines_to_add = []
for n in range(1, 16):
    for port in ['A', 'B', 'C', 'D']:
        line = define_template.format(n=n, port=port)
        lines_to_add.append(line)

with open(file_path, "r") as f:
    lines = f.readlines()

insertion_index = 71
new_lines = lines[:insertion_index] + lines_to_add + lines[insertion_index:]

with open(file_path, "w") as f:
    f.writelines(new_lines)

print(f"Inserted correct EXTI defines with matching line numbers at line {insertion_index + 1}")
