"""
-------------------------------------------------------------
Part 1: Insert EXTI GPIO Mapping Defines
-------------------------------------------------------------

This block inserts EXTI GPIO mapping macros for EXTI1–EXTI15
for ports A, B, C, D.

Example generated line:
#define EXTI1PA1 (EXTI_GPIO_MAPPING_t){EXTI1, GPIOA, GPIO_PIN_1, EXTI1_IRQ}

file_path = r"C:\\Users\\mm\\STM32CubeIDE\\Embedded\\Drivers\\stm32f103c6Drivers\\inc\\stm32f103c6_EXTI_Driver.h"

define_template = (
    "#define EXTI{n}P{port}{n} (EXTI_GPIO_MAPPING_t){{EXTI{n}, GPIO{port}, GPIO_PIN_{n}, EXTI{n}_IRQ}}\\n"
)

lines_to_add = []
for n in range(1, 16):
    for port in ['A', 'B', 'C', 'D']:
        line = define_template.format(n=n, port=port)
        lines_to_add.append(line)

with open(file_path, "r") as f:
    lines = f.readlines()

insertion_index = 200
new_lines = lines[:insertion_index] + lines_to_add + lines[insertion_index:]

with open(file_path, "w") as f:
    f.writelines(new_lines)

print(f"Inserted correct EXTI defines with matching line numbers at line {insertion_index + 1}")

-------------------------------------------------------------
End of Part 1
-------------------------------------------------------------
"""

##################################################
# ✅ Part 2: Insert NVIC IRQ Enable Defines
##################################################

# ✅ 1) Update this to your header file path
file_path = r"C:\Users\mm\STM32CubeIDE\Embedded\Drivers\stm32f103c6Drivers\inc\stm32f103x6.h"

# ✅ 2) IRQ mapping: EXTI0–EXTI15 to IRQ numbers
irq_map = {
    0: 6,
    1: 7,
    2: 8,
    3: 9,
    4: 10,
    5: 23,
    6: 23,
    7: 23,
    8: 23,
    9: 23,
    10: 40,
    11: 40,
    12: 40,
    13: 40,
    14: 40,
    15: 40
}

# ✅ 3) Generate NVIC enable define lines for each EXTI
define_lines = []
for exti_num, irq_num in irq_map.items():
    line = f"#define NVIC_IRQ{irq_num}_EXTI{exti_num}_ENABLE (NVIC_ISER0 |= 1<<{irq_num})\n"
    define_lines.append(line)

# ✅ 4) Insert at line 211 (index 210)
with open(file_path, "r") as f:
    lines = f.readlines()

insert_line = 210
lines = lines[:insert_line] + define_lines + lines[insert_line:]

# ✅ 5) Write updated content back
with open(file_path, "w") as f:
    f.writelines(lines)

print(f"✅ Successfully inserted NVIC IRQ defines at line 211 in {file_path}")
