# MCU Fundamentals - Complete Lecture Notes with Visuals

## 1. Embedded System Definition
![Embedded System](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8e/Embedded_System_Block_Diagram.svg/800px-Embedded_System_Block_Diagram.svg.png)
An embedded system is a dedicated computer system designed for specific tasks within a larger system. Key characteristics include real-time operation, resource constraints, and high reliability.

## 2. Microcontroller (MCU) vs Microprocessor (MPU)
![MCU Architecture](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7b/Microcontroller_Block_Diagram.svg/800px-Microcontroller_Block_Diagram.svg.png)
- **MCU**: All-in-one chip with processor, memory, and I/O
- **MPU**: Requires external components, more powerful

## 3. System on Chip (SoC)
![SoC Diagram](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d3/SoC_Structure.svg/1200px-SoC_Structure.svg.png)
Integrates all system components into a single chip, including processors, memory, and specialized accelerators.

## 4. Electronic Control Unit (ECU)
![Automotive ECU](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9e/ECU_VW_1.8T.jpg/800px-ECU_VW_1.8T.jpg)
Specialized embedded systems controlling vehicle subsystems, networked via automotive protocols like CAN bus.

## 5. Memory Management Unit (MMU)
![MMU Operation](https://www.sciencedirect.com/science/article/pii/S0065245820300449)
Handles virtual-to-physical address translation and memory protection.

## 6. Cache Memory
![Cache Hierarchy](https://upload.wikimedia.org/wikipedia/commons/thumb/0/0e/Cache_Hierarchy.svg/800px-Cache_Hierarchy.svg.png)
| Level | Speed | Size | Location |
|-------|-------|------|----------|
| L1    | Fastest | Smallest | On-chip |
| L2    | Medium | Medium | On-chip |
| L3    | Slowest | Largest | On/Off-chip |

## 7. OS vs Bare-Metal Software
![Bare-Metal vs OS](https://www.beningo.com/wp-content/uploads/2018/02/bare-metal-vs-rtos-architecture.png)
- **OS**: Abstraction layer, multi-tasking
- **Bare-metal**: Direct hardware access, minimal overhead

## 8. Memory Types
![ROM Types](https://www.electronicshub.org/wp-content/uploads/2015/05/Types-of-ROM.jpg)
- **ROM**: Non-volatile (PROM, EPROM, EEPROM)
- **RAM**: Volatile (SRAM, DRAM)
- **Hybrid**: FRAM, MRAM, PRAM

## 9. Von Neumann vs Harvard Architecture
![Architectures Comparison](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e5/Von_Neumann_Architecture.svg/800px-Von_Neumann_Architecture.svg.png)
- **Von Neumann**: Shared memory/bus
- **Harvard**: Separate memory/buses

## 10. Pipeline Processing
![CPU Pipeline](https://upload.wikimedia.org/wikipedia/commons/thumb/c/cb/Pipeline%2C_4_stage.svg/800px-Pipeline%2C_4_stage.svg.png)
5-stage pipeline: Fetch → Decode → Execute → Memory → Writeback

## 11. CISC vs RISC
![CISC vs RISC](https://www.researchgate.net/publication/334632656/figure/fig1/AS:783989396013056@1563998411253/Vehicle-Control-Units-Architecture-11.png)
| Feature | CISC | RISC |
|---------|------|------|
| Instructions | Complex | Simple |
| Execution | Multi-cycle | Single-cycle |
| Examples | x86 | ARM, RISC-V |