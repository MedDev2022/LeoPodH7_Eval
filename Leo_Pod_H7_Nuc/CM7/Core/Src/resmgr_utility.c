/* USER CODE BEGIN Header */
/**
 ******************************************************************************
  * File Name          : resmgr_utility.c
  * Description        : This file provides code for the configuration
  *                      of the resmgr_utility instances.
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

/* Includes ------------------------------------------------------------------*/
#include "resmgr_utility.h"

/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/* Global variables ---------------------------------------------------------*/

/* USER CODE BEGIN 1 */
/* USER CODE END 1 */

/* RESMGR_UTILITY init function */
void MX_RESMGR_UTILITY_Init(void)
{
  /* USER CODE BEGIN 2 */
  /* USER CODE END 2 */

  if (ResMgr_Init(MX_RESMGR_UTILITY_SendMsg, MX_RESMGR_UTILITY_Callback) != RESMGR_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */

}

/* Resource Manager send message function */
__weak void MX_RESMGR_UTILITY_SendMsg(uint32_t id, uint32_t msg)
{
      /* USER CODE BEGIN 4 */
    switch (msg)
    {
        case RESMGR_MSG_INIT:
            //User Code
            break;

        case RESMGR_MSG_DEINIT:
            //User Code
            break;

        case RESMGR_MSG_ASSIGN:
            //User Code
            break;

        case RESMGR_MSG_RELEASE:
            //User Code
            break;

        case RESMGR_MSG_PEND:
            //User Code
            break;

        case RESMGR_MSG_REJECT:
            //User Code
            break;

        default:
            break;
    }
      /* USER CODE END 4 */

    return;
}

/* Resource Manager callback function */
__weak void MX_RESMGR_UTILITY_Callback(uint32_t id, uint32_t msg)
{
      /* USER CODE BEGIN 5 */
    switch (msg)
    {
        case RESMGR_MSG_INIT:
            //User Code
            break;

        case RESMGR_MSG_DEINIT:
            //User Code
            break;

        case RESMGR_MSG_ASSIGNED:
            //User Code
            break;

        case RESMGR_MSG_RELEASED:
            //User Code
            break;

        case RESMGR_MSG_PENDED:
            //User Code
            break;

        case RESMGR_MSG_REJECTED:
            //User Code
            break;

        default:
            break;
    }
      /* USER CODE END 5 */

    return;
}

/**
  * @}
  */
