
# Custom `_sbrk` Implementation in Embedded Systems

```c

typedef volatile unsigned int vuint32_t;

#include <stdint.h>
#include <stdlib.h>

#define heap_width 500 // 500 B

void *_sbrk(int incr)
{
    static uint8_t *heap_ptr = NULL;
    uint8_t *prev_heap_ptr;

    if (heap_ptr == NULL)
        heap_ptr = (unsigned char*)&_E_bss;

    prev_heap_ptr = heap_ptr;

    /* Protect heap from growing into the reserved stack */
    if ((heap_ptr + incr) > ((unsigned char*)&_E_bss + heap_width))
        return (void *)NULL;

    heap_ptr += incr;
    return (void *)prev_heap_ptr;
}
```

Description

This is a custom implementation of the _sbrk function, used in embedded systems to support dynamic memory allocation (e.g., for malloc). It works by maintaining a simple heap region starting from the end of the .bss section.
---


The function checks if the requested memory will exceed the heap boundary. If so, it returns NULL.

Otherwise, it increments heap_ptr and returns the previous value.


This function is used by the standard library's malloc implementation to allocate memory in bare-metal systems where no OS is present.

---