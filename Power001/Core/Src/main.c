/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "hrtim.h"
#include "opamp.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "power001_model.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
const uint8_t send_lth=13,rcv_lth=32;
//unsigned char send_buf[send_lth]={0};
uint8_t rcv_buf[1+2+2]={0},
				send_buf[(9+4+3)*2+10] = {
					'v','o','u','t','.','v','a','l','=','0','0','0','0','\xff','\xff','\xff',
					'i','o','u','t','.','v','a','l','=','0','0','0','0','\xff','\xff','\xff',
					'c','.','v','a','l','=','1','\xff','\xff','\xff'};
				
uint16_t t7num=0;
uint16_t vout_val=0, vset_val=0, iout_val=0, iset_val=0;
float vget=0, iget=0, vtemp=0, vtemp2=0, itemp=0, itemp2=0;
float pwmtemp = 9000;
					
int output = 0, output_temp = 0, fix=0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_HRTIM1_Init();
  MX_TIM6_Init();
  MX_OPAMP1_Init();
  /* USER CODE BEGIN 2 */
	output_off();
	
	rtP.kp_v = 0.6;
	rtP.ki_v = 1.5;
	rtP.kd_v = 0;
	
	rtP.kp_i = 1.0;
	rtP.ki_i = 4.0;
	rtP.kd_i = 0;
	
	rtP.period_max = 27200;
	rtP.v_in = 5000;
	rtU.state = 0;
	rtY.v_period_out = 0;
	
	power001_model_initialize();
	
	HAL_HRTIM_WaveformOutputStart(&hhrtim1, HRTIM_OUTPUT_TC1|HRTIM_OUTPUT_TC2); 
	HAL_HRTIM_WaveformCounterStart(&hhrtim1, HRTIM_TIMERID_TIMER_C);
	//hhrtim1.Instance->sTimerxRegs[2].CMP1xR = 15000;//改变占空比 0~27200
	
	HAL_OPAMP_Start(&hopamp1);
	HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
	
	__HAL_UART_DISABLE_IT(&huart2, UART_IT_TC);
	
	HAL_UART_Receive_DMA(&huart2, rcv_buf, 5);

	HAL_TIM_Base_Start_IT(&htim6);
	
	for(int i=0;i<10;i++){
		HAL_UART_Receive_DMA(&huart2, rcv_buf, 5);
		HAL_Delay(100);
	}
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		/*
    vout = vin * D/(1-D)
		D = vout/(vout+vin)
    V 0~12 -> 0~75% PWM
    I 0~2 -> PWM++或--
		*/
		
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV5;
  RCC_OscInitStruct.PLL.PLLN = 68;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim == &htim6){
		
		sampling();
		
		vout_val = vget*2500*6/4096/10;
		iout_val = iget*2500/4096/10;
		
		if(1!=output||0==vset_val){
			output_off();
		}
		
		rtU.v_tgt = 10*vset_val;
		rtU.i_tgt = 10*iset_val;
		rtU.v_val = vget*2500*6/4096;
		rtU.i_val = iget*2500/4096;
		
//		rtU.state = 0;
		
//		if(1==output){
//			hhrtim1.Instance->sTimerxRegs[2].CMP1xR = pwmtemp;
//			output_on();
//		}
		
		if(1==output){
			if(rtU.i_val <= rtU.i_tgt&&fix==0){
				rtU.state = 1;//CV
			}
			else{
				rtU.state = 2;//CC
				fix = 1;
			}
			
			power001_model_step();
			if(rtY.v_period_out<272){
				rtY.v_period_out = 272;
			}
			if(1==rtU.state){
				hhrtim1.Instance->sTimerxRegs[2].CMP1xR = rtY.v_period_out;
			}
			else if(2==rtU.state){
				hhrtim1.Instance->sTimerxRegs[2].CMP1xR = rtY.i_period_out;
			}
			output_on();
		}
	}
}

//屏幕显示部分
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART2){
		set_update();
		out_update();
	}
}

void out_update(void){
	send_buf[12] = 48+vout_val%10;
	send_buf[11] = 48+vout_val/10%10;
	send_buf[10] = 48+vout_val/100%10;
	send_buf[9] = 48+vout_val/1000%10;
	
	send_buf[28] = 48+iout_val%10;
	send_buf[27] = 48+iout_val/10%10;
	send_buf[26] = 48+iout_val/100%10;
	send_buf[25] = 48+iout_val/1000%10;
	
	if(2==rtU.state){
		send_buf[38] = '2';
	}
	else{
		send_buf[38] = '1';
	}
	HAL_UART_Transmit_DMA(&huart2, send_buf, 42);
}

void set_update(void){
	if(1==rcv_buf[0]){
		if(0==rcv_buf[3]&&0==rcv_buf[4]){
			if(1==rcv_buf[1]){
				output = 1;
			}
			else if(0==rcv_buf[1]){
				output = 0;
			}
		}
		for(int i=0;i<5;i++){
				rcv_buf[i]=0;
		}
	}
	else if(2==rcv_buf[0]){
		if(0==rcv_buf[3]&&0==rcv_buf[4]){
			vset_val = rcv_buf[2]*256 + rcv_buf[1];
		}
		for(int i=0;i<5;i++){
				rcv_buf[i]=0;
		}
	}
	else if(3==rcv_buf[0]){
		if(0==rcv_buf[3]&&0==rcv_buf[4]){
			iset_val = rcv_buf[2]*256 + rcv_buf[1];
		}
		for(int i=0;i<5;i++){
				rcv_buf[i]=0;
		}
	}
	else if(4==rcv_buf[0]){
		if(0==rcv_buf[3]&&0==rcv_buf[4]){
			rtP.v_in = (rcv_buf[2]*256 + rcv_buf[1])*10;
			output_temp = 0;
		}
		for(int i=0;i<5;i++){
				rcv_buf[i]=0;
		}
	}
	else if(5==rcv_buf[0]){
		if(0==rcv_buf[3]&&0==rcv_buf[4]){
			if(1==rcv_buf[1]){
				rtU.state = 1;
				fix=0;
			}
			else if(2==rcv_buf[1]){
				rtU.state = 2;
				fix=1;
			}
		}
		for(int i=0;i<5;i++){
				rcv_buf[i]=0;
		}
	}
}

//EG2104控制部分
void output_off(void){
	HAL_GPIO_WritePin(SD1_GPIO_Port,SD1_Pin,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(SD2_GPIO_Port,SD2_Pin,GPIO_PIN_RESET);//关闭EG2104输出
	HAL_GPIO_WritePin(MOSCTRL_GPIO_Port,MOSCTRL_Pin,GPIO_PIN_SET);
	fix=0;
}

void output_on(void){
	HAL_GPIO_WritePin(MOSCTRL_GPIO_Port,MOSCTRL_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SD1_GPIO_Port,SD1_Pin,GPIO_PIN_SET);
  HAL_GPIO_WritePin(SD2_GPIO_Port,SD2_Pin,GPIO_PIN_SET);//打开EG2104输出
}

//采样部分
void sampling(void){
	HAL_ADC_Start(&hadc1);//启动ADC1转换
	HAL_ADC_PollForConversion(&hadc1, 10);//等待转换完成，等待时间10ms
 
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC)){
		vget = HAL_ADC_GetValue(&hadc1);
		//vtemp = vget*2500/4096;
		//vtemp2 = vget*2500*6/4096;
	}
	
	HAL_ADC_Start(&hadc2);//启动ADC2转换
	HAL_ADC_PollForConversion(&hadc2, 10);//等待转换完成，等待时间10ms
 
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc2), HAL_ADC_STATE_REG_EOC)){
		iget = HAL_ADC_GetValue(&hadc2);
		//itemp = iget*2500/4096;
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
