
/*
 * stm32f103c6_GPIO_Driver.h
 *
 *  Created on: Jun 14, 2025
 *      Author: Muhamad Elalawy
 */
#include "stm32f103c6_GPIO_Driver.h"


uint8_t Get_CRLH_Position(uint16_t PinNumber){
	switch(PinNumber){

	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}

/**
 * @brief  Initializes a GPIO pin according to the specified parameters.
 *
 * This function configures a GPIO pin's mode and speed based on the provided
 * configuration structure. It supports both input and output modes, including
 * push-pull, open-drain, analog, floating input, and alternate function modes.
 *
 * @param[in] GPIOx        Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB, etc.).
 * @param[in] Pin_Config   Pointer to a GPIO_Pin_Config_t structure that contains
 *                         the configuration information for the specified pin.
 *
 * @note
 * - For output modes, the pin speed must be specified.
 * - For input pull-up or pull-down configuration, the function sets or clears the ODR bit.
 * - Internally determines the correct configuration register (CRL for pins 0–7, CRH for 8–15).
 *
 * @retval None
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_Pin_Config_t *Pin_Config){
	//CRL -> for pins 0:7
	//CRH -> for pins 8:15
	volatile uint32_t *ConfigRegiter = NULL;
	uint8_t PIN_CONFIG = 0;

	ConfigRegiter = (Pin_Config->GPIO_Pin_Number < GPIO_PIN_8) ? &(GPIOx->CRL) : &(GPIOx->CRH);
	//reset CNF , MODE
	(*ConfigRegiter) &= ~(0xF << Get_CRLH_Position(Pin_Config->GPIO_Pin_Number));

	//if pin is OUTPUT
	if((Pin_Config->GPIO_Mode == GPIO_MODE_OUTPUT_PP) || (Pin_Config->GPIO_Mode == GPIO_MODE_OUTPUT_OD) || (Pin_Config->GPIO_Mode == GPIO_MODE_OUTPUT_AF_PP )|| (Pin_Config->GPIO_Mode == GPIO_MODE_OUTPUT_AF_OD)){

		PIN_CONFIG = ((((Pin_Config->GPIO_Mode - 4) << 2) | (Pin_Config->GPIO_Output_Speed )) &0X0F);
	}


	//if pin is INPUT
	else
	{
		if((Pin_Config->GPIO_Mode == GPIO_MODE_INPUT_FLO) || (Pin_Config->GPIO_Mode == GPIO_MODE_Analog)){

			PIN_CONFIG= ((((Pin_Config->GPIO_Mode) << 2) | 0x0)  &0X0F);
		}
		else if(Pin_Config->GPIO_Mode == GPIO_MODE_AF_INPUT)
		{
			PIN_CONFIG = (((GPIO_MODE_INPUT_FLO << 2) | 0x0)  & 0X0F);

		}
		else //input PU/PD
		{
			PIN_CONFIG = (((GPIO_MODE_INPUT_PU << 2) | 0x0)  &0X0F);

			if(Pin_Config->GPIO_Mode == GPIO_MODE_INPUT_PU)//PU
			{
				GPIOx->ODR |= Pin_Config->GPIO_Pin_Number;
			}
			else//PD
			{
				GPIOx->ODR &=  ~(Pin_Config->GPIO_Pin_Number);
			}
		}
	}
	//write on CRL | CRH
	(*ConfigRegiter) |= ((PIN_CONFIG) << Get_CRLH_Position(Pin_Config->GPIO_Pin_Number));


}


/**
 * @brief  Resets the specified GPIO peripheral to its default state.
 *
 * This function resets all configuration registers of the selected GPIO port
 * using the RCC reset controller. It ensures that the GPIO port is returned
 * to its power-on reset state.
 *
 * @param[in] GPIOx  Pointer to the GPIO peripheral to reset
 *                   (e.g., GPIOA, GPIOB, GPIOC, GPIOD, GPIOE).
 *
 * @note
 * - Uses the RCC APB2 peripheral reset register (RCC_APB2RSTR) to reset the GPIO port.
 * - This approach is preferred over manually clearing registers as it ensures a complete and clean reset.
 *
 * @retval None
 */

void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx){
	/*
	 * In case there is no reset controller we can follow the following way:
	GPIOx->CRL  = 0x44444444;
	GPIOx->CRH  = 0x44444444;
	GPIOx->BRR  = 0x00000000;
	GPIOx->ODR  = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->LCKR = 0x00000000;
	*/

	//**********************************************//

	//But in our mcu there is a reset controller, so we can use it.
	// Reset GPIO peripherals using APB2 peripheral reset register (RCC_APB2RSTR)
	// Set and cleared by software.
	if (GPIOx == GPIOA)
	{
	    RCC->APB2RSTR |= (1 << 2);  // Bit 2 IOPARST: IO port A reset
	    RCC->APB2RSTR &= ~(1 << 2); // Clear reset
	}
	else if (GPIOx == GPIOB)
	{
	    RCC->APB2RSTR |= (1 << 3);  // Bit 3 IOPBRST: IO port B reset
	    RCC->APB2RSTR &= ~(1 << 3); // Clear reset
	}
	else if (GPIOx == GPIOC)
	{
	    RCC->APB2RSTR |= (1 << 4);  // Bit 4 IOPCRST: IO port C reset
	    RCC->APB2RSTR &= ~(1 << 4); // Clear reset
	}
	else if (GPIOx == GPIOD)
	{
	    RCC->APB2RSTR |= (1 << 5);  // Bit 5 IOPDRST: IO port D reset
	    RCC->APB2RSTR &= ~(1 << 5); // Clear reset
	}
	else if (GPIOx == GPIOE)
	{
	    RCC->APB2RSTR |= (1 << 6);  // Bit 6 IOPERST: IO port E reset
	    RCC->APB2RSTR &= ~(1 << 6); // Clear reset
	}


}
/**
 * @brief  Reads the logic level of a specific GPIO input pin.
 *
 * This function checks the input data register (IDR) of the specified GPIO port
 * and returns the current logic level (high or low) of the selected pin.
 *
 * @param[in] GPIOx      Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB, etc.).
 * @param[in] PinNumber  Specifies the GPIO pin to read. This parameter should be
 *                       a value of @ref GPIO_PINS (e.g., GPIO_PIN_0, GPIO_PIN_1, ...).
 *
 * @retval GPIO_PIN_SET     The pin is at high logic level.
 * @retval GPIO_PIN_RESET   The pin is at low logic level.
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint16_t PinNumber){

	uint8_t Bit_Status;

	if(((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET){
		Bit_Status = (uint8_t)GPIO_PIN_SET;
	}
	else
	{
		Bit_Status = (uint8_t)GPIO_PIN_RESET;

	}

	return Bit_Status;

}


/**
 * @brief  Reads the logic levels of all pins on a GPIO port.
 *
 * This function reads the input data register (IDR) of the specified GPIO port
 * and returns the current logic levels of all its pins.
 *
 * @param[in] GPIOx  Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB, etc.).
 *
 * @retval uint16_t  A 16-bit value representing the logic levels of all pins on the port.
 *                   Each bit corresponds to a pin (bit 0 = pin 0, ..., bit 15 = pin 15).
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx){
	uint16_t Port_Value;
	Port_Value = (uint16_t)GPIOx->IDR;
	return Port_Value;

}


/**
 * @brief  Writes a logic level to a specific GPIO output pin.
 *
 * This function sets or resets the specified GPIO pin by writing to the
 * Bit Set/Reset Register (BSRR) or Bit Reset Register (BRR).
 *
 * @param[in] GPIOx      Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB, etc.).
 * @param[in] PinNumber  Specifies the GPIO pin to write. This parameter should be
 *                       a value of @ref GPIO_PINS (e.g., GPIO_PIN_0, GPIO_PIN_1, ...).
 * @param[in] Value      Specifies the logic level to write to the pin.
 *                       - GPIO_PIN_SET:   Sets the pin (logic high)
 *                       - GPIO_PIN_RESET: Resets the pin (logic low)
 *
 * @retval None
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint16_t PinNumber,uint8_t Value){
	if (Value != GPIO_PIN_RESET){
		//GPIOx->ODR |= PinNumber;
		//or
		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else
	{
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}


/**
 * @brief  Writes a 16-bit value to all pins of a GPIO port.
 *
 * This function sets the output data register (ODR) of the specified GPIO port,
 * updating the logic levels of all 16 pins at once.
 *
 * @param[in] GPIOx  Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB, etc.).
 * @param[in] Value  16-bit value to be written to the port. Each bit corresponds to
 *                   a pin (bit 0 = pin 0, ..., bit 15 = pin 15).
 *
 * @retval None
 *
 * @note Use with caution, as it overwrites the state of all pins in the port.
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx,uint16_t Value){

	GPIOx->ODR = Value;


}


/**
 * @brief  Toggles the state of a specific GPIO output pin.
 *
 * This function flips the logic level of the specified pin by performing
 * a bitwise XOR on the output data register (ODR).
 *
 * @param[in] GPIOx      Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB, etc.).
 * @param[in] PinNumber  Specifies the GPIO pin to toggle. This parameter should be
 *                       a value of @ref GPIO_PINS (e.g., GPIO_PIN_0, GPIO_PIN_1, ...).
 *
 * @retval None
 *
 * @note This operation affects only the specified pin. Other pins remain unchanged.
 */

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint16_t PinNumber){


	GPIOx->ODR ^= (PinNumber);

}




/**
 * @brief  Locks the configuration of a specific GPIO pin.
 *
 * This function applies a lock to the configuration of the specified GPIO pin.
 * Once locked, the pin configuration (mode, speed, etc.) cannot be modified
 * until the next MCU reset. This feature is useful for preventing unintended
 * changes to critical GPIO settings.
 *
 * The locking mechanism follows the hardware-required sequence:
 * 1. Write 1 to LCKK bit along with the pin bit.
 * 2. Write 0 to LCKK bit while keeping the pin bit.
 * 3. Write 1 again to LCKK bit and pin bit.
 * 4. Read twice to confirm lock.
 *
 * @param[in] GPIOx      Pointer to the GPIO peripheral (e.g., GPIOA, GPIOB, etc.).
 * @param[in] PinNumber  Specifies the GPIO pin to lock. This parameter should be
 *                       a value of @ref GPIO_PINS (e.g., GPIO_PIN_0, GPIO_PIN_1, ...).
 *
 * @retval GPIO_RETURN_LOCK_OK    Lock was successfully applied.
 * @retval GPIO_RETURN_LOCK_ERROR Lock failed to apply.
 *
 * @note Locking is maintained until the next system reset.
 *       Attempting to change the configuration of a locked pin will be ignored by hardware.
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx,uint16_t PinNumber){

    volatile uint32_t tmp = 1 << 16;  // Set LCKK[16]

    // Set the LCKy
    tmp |= PinNumber;

    // Write sequence to lock the configuration
    // Write 1
    GPIOx->LCKR = tmp;
    // Write 0
    GPIOx->LCKR = PinNumber;
    // Write 1
    GPIOx->LCKR = tmp;

    // Read 0
    tmp = GPIOx->LCKR;
    // Read 1 (this read is optional but confirms that the lock is active)
    if ((uint32_t)(GPIOx->LCKR & (1 << 16)))
    {
        return GPIO_RETURN_LOCK_OK;  // Lock is active
    }


    return GPIO_RETURN_LOCK_ERROR;  // Lock failed
}



