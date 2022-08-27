///* USER CODE BEGIN Header */
///**
//  ******************************************************************************
//  * @file           : main.c
//  * @brief          : Main program body
//  ******************************************************************************
//  * @attention
//  *
//  * Copyright (c) 2022 STMicroelectronics.
//  * All rights reserved.
//  *
//  * This software is licensed under terms that can be found in the LICENSE file
//  * in the root directory of this software component.
//  * If no LICENSE file comes with this software, it is provided AS-IS.
//  *
//  ******************************************************************************
//  */
///* USER CODE END Header */
///* Includes ------------------------------------------------------------------*/
//#include "main.h"
//#include "cmsis_os.h"
//
///* Private includes ----------------------------------------------------------*/
///* USER CODE BEGIN Includes */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include "baro.h"
//#include "LCD.h"
///* USER CODE END Includes */
//
///* Private typedef -----------------------------------------------------------*/
////typedef StaticSemaphore_t osStaticSemaphoreDef_t;
///* USER CODE BEGIN PTD */
//
///* USER CODE END PTD */
//
///* Private define ------------------------------------------------------------*/
///* USER CODE BEGIN PD */
////#define MAX_SAMPLES 100
///* USER CODE END PD */
//
///* Private macro -------------------------------------------------------------*/
///* USER CODE BEGIN PM */
////#define countof(_a) (sizeof(_a)/sizeof(_a[0]))
///* USER CODE END PM */
//
///* Private variables ---------------------------------------------------------*/
//ADC_HandleTypeDef hadc1;
//
//I2C_HandleTypeDef hi2c1;
//
//SPI_HandleTypeDef hspi1;
//
//TIM_HandleTypeDef htim9;
//TIM_HandleTypeDef htim10;
//
//UART_HandleTypeDef huart1;
//
///* Definitions for TaskLEDBlink */
///*osThreadId_t TaskLEDBlinkHandle;
//const osThreadAttr_t TaskLEDBlink_attributes = {
//  .name = "TaskLEDBlink",
//  .stack_size = 128 * 4,
//  .priority = (osPriority_t) osPriorityNormal,
//};*/
///* Definitions for TaskButtonRead */
///*osThreadId_t TaskButtonReadHandle;
//const osThreadAttr_t TaskButtonRead_attributes = {
//  .name = "TaskButtonRead",
//  .stack_size = 128 * 4,
//  .priority = (osPriority_t) osPriorityNormal,
//};*/
///* Definitions for muxUART */
///*osMutexId_t muxUARTHandle;
//const osMutexAttr_t muxUART_attributes = {
//  .name = "muxUART"
//};*/
///* Definitions for SemButtonPressed */
///*osSemaphoreId_t SemButtonPressedHandle;
//osStaticSemaphoreDef_t SemButtonPressedControlBlock;
//const osSemaphoreAttr_t SemButtonPressed_attributes = {
//  .name = "SemButtonPressed",
//  .cb_mem = &SemButtonPressedControlBlock,
//  .cb_size = sizeof(SemButtonPressedControlBlock),
//};*/
///* USER CODE BEGIN PV */
///*int switcher = 0;
////char text[100] = {0};
////int32_t pres = 0;
//*/
///* USER CODE END PV */
//
///* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
//static void MX_GPIO_Init(void);
//static void MX_ADC1_Init(void);
//static void MX_TIM9_Init(void);
//static void MX_TIM10_Init(void);
//static void MX_USART1_UART_Init(void);
//static void MX_I2C1_Init(void);
//static void MX_SPI1_Init(void);
////void StartTaskLEDBlink(void *argument);
////void StartTaskButtonRead(void *argument);
//
///* USER CODE BEGIN PFP */
////static int32_t filter(int32_t sample);
///* USER CODE END PFP */
//
///* Private user code ---------------------------------------------------------*/
///* USER CODE BEGIN 0 */
///* USER CODE END 0 */
//
///**
//  * @brief  The application entry point.
//  * @retval int
//  */
//int main(void)
//{
//  /* USER CODE BEGIN 1 */
//	//uint32_t cnt = 0;
//  /* USER CODE END 1 */
//
//  /* MCU Configuration--------------------------------------------------------*/
//
//  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
//  HAL_Init();
//
//  /* USER CODE BEGIN Init */
//
//  /* USER CODE END Init */
//
//  /* Configure the system clock */
//  SystemClock_Config();
//
//  /* USER CODE BEGIN SysInit */
//  //lcd_init();
//  /* USER CODE END SysInit */
//
//  /* Initialize all configured peripherals */
//  MX_GPIO_Init();
//  MX_ADC1_Init();
//  MX_TIM9_Init();
//  MX_TIM10_Init();
//  MX_USART1_UART_Init();
//  MX_I2C1_Init();
//  MX_SPI1_Init();
//  /* USER CODE BEGIN 2 */
//  uint16_t pot;
//  //HAL_TIM_Base_Start_IT(&htim9);
//  lcd_init();
//  lcd_fill(ST7735_BLACK);
//  //uint8_t cnt = 0;
//	//lcd_fill_rect(10, 10, 50, 50, ST7735_CYAN);
//	//lcd_fill_rect(50, 50, 150, 150, ST7735_MAGENTA);
//	//lcd_rect(5, 5, 15, 15, ST77XX_ORANGE);
//	//lcd_rect(200, 200, 15, 15, ST77XX_ORANGE);
//	//lcd_line(13, 19, 37, 93, ST77XX_GREEN);
//	//lcd_line(13, 19, 93, 37, ST77XX_GREEN);
//	//lcd_circle(22, 55, 76, ST77XX_RED);
//	//lcd_fill_circle(33, 66, 19, ST77XX_BLUE);
//	//lcd_print("Hello LCD!");
//	//lcd_set_text_color(ST7735_CYAN);
////	lcd_set_text_bg_color(ST7735_ORANGE);
////	lcd_print("\nNew line!");
//
//  /* USER CODE END 2 */
//
//  /* Init scheduler */
// // osKernelInitialize();
//  /* Create the mutex(es) */
//  /* creation of muxUART */
// // muxUARTHandle = osMutexNew(&muxUART_attributes);
//
//  /* USER CODE BEGIN RTOS_MUTEX */
//  /* add mutexes, ... */
//  /* USER CODE END RTOS_MUTEX */
//
//  /* Create the semaphores(s) */
//  /* creation of SemButtonPressed */
//  //SemButtonPressedHandle = osSemaphoreNew(1, 1, &SemButtonPressed_attributes);
//
//  /* USER CODE BEGIN RTOS_SEMAPHORES */
//  /* add semaphores, ... */
//  /* USER CODE END RTOS_SEMAPHORES */
//
//  /* USER CODE BEGIN RTOS_TIMERS */
//  /* start timers, add new ones, ... */
//  /* USER CODE END RTOS_TIMERS */
//
//  /* USER CODE BEGIN RTOS_QUEUES */
//  /* add queues, ... */
//  /* USER CODE END RTOS_QUEUES */
//
//  /* Create the thread(s) */
//  /* creation of TaskLEDBlink */
////TaskLEDBlinkHandle = osThreadNew(StartTaskLEDBlink, NULL, &TaskLEDBlink_attributes);
//
//  /* creation of TaskButtonRead */
// // TaskButtonReadHandle = osThreadNew(StartTaskButtonRead, NULL, &TaskButtonRead_attributes);
//
//  /* USER CODE BEGIN RTOS_THREADS */
//  /* add threads, ... */
//  /* USER CODE END RTOS_THREADS */
//
//  /* USER CODE BEGIN RTOS_EVENTS */
//  /* add events, ... */
//  /* USER CODE END RTOS_EVENTS */
//
//  /* Start scheduler */
//  osKernelStart();
//
//  /* We should never get here as control is now taken by the scheduler */
//  /* Infinite loop */
//  /* USER CODE BEGIN WHILE */
//  int count = 20;
//  int pot_prev = 0;
//
//  while (1)
//  {
//
//	 // lcd_fill(ST7735_MAGENTA);
//      HAL_ADC_Start(&hadc1);
//      HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
//      pot = HAL_ADC_GetValue(&hadc1);
//	//  pot_prev = pot;
//	 // lcd_fill_circle(pot, 60, 20, ST77XX_RED);
//	//  lcd_fill_circle(pot_prev, 60, 20, ST77XX_MAGENTA);
//	  //lcd_fill_circle(count, 60, 20, ST77XX_RED);
//	  //pot_prev = pot;
//      pot = pot / 40;
//	  if(pot <= 20)
//	  {
//		  lcd_fill_circle(20, 60, 20, ST77XX_MAGENTA);
//	  }
//	  else
//	  {
//		  lcd_fill_circle(pot, 60, 20, ST77XX_MAGENTA);
//	  }
//
//	  lcd_fill(ST7735_BLACK);
//	  //lcd_fill_circle(pot_prev, 60, 20, ST77XX_MAGENTA);
//
//	  /*
//	for(pot = 0; pot < 100; pot++)
//	{
//		 count+=10;
//	}
//	if(pot )
//	for(pot = 0; pot < 3000; pot++)
//		{
//			 count+=10;
//		}
//	*/
//
//	 // int32_t temp = baro_read_temp();
//	//  int32_t pres = baro_read_press();
//	  //snprintf(text, countof(text), "/*%ld.%02ld*/\n", pres/100, pres%100);
//	  //HAL_UART_Transmit(&huart1, (uint8_t*)text, strlen(text), 1000);
//
//	 // int32_t signal = sin((3.14 * cnt) / 1000.0) * 50 + 50;
//	    //int32_t signal_noised = signal + (rand() % 20) - 10;
//	    //int32_t signal_filtered = filter(signal_noised);
//
//	   // sprintf(text, "/*%ld,%ld,%ld*\n", signal, signal_noised, signal_filtered);
//	  /* cnt++;
//	    HAL_UART_Transmit(&huart1, (uint8_t*)text, strlen(text), 1000);
//	  sprintf(text,"Hello world %d\n", 616);
//	  //HAL_UART_Transmit(&huart1, (uint8_t *)text, strlen(text), HAL_MAX_DELAY);
//	  uint8_t buff[4] = {0};
//	  buff[0] = 0xD0;
//	  if(HAL_I2C_Master_Transmit(&hi2c1, (0x76 << 1), buff, 1, HAL_MAX_DELAY) != HAL_OK)
//	  {
//		  sprintf(text,"I2C Transmit error \n");
//		  HAL_UART_Transmit(&huart1, (uint8_t *)text, strlen(text), HAL_MAX_DELAY);
//	  }
//	  buff[0] = 0;
//	  if(HAL_I2C_Master_Receive(&hi2c1, (0x76 << 1), buff, 1, HAL_MAX_DELAY) != HAL_OK)
//	  {
//		  sprintf(text,"I2C Transmit error \n");
//		  HAL_UART_Transmit(&huart1, (uint8_t *)text, strlen(text), HAL_MAX_DELAY);
//	  }
//	  sprintf(text,"0x%02X\n", buff[0]);
//	  HAL_UART_Transmit(&huart1, (uint8_t *)text, strlen(text), HAL_MAX_DELAY);
//
//	  HAL_Delay(1000);
//      //HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//      //HAL_Delay(1000);
//      //HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
//      //HAL_Delay(1000);
//
//
//	   if(HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin) == GPIO_PIN_SET)
//
//
//	      {
//	        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//	      }
//	      else
//	      {
//	        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
//	      }
//	      HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//	      HAL_Delay(1000);
//	      HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
//	      HAL_Delay(1000);
//
//
//	      HAL_ADC_Start(&hadc1);
//	      HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
//	      pot = HAL_ADC_GetValue(&hadc1);
//
//
//	      if (pot >= 2100)
//	      {
//	        if(HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin) == GPIO_PIN_SET)
//	        {
//	          HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
//	        }
//	        else
//	        {
//	          HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//	        }
//	      }
//	      else if(pot <= 2100)
//	      {
//	        if(HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin) == GPIO_PIN_SET)
//	        {
//	          HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//	        }
//	        else
//	        {
//	          HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
//	        }
//	      }
//	          switch(switcher)
//	      {
//	      case false:
//	        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
//	      case true:
//	        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//	        HAL_Delay(1000);
//	        switcher = false;
//	      }
//
//
//	  HAL_ADC_Start(&hadc1);
//	  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
//	  pot = HAL_ADC_GetValue(&hadc1);
//
//
//
//      if (pot >= 2100)
//      {
//          if(switcher == 1)
//    	  {
//         	  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,GPIO_PIN_RESET);
//    	 	  HAL_Delay(10000);
//    		  switcher = 0;
//    	  }
//      }
//      else if(pot <= 2100)
//      {
//          if(switcher == 1)
//    	  {
//         	  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,GPIO_PIN_RESET);
//    	 	  HAL_Delay(5000);
//    		  switcher = 0;
//    	  }
//      }
//
//
//	  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,GPIO_PIN_RESET);
//	  HAL_Delay(300);
//	  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,GPIO_PIN_SET);
//      HAL_Delay(300);
//
//      HAL_GPIO_WritePin(RED_CAR_GPIO_Port, RED_CAR_Pin, GPIO_PIN_SET);
//      HAL_Delay(1000);
//      HAL_GPIO_WritePin(YELLOW_CAR_GPIO_Port, YELLOW_CAR_Pin, GPIO_PIN_SET);
//      HAL_Delay(1000);
//      HAL_GPIO_WritePin(GREEN_CAR_GPIO_Port, GREEN_CAR_Pin, GPIO_PIN_SET);
//      HAL_Delay(1000);
//      HAL_GPIO_WritePin(RED_MEN_GPIO_Port, RED_MEN_Pin, GPIO_PIN_SET);
//      HAL_Delay(1000);
//      HAL_GPIO_WritePin(YELLOW_MEN_GPIO_Port, YELLOW_MEN_Pin, GPIO_PIN_SET);
//      HAL_Delay(1000);
//      HAL_GPIO_WritePin(GREEN_MEN_GPIO_Port, GREEN_MEN_Pin, GPIO_PIN_SET);
//      HAL_Delay(1000);
//      */
//    /* USER CODE END WHILE */
//
//    /* USER CODE BEGIN 3 */
//  }
//  /* USER CODE END 3 */
//}
//
///**
//  * @brief System Clock Configuration
//  * @retval None
//  */
//void SystemClock_Config(void)
//{
//  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//
//  /** Configure the main internal regulator output voltage
//  */
//  __HAL_RCC_PWR_CLK_ENABLE();
//  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
//
//  /** Initializes the RCC Oscillators according to the specified parameters
//  * in the RCC_OscInitTypeDef structure.
//  */
//  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
//  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
//  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//  RCC_OscInitStruct.PLL.PLLM = 25;
//  RCC_OscInitStruct.PLL.PLLN = 168;
//  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
//  RCC_OscInitStruct.PLL.PLLQ = 4;
//  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//  {
//    Error_Handler();
//  }
//
//  /** Initializes the CPU, AHB and APB buses clocks
//  */
//  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
//  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
//
//  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
//  {
//    Error_Handler();
//  }
//}
//
///**
//  * @brief ADC1 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_ADC1_Init(void)
//{
//
//  /* USER CODE BEGIN ADC1_Init 0 */
//
//  /* USER CODE END ADC1_Init 0 */
//
//  ADC_ChannelConfTypeDef sConfig = {0};
//
//  /* USER CODE BEGIN ADC1_Init 1 */
//
//  /* USER CODE END ADC1_Init 1 */
//
//  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
//  */
//  hadc1.Instance = ADC1;
//  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
//  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
//  hadc1.Init.ScanConvMode = DISABLE;
//  hadc1.Init.ContinuousConvMode = ENABLE;
//  hadc1.Init.DiscontinuousConvMode = DISABLE;
//  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
//  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
//  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
//  hadc1.Init.NbrOfConversion = 1;
//  hadc1.Init.DMAContinuousRequests = DISABLE;
//  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
//  if (HAL_ADC_Init(&hadc1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//
//  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
//  */
//  sConfig.Channel = ADC_CHANNEL_0;
//  sConfig.Rank = 1;
//  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
//  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN ADC1_Init 2 */
//
//  /* USER CODE END ADC1_Init 2 */
//
//}
//
///**
//  * @brief I2C1 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_I2C1_Init(void)
//{
//
//  /* USER CODE BEGIN I2C1_Init 0 */
//
//  /* USER CODE END I2C1_Init 0 */
//
//  /* USER CODE BEGIN I2C1_Init 1 */
//
//  /* USER CODE END I2C1_Init 1 */
//  hi2c1.Instance = I2C1;
//  hi2c1.Init.ClockSpeed = 100000;
//  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
//  hi2c1.Init.OwnAddress1 = 0;
//  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
//  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
//  hi2c1.Init.OwnAddress2 = 0;
//  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
//  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
//  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN I2C1_Init 2 */
//
//  /* USER CODE END I2C1_Init 2 */
//
//}
//
///**
//  * @brief SPI1 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_SPI1_Init(void)
//{
//
//  /* USER CODE BEGIN SPI1_Init 0 */
//
//  /* USER CODE END SPI1_Init 0 */
//
//  /* USER CODE BEGIN SPI1_Init 1 */
//
//  /* USER CODE END SPI1_Init 1 */
//  /* SPI1 parameter configuration*/
//  hspi1.Instance = SPI1;
//  hspi1.Init.Mode = SPI_MODE_MASTER;
//  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
//  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
//  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
//  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
//  hspi1.Init.NSS = SPI_NSS_SOFT;
//  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
//  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
//  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
//  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
//  hspi1.Init.CRCPolynomial = 10;
//  if (HAL_SPI_Init(&hspi1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN SPI1_Init 2 */
//
//  /* USER CODE END SPI1_Init 2 */
//
//}
//
///**
//  * @brief TIM9 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_TIM9_Init(void)
//{
//
//  /* USER CODE BEGIN TIM9_Init 0 */
//
//  /* USER CODE END TIM9_Init 0 */
//
//  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
//
//  /* USER CODE BEGIN TIM9_Init 1 */
//
//  /* USER CODE END TIM9_Init 1 */
//  htim9.Instance = TIM9;
//  htim9.Init.Prescaler = 839;
//  htim9.Init.CounterMode = TIM_COUNTERMODE_UP;
//  htim9.Init.Period = 49999;
//  htim9.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
//  htim9.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
//  if (HAL_TIM_Base_Init(&htim9) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
//  if (HAL_TIM_ConfigClockSource(&htim9, &sClockSourceConfig) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN TIM9_Init 2 */
//
//  /* USER CODE END TIM9_Init 2 */
//
//}
//
///**
//  * @brief TIM10 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_TIM10_Init(void)
//{
//
//  /* USER CODE BEGIN TIM10_Init 0 */
//
//  /* USER CODE END TIM10_Init 0 */
//
//  /* USER CODE BEGIN TIM10_Init 1 */
//
//  /* USER CODE END TIM10_Init 1 */
//  htim10.Instance = TIM10;
//  htim10.Init.Prescaler = 84;
//  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
//  htim10.Init.Period = 999;
//  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
//  htim10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
//  if (HAL_TIM_Base_Init(&htim10) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN TIM10_Init 2 */
//
//  /* USER CODE END TIM10_Init 2 */
//
//}
//
///**
//  * @brief USART1 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_USART1_UART_Init(void)
//{
//
//  /* USER CODE BEGIN USART1_Init 0 */
//
//  /* USER CODE END USART1_Init 0 */
//
//  /* USER CODE BEGIN USART1_Init 1 */
//
//  /* USER CODE END USART1_Init 1 */
//  huart1.Instance = USART1;
//  huart1.Init.BaudRate = 115200;
//  huart1.Init.WordLength = UART_WORDLENGTH_8B;
//  huart1.Init.StopBits = UART_STOPBITS_1;
//  huart1.Init.Parity = UART_PARITY_NONE;
//  huart1.Init.Mode = UART_MODE_TX_RX;
//  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
//  if (HAL_UART_Init(&huart1) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN USART1_Init 2 */
//
//  /* USER CODE END USART1_Init 2 */
//
//}
//
///**
//  * @brief GPIO Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_GPIO_Init(void)
//{
//  GPIO_InitTypeDef GPIO_InitStruct = {0};
//
//  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOC_CLK_ENABLE();
//  __HAL_RCC_GPIOH_CLK_ENABLE();
//  __HAL_RCC_GPIOA_CLK_ENABLE();
//  __HAL_RCC_GPIOB_CLK_ENABLE();
//
//  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
//
//  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(GPIOA, LCD_RESET_Pin|LCD_CS_Pin|LCD_A0_Pin, GPIO_PIN_SET);
//
//  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(GPIOB, GREEN_CAR_Pin|YELLOW_CAR_Pin|RED_CAR_Pin, GPIO_PIN_RESET);
//
//  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(GPIOA, GREEN_MEN_Pin|YELLOW_MEN_Pin|RED_MEN_Pin, GPIO_PIN_RESET);
//
//  /*Configure GPIO pin : LED_Pin */
//  GPIO_InitStruct.Pin = LED_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);
//
//  /*Configure GPIO pins : LCD_RESET_Pin LCD_CS_Pin LCD_A0_Pin GREEN_MEN_Pin
//                           YELLOW_MEN_Pin RED_MEN_Pin */
//  GPIO_InitStruct.Pin = LCD_RESET_Pin|LCD_CS_Pin|LCD_A0_Pin|GREEN_MEN_Pin
//                          |YELLOW_MEN_Pin|RED_MEN_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
//  /*Configure GPIO pins : BUTTON2_Pin BUTTON_Pin */
//  GPIO_InitStruct.Pin = BUTTON2_Pin|BUTTON_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//  /*Configure GPIO pins : GREEN_CAR_Pin YELLOW_CAR_Pin RED_CAR_Pin */
//  GPIO_InitStruct.Pin = GREEN_CAR_Pin|YELLOW_CAR_Pin|RED_CAR_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//  /* EXTI interrupt init*/
//  HAL_NVIC_SetPriority(EXTI2_IRQn, 5, 0);
//  HAL_NVIC_EnableIRQ(EXTI2_IRQn);
//
//  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
//  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
//
//}
//
///* USER CODE BEGIN 4 */
///*void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	osSemaphoreRelease(SemButtonPressedHandle);
//}
//static int32_t filter(int32_t sample)
//{
//	  static int32_t arr[MAX_SAMPLES] = {0};
//	  static uint32_t runner = 0;
//	  static uint32_t filled = 0;
//
//	  arr[runner] = sample;
//
//	  if (filled < MAX_SAMPLES)
//	    ++filled;
//	  else {
//	    if (++runner == MAX_SAMPLES)
//	      runner = 0;
//	  }
//
//	  int64_t avg = 0;
//	  for (uint32_t i = 0; i < filled; i++) {
//	    avg += arr[i];
//	  }
//	  avg /= filled;
//
//	  return (int32_t)avg;
//}
//void  HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//	if (htim == &htim9)
//	{
//		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
//	}
//}
//
//	// HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,GPIO_PIN_SET);
//	//switcher = 1;
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//  if (GPIO_Pin == BUTTON_Pin)
//  {
//    if (HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin) == GPIO_PIN_SET)
//    {
//      __HAL_TIM_SET_COUNTER(&htim10, 0);
//      HAL_TIM_Base_Start(&htim10);
//    }
//    else
//    {
//      HAL_TIM_Base_Stop(&htim10);
//      uint32_t cnt = __HAL_TIM_GET_COUNTER(&htim10);
//      if (cnt < 500)
//      {
//        __HAL_TIM_SET_AUTORELOAD(&htim9, 49999);
//        __HAL_TIM_SET_COUNTER(&htim9, 49999);
//      }
//      else
//      {
//        __HAL_TIM_SET_AUTORELOAD(&htim9, 9999);
//        __HAL_TIM_SET_COUNTER(&htim9, 9999);
//      }
//    }
//  }
//}
//*/
//
///* USER CODE END 4 */
//
///* USER CODE BEGIN Header_StartTaskLEDBlink */
///**
//  * @brief  Function implementing the TaskLEDBlink thread.
//  * @param  argument: Not used
//  * @retval None
//  */
///* USER CODE END Header_StartTaskLEDBlink */
////void StartTaskLEDBlink(void *argument)
////{
//  /* USER CODE BEGIN 5 */
//  /* Infinite loop */
// /* for(;;)
//  {
//	  if (baro_init() != BARO_OK)
//	  {
//	    snprintf(text, countof(text), "Error init baro\n");
//	    HAL_UART_Transmit(&huart1, (uint8_t*)text, strnlen(text, countof(text)), 1000);
//	    while (1) {}
//	  }
//	  else
//	  {
//	    pres = baro_read_press();
//	    snprintf(text, countof(text), "/*%ld.%02ld*\n", pres/100, pres%100);
//	  }
//	 // HAL_UART_Transmit(&huart1, (uint8_t*)text, strlen(text), 1000);
//    //char *text = "This is some long text for sending over UART from TASK 1!\n";
//    //HAL_UART_Transmit(&huart1, (uint8_t*)text, strlen(text), 1000);
//    osDelay(pdMS_TO_TICKS(1000));
//  }*/
//  /* USER CODE END 5 */
////}
//
///* USER CODE BEGIN Header_StartTaskButtonRead */
///**
//* @brief Function implementing the TaskButtonRead thread.
//* @param argument: Not used
//* @retval None
//*/
///* USER CODE END Header_StartTaskButtonRead */
////void StartTaskButtonRead(void *argument)
////{
//  /* USER CODE BEGIN StartTaskButtonRead */
//  /* Infinite loop */
//  /*for(;;)
//  {
//	  osSemaphoreAcquire(SemButtonPressedHandle, osWaitForever);
//	  HAL_UART_Transmit(&huart1, (uint8_t*)text, strlen(text), 1000);
//    //char *text = "This is some long text for sending over UART from TASK 2!\n";
//   // osMutexAcquire(muxUARTHandle, osWaitForever);
//    //HAL_UART_Transmit(&huart1, (uint8_t*)text, strlen(text), 1000);
//    //osMutexRelease(muxUARTHandle);
//    //osDelay(pdMS_TO_TICKS(1000));
//  }*/
//  /* USER CODE END StartTaskButtonRead */
////}
//
///**
//  * @brief  This function is executed in case of error occurrence.
//  * @retval None
//  */
//void Error_Handler(void)
//{
//  /* USER CODE BEGIN Error_Handler_Debug */
//  /* User can add his own implementation to report the HAL error return state */
//  __disable_irq();
//  while (1)
//  {
//  }
//  /* USER CODE END Error_Handler_Debug */
//}
//
//#ifdef  USE_FULL_ASSERT
///**
//  * @brief  Reports the name of the source file and the source line number
//  *         where the assert_param error has occurred.
//  * @param  file: pointer to the source file name
//  * @param  line: assert_param error line source number
//  * @retval None
//  */
//void assert_failed(uint8_t *file, uint32_t line)
//{
//  /* USER CODE BEGIN 6 */
//  /* User can add his own implementation to report the file name and line number,
//     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//  /* USER CODE END 6 */
//}
//#endif /* USE_FULL_ASSERT */
