# Lecture Notes: MCU Fundamentals (Unit 6, Lesson 1)

## 1. Embedded System Definition
An embedded system is a dedicated computer system designed to perform specific tasks within a larger mechanical or electrical system. Unlike general-purpose computers, embedded systems are typically optimized for their particular functions with constraints on size, power consumption, and cost.

Key characteristics:
- Single-functioned (dedicated to a specific task)
- Real-time operation constraints
- Resource-constrained (limited memory, processing power)
- Often part of a larger system
- High reliability requirements

Examples include microwave oven controllers, automotive engine control units, and medical device controllers.

## 2. Deep Dive into Key Components and Terms

### Microcontroller Unit (MCU)
A microcontroller is a compact integrated circuit that combines a processor core with memory and programmable input/output peripherals. Key features:
- All components on a single chip
- Designed for embedded applications
- Typically lower power consumption than MPUs
- Often includes analog components (ADCs, DACs)

### Microprocessor Unit (MPU)
A microprocessor is the central processing unit (CPU) of a computer system that performs arithmetic and logic operations. Unlike MCUs:
- Requires external memory and peripherals
- More powerful for general computing
- Used in computers, servers, and high-performance systems

### System on Chip (SoC)
An SoC integrates all components of a computer or electronic system into a single chip. It may include:
- One or more processor cores (MCUs, MPUs, or both)
- Memory blocks
- Communication interfaces
- Specialized accelerators (GPUs, DSPs)
- Analog components

### Electronic Control Unit (ECU)
An ECU is a type of embedded system that controls electrical systems or subsystems in vehicles. Features:
- Real-time operation
- Automotive-grade reliability
- Networked via CAN bus or other automotive protocols
- Examples: Engine control, ABS, airbag systems

### Memory Management Unit (MMU)
The MMU handles memory access requested by the CPU. Its functions include:
- Virtual to physical address translation
- Memory protection
- Cache control
- Enables operating systems with memory protection

### Floating-Point Unit (FPU)
A specialized coprocessor that performs floating-point arithmetic operations. Benefits:
- Faster than software emulation
- Higher precision
- Standardized operations (IEEE 754)

### Microprocessor Unit (MPU) Variations
MPUs come in many configurations:
- Different architectures (x86, ARM, RISC-V)
- Single-core vs multi-core
- Different clock speeds
- Various instruction sets
- Power profiles (high-performance to ultra-low-power)

## 3. Integrated Circuits and Moore's Law

### Integrated Circuits (IC)
Miniaturized electronic circuits consisting of semiconductor devices and passive components fabricated on a semiconductor material (typically silicon).

Types:
- Digital ICs (process discrete signals)
- Analog ICs (process continuous signals)
- Mixed-signal ICs (combine both)

### Moore's Law
The observation that the number of transistors in a dense integrated circuit doubles about every two years. Implications:
- Exponential growth in computing power
- Decreasing cost per transistor
- Increasing challenges in power dissipation and quantum effects at small scales

Current status:
- Physical limits being approached
- Alternative approaches being developed (3D ICs, new materials)

## 4. Cache Memory

### Cache Hierarchy
Modern systems use multiple levels of cache:

| Feature       | L1 Cache          | L2 Cache           | L3 Cache           |
|--------------|------------------|-------------------|-------------------|
| Size         | Smallest (KB)     | Medium (MB)        | Largest (MB)       |
| Speed        | Fastest           | Moderate           | Slowest           |
| Location     | On-chip           | On-chip            | On-chip/Off-chip   |
| Purpose      | Instruction/data  | Shared between cores | Shared between all cores |

### Cache Coherence
The consistency of shared resource data that ends up stored in multiple local caches. Solutions:
- Snooping protocols
- Directory-based protocols
- MESI protocol (Modified, Exclusive, Shared, Invalid)

## 5. OS Software vs Bare-metal Software

### Operating System Software
- Provides abstraction layer for hardware
- Manages resources (memory, tasks, I/O)
- Enables multi-tasking
- Includes device drivers
- Examples: Linux, FreeRTOS, VxWorks

### Bare-metal Software
- Runs directly on hardware without OS
- Maximum control over hardware
- Minimal overhead
- Used in real-time critical applications
- Developer must handle all hardware interactions

## 6. MCU Memory Types

### Read-Only Memory (ROM)
- Non-volatile (retains data without power)
- Types:
  - Mask ROM (factory programmed)
  - PROM (Programmable ROM, one-time programmable)
  - EPROM (Erasable PROM, UV erasable)
  - EEPROM (Electrically Erasable PROM, byte-level erase)
  - Flash (block-level erase, faster than EEPROM)

### Random Access Memory (RAM)
- Volatile (loses data without power)
- Types:
  - SRAM (Static RAM)
    - Faster
    - More expensive
    - No refresh needed
    - Used for cache
  - DRAM (Dynamic RAM)
    - Slower
    - Less expensive
    - Needs refresh
    - Used for main memory

### Hybrid Memory
Combines characteristics of ROM and RAM:
- FRAM (Ferroelectric RAM)
- MRAM (Magnetoresistive RAM)
- PRAM (Phase-change RAM)
- RRAM (Resistive RAM)

## 7. Von Neumann vs Harvard Architecture

### Von Neumann Architecture
- Single shared memory for instructions and data
- Single bus for both data and instructions
- Bottleneck at memory access
- Simpler design
- Most general-purpose computers use this

### Harvard Architecture
- Separate memories for instructions and data
- Separate buses for instructions and data
- Higher performance
- More complex design
- Common in DSPs and MCUs

Modern processors often use modified Harvard architecture with separate caches but unified main memory.

## 8. Pipeline Processing

A technique where multiple instructions are overlapped in execution. Stages typically include:
1. Fetch
2. Decode
3. Execute
4. Memory access
5. Write back

Benefits:
- Increased instruction throughput
- Better resource utilization

Challenges:
- Pipeline hazards (structural, data, control)
- Branch prediction needed
- Increased complexity

## 9. CISC vs RISC

### Complex Instruction Set Computer (CISC)
- Many complex instructions
- Variable length instructions
- Instructions perform multiple operations
- More compact code
- Examples: x86, 68000

### Reduced Instruction Set Computer (RISC)
- Fewer, simpler instructions
- Fixed length instructions
- Load/store architecture
- Pipelining more efficient
- Examples: ARM, MIPS, RISC-V

Modern processors often blend characteristics (ARM has some CISC features, x86 decodes to RISC-like micro-ops).

---



# Mastering Embedded System Online Diploma - Unit 6 (MCU Fundamentals) Lesson 1

## What is Embedded System

An **embedded system** is a special-purpose computer system designed to perform one or a few dedicated functions, often with real-time computing constraints [4, 7]. It is usually embedded as part of a complete device including hardware and mechanical parts [7]. Unlike a general-purpose computer like a personal computer, which can perform many different tasks based on programming, an embedded system is designed for specific tasks [7]. Embedded systems control many common devices used today [8].

## Deep Dive in uc, up, SoC, ECU, MMU, FPU, MPU

This section delves into the definitions and relationships between various processing units and related components.

### Integrated circuits (IC)

An **integrated circuit (IC)** is a single chip containing a set of electronic circuits [7]. These circuits are designed using transistors that act as resistors, capacitors, inductors, switches, etc., enabling the creation of very small-sized integrated circuits [7]. **VLSI circuits (Very Large Scale Integrated circuits)** are a newer form of ICs capable of performing complex tasks [7]. Microprocessors, microcontrollers, and System on Chips (SoCs), as well as components like RAM and ROM, are all made of ICs [9].

### Moore's Law

**Moore's Law** states that the density of transistors in an IC will double approximately every 2 years [10]. This is evident in the progression of processor technology, moving from 14nm to 7nm processors [10]. As the size of a transistor decreases, more transistors can be included in a processor (IC) [10].

### Microprocessors (µP, uP, MPU, or CPU)

A **microprocessor** is an integrated circuit capable of performing arithmetic and logical operations [11]. It consists only of a **Central Processing Unit (CPU)** [11]. Microprocessors are generally used for general computing purposes, such as in personal computers and servers [11]. The first microprocessor, the Intel 4004, was developed by Intel in 1971 [11].

The CPU is considered the "brain" of the computer system [12]. A particular computer will have a specific type of processor, like a Pentium or a SPARC chip [12]. The CPU contains the following main components:
*   **Arithmetic/Logic Unit (ALU)**: Performs calculations and decisions [13].
*   **Control Unit (CU)**: Coordinates processing steps [13].
*   **Registers**: Small, fast storage areas for instructions and data [13].

Co-processors can assist the CPU with some processing functions, such as math co-processors for heavy-duty math or graphics coprocessors for speeding up graphics display [12].

The internal structure of a microprocessor includes the ALU, Register Section, and Control and Timing section, connected by the Address bus, Data bus, and Control bus [14].

**Instruction Life Cycle: Fetch-Decode-Execute** [15]
*   **Fetch**: Get the instruction from memory and increment the Program Counter (PC) [15].
*   **Decode**: Determine what the instruction is (e.g., add) [15].
*   **Execute**: Perform the operation specified by the instruction (e.g., add the contents of two registers and put the result in a third register) [15].

### Microcontrollers (µC, uC, or MCU)

A **microcontroller** is also an IC, but it consists of a CPU and other components like RAM, ROM, and I/O ports [16]. It can be considered an extension of the microprocessor [16]. Microcontrollers are used in embedded systems [16]. A microcontroller is a small computer on a single integrated circuit containing a processor core, memory, and programmable input/output peripherals [17]. Microcontroller units (MCUs) come in many shapes, sizes, and configurations [18, 19].

### System on Chips (SoC)

A **System on Chip (SoC)** is a high-performance microcontroller [20]. SoCs have more components than a typical microcontroller, including not only memory components like RAM but also GPUs, Modems, and DSPs [20]. These SoCs are used in mobile devices such as smartphones and tablets because they consume less power and offer higher efficiency without compromising performance [20]. SoCs include high-performance CPUs (potentially with more than one cluster), high-performance peripherals like graphics/sound peripherals (IPU, DU, LVDS, etc.), network peripherals, and storage/communication peripherals (SDCARD/USB) [20].

### Difference Between IC, MPU, MCU, SoC, and ECU

*   **IC (Integrated Circuit)**: A single chip with electronic circuits [7].
*   **MPU (Microprocessor Unit)**: An IC that only consists of a CPU [11, 21]. MPU = CPU [21].
*   **MCU (Microcontroller Unit)**: An IC that consists of a CPU, peripherals, and memory [16, 21]. MCU = MPU + Peripherals + Memory [21].
*   **SoC (System on Chip)**: A high-performance MCU with secondary cores like a GPU or DSP [20, 21]. SoC = (High Performance) MCU + Secondary Cores (GPU/DSP) [21].
*   **ECU (Electronic Control Unit)**: Any embedded system in automotive electronics that controls one or more electrical systems or subsystems in a vehicle [22]. An ECU can contain multiple SoCs and/or MCUs, along with sensors, actuators, and off-chip controllers [21]. ECU = N number of SoC/MCU + Sensors + Actuators + off-chip Controllers + ... [21].

Peripheral types mentioned include Basic Peripherals (GPIO, Clock Controller, Timers, ADC, DAC, Reset Controller), Serial Peripherals (UART, SPI, I2C), Automotive Network Peripherals (CAN/CANfd, LIN, FlexRay, AutoEthernet), and High performance Peripherals (Graphics/Sound, MMC/SD, USB/Network Controllers) [21].

### Electronic Control Unit (ECU)

An **electronic control unit (ECU)** is an embedded system found in automotive electronics that manages one or more of the electrical systems or subsystems in a vehicle [22]. Examples of ECUs include the engine control module (ECM), transmission control module (TCM), brake control module (BCM or EBCM), central control module (CCM), general electronic module (GEM), and body control module (BCM) [22, 23]. These control various functions like air-fuel mixture, idle speed, power windows, mirrors, air conditioning, immobilizer systems, and central locking [22, 23].

### Floating-Point Unit (FPU)

Early CPUs were designed for fixed-point arithmetic operations [24]. More complex floating-point operations were performed by breaking them down into simpler steps [24]. To speed up floating-point operations, a special **floating-point unit (FPU)** was added [24]. The FPU's role is to carry out addition, subtraction, multiplication, division, square root, and bit-shifting operations on floating-point values [24].

### Memory Protection Unit (MPU) and Memory Management Unit (MMU)

A **memory protection unit (MPU)** allows software, such as the operating system (OS), to define regions in memory and assign access permissions and attributes to those regions [25]. The MPU monitors transactions between the CPU and memory and triggers a fault exception if an access violation is detected [25]. The primary purpose of the MPU is to prevent a program from accessing memory that has not been allocated to it [25]. Microprocessor units (MPUs) come in many shapes, sizes, and configurations [26].

An **MMU (memory management unit)** is an upgrade to the MPU [27]. The MMU's task is to translate the virtual addresses used by programs into physical addresses in the main memory [27].

## Integrated circuits(IC)/Moore's Law

As mentioned above, an integrated circuit is a single chip containing a set of electronic circuits built using transistors [7]. Moore's Law describes the trend of doubling transistor density on an IC every two years [10].

## Cache Memory

**Cache memory** is a small, high-speed memory located close to the CPU [28, 29]. It is used to store frequently accessed instructions and data to reduce the time it takes for the CPU to access them from main memory [29-31].

The hard disk is too slow to provide instructions directly to the CPU, so programs are first loaded into main memory [32]. As CPU speeds increased, main memory became a bottleneck [30]. Cache memory was introduced between the CPU and main memory to provide instructions at a faster rate [30].

When an instruction or data is accessed from main memory, a copy is placed in the cache [31]. Subsequent access to the same instruction or data is faster because it is retrieved directly from the cache [31].

There is a hierarchy of caches, commonly referred to as L1, L2, and L3 caches [33].
*   **L1 cache**: Typically on the same silicon wafer as the CPU, providing instructions at the same clock speed as the CPU [31, 34, 35]. It can be divided into Instruction Cache and Data Cache [34, 35].
*   **L2 cache**: An additional cache, which may be off-chip, that interacts with the CPU at a slower speed than L1 cache [31, 34, 35].
*   **L3 cache**: Another level of cache in the hierarchy [33, 35].

When the processor needs to access a memory location, it first checks the cache [33].
*   **Cache hit**: If the memory location is found in the cache, data is read from the cache [33].
*   **Cache miss**: If the memory location is not found in the cache, the cache allocates a new entry and copies the data from main memory, then fulfills the request from the cache [36].

The performance of cache memory is often measured by its **Hit ratio**, which is the number of hits divided by the total accesses [36].

Cache memory is made of **SRAM** (Static Random Access Memory) [37].

**Cache coherence** is a discipline in shared memory multiprocessor systems with separate caches for each processor [38]. It ensures that changes made to shared data in one cache are reflected in the other copies of that data throughout the system in a timely manner [38].

## Comparison between L1, L2 and L3 Cache Memory

The sources mention the existence of L1, L2, and L3 caches as a hierarchy [33, 39, 40]. L1 is the fastest and closest to the CPU, L2 is slower than L1 but faster than main memory, and L3 is slower than L2 but still faster than main memory [29-31]. The hierarchy and interaction between these levels are illustrated in slides 51-54 [34, 35].

## OS SW Vs Bare-metal SW

This section discusses the difference between developing software with and without an operating system.

### Bare metal SW

"Bare metal" programming means your application directly accesses the silicon chip without any intermediary like an operating system [41]. The application is the only software running on the microprocessor/microcontroller [41]. Drivers and the BIOS can be considered bare metal code [41].

### OS Application

Writing an application on top of an operating system means the OS manages the hardware and provides services to the application [42]. While the choice of OS for desktop computers is limited (Windows, Apple, Linux), the selection for embedded systems is much more complex due to the wide diversity of embedded applications and available options [42].

## MCU Memory Types (ROM, RAM, Hybrid) in details

This section details the different types of memory found in MCUs.

### Memory Basics

Memory stores data [43].

### RAM (Random Access Memory)

**RAM** is read-write memory, meaning data at any location can be read or written [6]. It is **volatile memory**, which means it retains its contents only as long as electricity is supplied [6]. Data access to RAM is very fast [6]. RAM is based on Mosfets [6].

### SRAM (Static Random Access Memory)

**SRAM** storage cells are made of flip-flops and do not require refreshing to keep their data [44].

*   **Benefits of SRAM**:
    *   Better performance than DRAM in terms of speed [44].
    *   Used to create speed-sensitive cache [44].
    *   Medium power consumption [44].

*   **Drawbacks of SRAM**:
    *   More expensive compared to DRAM [44].
    *   More complex design [44].
    *   Each cell requires at least 6 transistors to build, holding only 1 bit [44].
    *   Capacity is lower than DRAM [45].
    *   Data is lost when power is lost [45].

Microcontrollers are always based on SRAM because it has much lower power consumption [46].

### DRAM (Dynamic Random Access Memory)

**DRAM** uses 1 transistor and 1 capacitor per cell [47]. DRAM is **volatile**, losing data content on power loss [47]. DRAM is fast compared to Flash [47].

DRAM capacitors require constant refreshing due to charge leakage [48-50]. This refreshing happens frequently (e.g., 16 times per second or more) to prevent data loss [50]. While DRAM is being refreshed, its data cannot be accessed, unlike SRAM [51].

*   **Benefits of DRAM**:
    *   Lower price and power consumption compared to SRAM [51].
    *   Using a capacitor reduces the number of transistors needed per cell [51].

*   **Drawbacks of DRAM**:
    *   Capacitors require constant refreshing [51].
    *   Data cannot be accessed while refreshing [51].

PCs are based on DRAM because it has a much lower cost, which is important for the larger RAM sizes needed [46].

### ROM (Read Only Memory)

**ROM** is read-only memory, where data at any location can only be read [52]. It is **non-volatile**, meaning its contents are retained even when electricity is switched off [52]. Data access to ROM is slow compared to RAM [52]. ROM is based on Floating Gate Mosfets [52].

Programs and data that need to be permanently stored are kept in ROM devices [18]. ROM retains its contents even without power, making it suitable for storing program codes and permanent data needed to initialize and operate embedded systems [18].

Various types of ROM devices are available [18].

*   **PROM (Programmable ROM)**: Can be programmed only once by the user using a PROM programmer or burner [18, 53]. For every bit, there is a fuse [18]. It is also called OTP (one-time programmable) [18]. Data stored in PROM cannot be modified [53].

*   **Mask ROM**: Not user-programmable; its contents are programmed by the IC manufacturer during the manufacturing process [19]. It is cheaper than other kinds of ROMs and is also one-time programmable (OTP) [19].

*   **EPROM (Erasable ROM)**: Can be programmed many times [54]. An EPROM programmer is needed for programming [54]. It can be programmed and erased thousands of times [54]. The programming process is not electrically reversible [54]. A widely used type is UV-EPROM, which has a window for shining ultra-violet radiation to erase its contents [54]. UV light causes ionization, dissipating the stored charge and deleting the memory [54].
    *   **Advantages of EPROM**: Non-volatile (retains memory without power) [55]. Reprogrammable (data can be erased and reprogrammed) [55].
    *   **Disadvantages of EPROM**: Requires UV light for erasing [55]. Cannot erase a particular byte; the whole data is deleted [55].

### Hybrid Memory

**Hybrid memory** combines features of both RAM and ROM [5]. Its contents can be read and written like RAM, but its contents are non-volatile like ROM [5].

*   **EEPROM (Electrically Erasable Programmable ROM)**: Non-volatile (content is not lost on power down) [56]. Allows unlimited READ operations [56]. Can be connected serially through interfaces like I2C or SPI [56]. Can be reprogrammed/rewritten in bytes, pages, or the whole IC using electrical charge [56]. EEPROM is a replacement for both PROM and EPROM [56]. It is used in many applications to store, erase, and reprogram data [56].

*   **Flash memory**: The most recent advancement in memory technology [57]. Flash memory devices are high density, low cost, nonvolatile, fast, and electrically reprogrammable [57]. Flash is much more popular than EEPROM and is rapidly replacing many ROM devices [57].

*   **NVRAM (Non-Volatile RAM)**: SRAM with battery backup to retain contents even when power is off [58]. It is very expensive but offers fast data access [58]. One type uses an internal lithium battery as a backup [58]. Another type combines SRAM and EEPROM, writing the SRAM content to EEPROM when power is off and reading it back when power is restored [59].

## MCU BUS Interfaces Von Neumann, Harvard

This section discusses different computer architectures based on how memory and instructions are accessed via buses.

### Computer Bus

A **bus** is a set of parallel conductors that transfer data between different computer components [60]. A bus has three main parts [60]:
*   **Data bus**: Carries data [60].
*   **Address bus**: Carries the address of data [60].
*   **Control bus**: Carries control signals [60].

### Von-Neumann architecture

In the **Von-Neumann architecture**, the same memory and bus are used to store both Data and Instructions [61]. A bottleneck occurs because the CPU cannot access program memory and data memory simultaneously [61]. When a computation is finished, the output needs to move to memory across the same bus used for fetching instructions or data [61]. If the bus is busy, the output has to wait [61].

### Harvard architecture

The **Harvard architecture** stores machine instructions and data in separate memory units using different buses [62]. The main advantage is that this architecture can run a program and access data independently and simultaneously, which removes the bottleneck of the Von-Neumann architecture [62]. Harvard architecture is more complicated but the separate pipelines improve performance [62].

### Modified Harvard Architecture

The majority of modern computers technically use a **Modified Harvard Architecture** [63]. Although there is no physical separation of memory spaces for data and instructions, they have two separate address spaces and different buses [63].

### Why Von Neumann is used in Computer and Harvard is used in MCU?

*   **Signal Length**: To minimize external signal pins, microprocessors often use a common data and address bus for both data and instructions [64]. Microcontrollers typically have internal memory, making it easier to have separate data and address buses for data and instructions [64].
*   **Memory Storage**: Microprocessors usually load programs from external devices (hard drive, SSD, USB) into RAM, where data is also stored, leading to a natural fit with the Von Neumann architecture [65]. Microcontrollers typically have programs burned into flash memory (or earlier ROM types) and use separate RAM for data, which lends itself to the Harvard architecture with its distinct memories and separate buses for faster access [65].

## Pipeline

The sources mention "Pipeline" as a topic covered in the lecture [2, 66], but do not provide a detailed explanation of what it is or how it works. (External knowledge would be needed to explain this concept, but that is outside the scope of this response based solely on the provided sources).

## CISC Vs RISC

This section compares two different types of instruction set architectures.

**Computer Systems: Not All Processors Are Created Equal** [67]
Newer machines use specialized processor chips developed to speed up data processing [67].

*   **CISC (Complex instruction set computer)**: Has a large instruction set with many formats [67, 68]. An example is the X86 architecture [67].
*   **RISC (Reduced instruction set computer)**: Has a small instruction set with single or small variations in format [67, 68]. Most instructions are designed to execute in 1 cycle (LOAD, STORE, etc.) [67]. Used in processors like PowerPc, ARM CPUs, and Qualcomm [67]. Often used for power efficiency or in mobile devices [67].



