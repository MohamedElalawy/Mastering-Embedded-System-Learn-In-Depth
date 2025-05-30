 **NVIC** (Nested Vectored Interrupt Controller) and the **GIC** (Generic Interrupt Controller) are **not the same**, though they serve similar purposes: managing interrupts in ARM-based systems. Here's a breakdown of their differences:

---

### 🔹 **NVIC – Nested Vectored Interrupt Controller**

* **Used in:** ARM **Cortex-M** series (microcontrollers).
* **Purpose:** Manages interrupt priorities, enables/disables interrupts, supports nested interrupts.
* **Integrated:** Inside the Cortex-M core.
* **Simple and lightweight**, suitable for **bare-metal or RTOS-based** systems.
* **Registers:** Direct memory-mapped access to enable, disable, set priority, etc.

---

### 🔹 **GIC – Generic Interrupt Controller**

* **Used in:** ARM **Cortex-A** series (application processors, like in Linux-capable SoCs).
* **Purpose:** Handles interrupts in more complex, multi-core systems (e.g., smartphones, embedded Linux).
* **Separate hardware block** from the processor core.
* Supports **distribution** of interrupts among multiple cores.
* Supports **interrupt virtualization** for hypervisors.
* **More complex** than NVIC, with components like:

  * **Distributor**
  * **CPU Interface**
  * **Redistributors** (in GICv3 and later)

---

### 🔸 Summary Table

| Feature           | NVIC (Cortex-M)     | GIC (Cortex-A)            |
| ----------------- | ------------------- | ------------------------- |
| Target core       | Cortex-M (MCU)      | Cortex-A (Application)    |
| Complexity        | Simple              | Complex (multi-core, OS)  |
| Use case          | Bare-metal / RTOS   | Linux / Hypervisor        |
| Integration       | Inside the CPU core | External or semi-external |
| Interrupt nesting | Yes                 | Yes                       |
| Virtualization    | No                  | Yes                       |

---

