
# Lesson5
## Custom `_sbrk` Implementation in Embedded Systems

```c

void* __sbrk(int incr) {
    static unsigned char* heap_ptr = NULL;
    unsigned char* prev_heap_ptr = NULL;
    extern unsigned int _E_bss; // symbol
    extern unsigned int _heap_End; // symbol

    // first time initialized
    if (heap_ptr == NULL) {
        heap_ptr = (unsigned char*)&_E_bss;
    }

    prev_heap_ptr = heap_ptr;

    // protect stack
    if ((heap_ptr + incr) > (&_heap_End)) {
        return (void*)NULL;
    }

    // Booking inc size
    heap_ptr += incr;

    return (void*)prev_heap_ptr;
}
```

Description

This is a custom implementation of the _sbrk function, used in embedded systems to support dynamic memory allocation (e.g., for malloc). It works by maintaining a simple heap region starting from the end of the .bss section.



The function checks if the requested memory will exceed the heap boundary. If so, it returns NULL.

Otherwise, it increments heap_ptr and returns the previous value.


This function is used by the standard library's malloc implementation to allocate memory in bare-metal systems where no OS is present.

# modify the linker script 

```ld

SECTIONS {
    .text : {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_text = .;
    } > flash

    .data : {
        _S_DATA = .;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _E_DATA = .;
    } > sram AT> flash

    .bss : {
        _S_bss = .;
        *(.bss*)
        _E_bss = .;
        . = ALIGN(4);
        . = . + 0x1000;
        _heap_End = .;
        . = ALIGN(4);
        . = . + 0x1000;
        _stack_top = .;
    } > sram
}


```
