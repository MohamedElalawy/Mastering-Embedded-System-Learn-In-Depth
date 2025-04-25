/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Muhamad Elalawy
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


// Base addresses
#define RCC_BASE     0x40021000
#define GPIOC_BASE   0x40011000

// Offsets
#define RCC_APB2ENR  (*(volatile uint32_t*)(RCC_BASE + 0x18))
#define GPIOC_CRH    (*(volatile uint32_t*)(GPIOC_BASE + 0x04))
#define GPIOC_ODR    (*(volatile uint32_t*)(GPIOC_BASE + 0x0C))

// Bit mask for GPIOC
#define IOPC_EN      (1 << 4)

// Union for ODR register (Output Data Register)
typedef union {
    uint32_t all_bits;
    struct {
        uint32_t pin0  :1;
        uint32_t pin1  :1;
        uint32_t pin2  :1;
        uint32_t pin3  :1;
        uint32_t pin4  :1;
        uint32_t pin5  :1;
        uint32_t pin6  :1;
        uint32_t pin7  :1;
        uint32_t pin8  :1;
        uint32_t pin9  :1;
        uint32_t pin10 :1;
        uint32_t pin11 :1;
        uint32_t pin12 :1;
        uint32_t pin13 :1;
        uint32_t pin14 :1;
        uint32_t pin15 :1;
        uint32_t reserved :16;
    } bits;
} GPIO_ODR_t;

// Map union to actual register
#define GPIOC_ODR_UNION (*(volatile GPIO_ODR_t*)(GPIOC_BASE + 0x0C))

void delay() {
    for (volatile int i = 0; i < 50000; ++i);
}

int main(void) {
    // 1. Enable GPIOC clock
    RCC_APB2ENR |= IOPC_EN;

    // 2. Set PC13 as push-pull output (50 MHz)
    // CRH controls pins 8-15. Each pin uses 4 bits.
    // For PC13: Bits 23:20 = 0011 (0x3)
    GPIOC_CRH &= ~(0xF << 20);     // Clear bits
    GPIOC_CRH |=  (0x3 << 20);     // MODE13 = 0b11 (Output 50 MHz), CNF13 = 0b00 (Push-pull)

    // 3. Toggle PC13
    while (1) {
        GPIOC_ODR_UNION.bits.pin13 = 0; // Clear PC13 (LED ON if active-low)
        delay();
        GPIOC_ODR_UNION.bits.pin13 = 1; // Set PC13 (LED OFF if active-low)
        delay();
    }

    return 0;
}
