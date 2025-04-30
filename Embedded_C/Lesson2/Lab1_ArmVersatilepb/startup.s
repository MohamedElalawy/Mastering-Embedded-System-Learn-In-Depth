/* Muhamad Elalawy Startup.s*/
.global reset            /* Make 'reset' visible to the linker*/

reset:
    ldr sp, =0x00011000  /* Set stack pointer*/
    bl main              /* Call main()*/

stop: b stop             /* Infinite loop after main*/
