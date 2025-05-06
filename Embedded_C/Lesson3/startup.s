/* Muhamad Elalawy Startup.s*/

/*SRAM 0x20000000 */

.section .vectors

    .word   0x20001000      /* stack top address */
    .word   _reset           /* Reset */
    .word   _vector_handler  /* NMI */
    .word   _vector_handler  /* Hard Fault */
    .word   _vector_handler  /* MM Fault */
    .word   _vector_handler  /* Bus Fault */
    .word   _vector_handler  /* Usage Fault */
    .word   _vector_handler  /* RESERVED */
    .word   _vector_handler  /* RESERVED */
    .word   _vector_handler  /* RESERVED */
    .word   _vector_handler  /* RESERVED */
    .word   _vector_handler  /* SVCall */
    .word   _vector_handler  /* Debug Reserved */
    .word   _vector_handler  /* RESERVED */
    .word   _vector_handler  /* PendSV */
    .word   _vector_handler  /* SysTick */
    .word   _vector_handler  /* IRQ0 */
    .word   _vector_handler  /* IRQ1 */
    .word   _vector_handler  /* IRQ2 */
    .word   _vector_handler  /* ... */
    /* On to IRQ67 */
	

.section .text

_reset:
	bl main
	b .

.thumb_func

_vector_handler:
	b _reset
	