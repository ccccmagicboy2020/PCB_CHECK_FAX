/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define KEY1_Pin GPIO_PIN_13
#define KEY1_GPIO_Port GPIOC
#define KEY2_Pin GPIO_PIN_14
#define KEY2_GPIO_Port GPIOC
#define KEY3_Pin GPIO_PIN_15
#define KEY3_GPIO_Port GPIOC
#define MOTOR_FORW_Pin GPIO_PIN_5
#define MOTOR_FORW_GPIO_Port GPIOA
#define MOTOR_BACK_Pin GPIO_PIN_6
#define MOTOR_BACK_GPIO_Port GPIOA
#define PRT_DTR_Pin GPIO_PIN_7
#define PRT_DTR_GPIO_Port GPIOA
#define LIGHT_CHECK_Pin GPIO_PIN_0
#define LIGHT_CHECK_GPIO_Port GPIOB
#define LED_CON_Pin GPIO_PIN_1
#define LED_CON_GPIO_Port GPIOB
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define ROW_A_Pin GPIO_PIN_12
#define ROW_A_GPIO_Port GPIOB
#define ROW_B_Pin GPIO_PIN_13
#define ROW_B_GPIO_Port GPIOB
#define SRCLK_1_Pin GPIO_PIN_14
#define SRCLK_1_GPIO_Port GPIOB
#define EN_D1_Pin GPIO_PIN_15
#define EN_D1_GPIO_Port GPIOB
#define RCLK_1_Pin GPIO_PIN_8
#define RCLK_1_GPIO_Port GPIOA
#define BEEP_CON_Pin GPIO_PIN_11
#define BEEP_CON_GPIO_Port GPIOA
#define COL_A_Pin GPIO_PIN_12
#define COL_A_GPIO_Port GPIOA
#define COL_B_Pin GPIO_PIN_15
#define COL_B_GPIO_Port GPIOA
#define O_OUT_Pin GPIO_PIN_3
#define O_OUT_GPIO_Port GPIOB
#define O_OUT_EXTI_IRQn EXTI3_IRQn
#define EN_D2_Pin GPIO_PIN_4
#define EN_D2_GPIO_Port GPIOB
#define SRCLK_2_Pin GPIO_PIN_5
#define SRCLK_2_GPIO_Port GPIOB
#define RCLK_2_Pin GPIO_PIN_6
#define RCLK_2_GPIO_Port GPIOB
#define RCLK_Pin GPIO_PIN_7
#define RCLK_GPIO_Port GPIOB
#define DATA_Pin GPIO_PIN_8
#define DATA_GPIO_Port GPIOB
#define SRCLK_Pin GPIO_PIN_9
#define SRCLK_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
