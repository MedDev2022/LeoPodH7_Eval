/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCU_LED_1_Pin GPIO_PIN_0
#define MCU_LED_1_GPIO_Port GPIOC
#define MCU_LED_2_Pin GPIO_PIN_1
#define MCU_LED_2_GPIO_Port GPIOC
#define MCU_2_LSR_TXD_Pin GPIO_PIN_2
#define MCU_2_LSR_TXD_GPIO_Port GPIOA
#define MCU_2_LSR_RXD_Pin GPIO_PIN_3
#define MCU_2_LSR_RXD_GPIO_Port GPIOA
#define MCU_2_DAYCAM_TXD_Pin GPIO_PIN_10
#define MCU_2_DAYCAM_TXD_GPIO_Port GPIOB
#define MCU_2_DAYCAM_RXD_Pin GPIO_PIN_11
#define MCU_2_DAYCAM_RXD_GPIO_Port GPIOB
#define MCU_2_HOST_TXD_Pin GPIO_PIN_9
#define MCU_2_HOST_TXD_GPIO_Port GPIOA
#define MCU_2_HOST_RXD_Pin GPIO_PIN_10
#define MCU_2_HOST_RXD_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
