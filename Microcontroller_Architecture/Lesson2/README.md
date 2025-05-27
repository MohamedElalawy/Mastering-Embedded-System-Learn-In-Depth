
# Unit 6 (MCU Fundamentals) - Lesson 2

---

## Port-mapped I/O

- **Instruction Usage**: Uses special machine instructions specifically designed for I/O operations.
- **Address Space**: The memory address space and the I/O device address space are independent of each other.
- **Addressing**: Each device is assigned one or more unique port numbers.
- **Example**: Intel x86 processors use `IN` and `OUT` instructions to read from or write to a port.

## Memory-mapped I/O

- **Instruction Usage**: Does not require any special instructions; it uses the native load and store instructions of the processor.
- **Address Space**: The memory and the I/O devices share the same address space.
- **Addressing**: Each peripheral register or data buffer is assigned to a memory address within the microprocessor's memory address space.
- **Performance**: Performed by the native load and store instructions of the processor.

> **Summary**:  
> - **Port-mapped I/O** uses dedicated I/O instructions and a separate address space.  
> - **Memory-mapped I/O** treats peripheral registers as memory locations and uses standard memory access instructions.

---

## MCU Memory Map

### Access Register Methods

1. Using numeric memory address directly  
2. Casting an address to a pointer  
3. Casting to a pointer and then dereferencing it  
4. Using structure, union, and pointer for one register  
5. Using structures and pointers for all registers in a GPIO peripheral  

### Memory Map Concepts

- A 32-bit system bus can address up to `2^32` (4 GB) different addresses.
- In Memory-mapped I/O, there is **no overlapping** of addresses between peripherals.
- **Example**:

ODR absolute address = GPIO_Base_address + ODR_offset
= 0x48000400 + 0x4
= 0x48000404

---

## MCU Bus Interfaces

### AMBA Bus Architecture and Protocols

A set of interconnect specifications from ARM for building high-performance SoC designs.

#### Components Typically Found:

- Microcontrollers/Microprocessors
- Internal/External Memory Bridges
- DSP, DMA, Accelerators
- Peripherals (USB, UART, PCIE, I2C)

#### Why Use AMBA?

- **IP Reuse**: Reduces development cost and time.
- **Flexibility**: Supports a wide range of SoC configurations.

### Bus Interface Performance

- **Bandwidth**: Rate of data transfer, limited by clock speed and bus width.
- **Latency**: Delay between request and actual data transfer.

### AMBA Protocols

- **AHB** (Advanced High-performance Bus): For high-bandwidth shared bus (memory, DMA, DSP).
- **ASB** (Advanced System Bus): For high-bandwidth interconnect.
- **APB** (Advanced Peripheral Bus): For low-bandwidth peripherals; simple and non-pipelined.
- **AXI** (Advanced Extensible Interface):
- Introduced in AMBA 3 (2003), improved in AXI 4 (2010).
- Features: pipelining, burst transfers, separate read/write paths, variable bus widths.

#### AXI Channels

- **Write Address Channel**: Master sends write address.
- **Write Data Channel**: Master sends data.
- **Write Response Channel**: Slave acknowledges write.
- **Read Address Channel**: Master sends read address.
- **Read Data Channel**: Slave returns data or error.

### Other Bus Components

- **Bus Matrix**
- **Bus Bridges**

---

## Technical Questions about the BUS

- **TM4C123**: System bus is not connected with flash memory → ✅ True  
- **TM4C123**: System bus can operate at up to 80 MHz → ✅ True  
- **STM32F103xx**: APB1 Bus can work up to 72 MHz → ❌ False  
- **STM32F103xx**: APB1 base address = `0x40000000`  
- **STM32F103xx**: GPIOA base address = `0x40010800`  
- **TM4C123**: `CANBIT` register in CAN Controller 1 →

Base address = 0x40041000
Offset = 0x000C
CANBIT_address = 0x4004100C

---

## Data Units

- **Bit**: Smallest unit, 0 or 1.
- **Byte**: 8 bits.
- **Halfword**: 2 bytes (16 bits).
- **Word**: Typically 4 bytes (32 bits).
- **Double-word**: 8 bytes (64 bits).
- **Nibble**: 4 bits (half a byte).

---

## Big and Little Endian

These define byte order for multi-byte data storage:

- **Big Endian**: MSB stored at the lowest address.
- **Little Endian**: LSB stored at the lowest address.

**Example from lecture**:  
An assembly instruction  
```asm
LDR r1, [r0]

loads a 32-bit value from memory address 0x20008000 to register r1.
The value in r1 depends on whether the system is Big Endian or Little Endian.

Let me know if you'd like this also exported to PDF, or transformed into a table-rich version for easier side-by-side comparison.

