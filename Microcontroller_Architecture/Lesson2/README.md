
Unit 6 (MCU Fundamentals) - Lesson 2
Port-mapped I/O
 * Instruction Usage: Uses special machine instructions specifically designed for I/O operations.
 * Address Space: The memory address space and the I/O device address space are independent of each other.
 * Addressing: Each device is assigned one or more unique port numbers.
 * Example: Intel x86 processors use IN and OUT instructions to read from or write to a port.
Memory-mapped I/O
 * Instruction Usage: Does not require any special instructions; it uses the native load and store instructions of the processor.
 * Address Space: The memory and the I/O devices share the same address space.
 * Addressing: Each peripheral register or data buffer is assigned to a memory address within the microprocessor's memory address space.
 * Performance: Performed by the native load and store instructions of the processor.
In essence, the key difference lies in how the CPU interacts with peripheral devices: Port-mapped I/O uses dedicated I/O instructions and a separate address space, while Memory-mapped I/O treats peripheral registers as memory locations and uses standard memory access instructions.

MCU Memory Map
 * Access Register Methods:
   * Method 1: Using numeric memory address directly
   * Method 2: Casting an address to a pointer
   * Method 3: Casting to a pointer and then dereferencing it
   * Method 4: Use structure, union, and pointer for one register
   * Method 5: Use structures and pointers for all registers in a GPIO peripheral
 * Memory Map Concepts:
   * The CPU can issue transactions to 2^32 (4G Bytes) different addresses if the system bus is 32-bit.
   * In Memory Mapped I/O, there is no overlap address between the peripherals.
   * Example: ODR absolute address = GPIO_Base_address + ODR_offset = 0x48000400 + 0x4 = 0x48000404
Port-mapped I/O
 * Uses special machine instructions designed specifically for I/O operations.
 * The memory address space and the I/O device address space are independent of each other.
 * Each device is assigned one or more unique port numbers.
 * Example: Intel x86 processors use IN and OUT instructions to read from or write to a port.
Memory-mapped I/O
 * Does not need any special instructions.
 * The memory and the I/O devices share the same address space.
 * Each peripheral register or data buffer is assigned to a memory address in the memory address space of the microprocessor.
 * Performed by the native load and store instructions of the processor.
MCU Bus Interfaces
 * AMBA Bus Architecture and Protocols (Advanced Microcontroller Bus Architecture):
   * A set of interconnect specifications from ARM that standardizes on-chip communication mechanisms between various functional blocks (or IP) for building high-performance SoC designs.
   * These designs typically have one or more microcontrollers or microprocessors along with other components like internal/external memory bridges, DSP, DMA, accelerators, and various peripherals (USB, UART, PCIE, I2C) integrated on a single chip.
   * Why use AMBA?
     * IP reuse: Essential in reducing SoC development costs and manufacturing time. AMBA specifications provide the interface standard that enables IP reuse.
     * Flexibility: Offers flexibility to work with a range of SoCs.
   * Bus Interface Performance:
     * Bandwidth: The rate at which data can be driven across the interface in an asynchronous system. Limited by clock speed and data bus width.
     * Latency
   * AMBA Protocols:
     * AHB (Advanced High-performance Bus): Used for connecting components that need higher bandwidth on a shared bus (e.g., internal memory, external memory interface, DMA, DSP). It is a shared bus protocol for multiple masters and slaves.
     * ASB (Advanced System Bus): Used for high bandwidth interconnect.
     * APB (Advanced Peripheral Bus): Used for connecting low-bandwidth peripherals. It is a simple non-pipelined protocol for communication from a bridge/master to slaves through a shared bus.
     * AXI (Advanced Extensible Interface): Introduced in AMBA 3 (2003) as a point-to-point connectivity protocol. Enhanced in AXI 4 (2010). Useful for high bandwidth and low latency interconnects. Enhancements over AHB include support for multiple outstanding data transfers (pipelined), burst data transfers, separate read and write paths, and different bus widths.
       * AXI Channels:
         * Write Address Channel: Master sends memory address for writing data.
         * Write Data Channel: Master sends data to the slave.
         * Write Response Channel: Slave indicates completion of write operation to the master.
         * Read Address Channel: Master specifies the address for a read operation from the slave.
         * Read Data Channel: Slave sends data to the master when ready. Slave returns an error if the address is invalid, data is corrupted, or access permissions are insufficient.
 * Bus Matrix
 * Bus Bridges
Technical Questions about the BUS
 * In TM4C123, the system bus is not connected with flash memory (True).
 * In TM4C123, the system bus can operate at speeds up to 80MHz (True).
 * In STM32F103xx, APB1 Bus can work with speed up to 72 MHz (False).
 * APB1 BUS peripheral register base address in STM32F103xx is 0x4000_0000.
 * GPIOA module base address in STM32F103xx is 0x4001_0800.
 * Address for CAN Bit Timing "CANBIT" register in CAN Controller 1 in TM4C123: Base address = 0x4004_1000, Offset = 0x000C, CANBIT_address = 0x4004_100C.


Data Units
The lecture notes mention the following data units:
 * Bit: The smallest unit of data in computing, representing a binary value of either 0 or 1.
 * Byte: Typically consists of 8 bits.
 * Halfword: Often refers to 2 bytes (16 bits).
 * Word: The size of a word can vary depending on the architecture, but it's typically 4 bytes (32 bits) on 32-bit systems.
 * Double-word: Usually refers to 2 words, or 8 bytes (64 bits).
 * Nibble: Consists of 4 bits, or half a byte.
Big and Little Endian
These terms describe the order in which bytes are stored in computer memory for multi-byte data types.
 * Big Endian: The most significant byte (MSB) of a multi-byte value is stored at the lowest memory address, and the least significant byte (LSB) is stored at the highest address.
 * Little Endian: The least significant byte (LSB) of a multi-byte value is stored at the lowest memory address, and the most significant byte (MSB) is stored at the highest address.
The lecture notes provide an example where an assembly instruction "LDR rl, [r0]" loads a 32-bit value from memory address 0x20008000 to register rl. The result in register rl would differ depending on whether big-endian or little-endian ordering is used for storing the 32-bit value in memory.
