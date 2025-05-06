/* Muhamad Elalawy Startup.s*/
.global reset            /* Make 'reset' visible to the linker*/
.global stop

reset:
    ldr sp, =stack_top  /* Set stack pointer*/
    bl main              /* Call main()*/

stop: b stop             /* Infinite loop after main*/
