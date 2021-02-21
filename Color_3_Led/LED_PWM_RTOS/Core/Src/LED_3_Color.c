#include "User_Header.h"
#include "tim.h"
#include "usart.h"

void RGB_LED_ctl(uint8_t color)
{
	switch(color)
	{
	case RED:
		HAL_GPIO_WritePin(B_LED_GPIO_Port, B_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_LED_GPIO_Port, G_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R_LED_GPIO_Port, R_LED_Pin, GPIO_PIN_RESET);
		break;

	case GREEN:
		HAL_GPIO_WritePin(B_LED_GPIO_Port, B_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G_LED_GPIO_Port, G_LED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(R_LED_GPIO_Port, R_LED_Pin, GPIO_PIN_SET);
		break;

	case BLUE:
		HAL_GPIO_WritePin(B_LED_GPIO_Port, B_LED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(G_LED_GPIO_Port, G_LED_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R_LED_GPIO_Port, R_LED_Pin, GPIO_PIN_SET);
		break;
	}
}

/*--------------------------------------
 *
 * 		NOT Equal Pin
 * 		TIM2 TIM_CHANNEL_1 , TIM_CHANNEL_2, TIM_CHANNEL_3 use
 *
 */

void RGB_LED_PWM_init(void)
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1 | TIM_CHANNEL_2 | TIM_CHANNEL_3);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,30000);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,20000);
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,10000);
}

void RGB_LED_PWM_ctl(uint8_t color)
{
#if 0
	switch(color)
	{
	case RED:

		if(TIM2->CCR1>65530)
			TIM2->CCR1=0;
		else
			TIM2->CCR1=TIM2->CCR1+1000;
		//printf("\r\n PWM1[%x]",__HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_1));
		break;

	case GREEN:
		if(TIM2->CCR2>65530)
			TIM2->CCR2=0;
		else
			TIM2->CCR2=TIM2->CCR2+1000;
		//printf("\r\n PWM2[%x]",__HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_2));
		break;

	case BLUE:
		if(TIM2->CCR3>65530)
			TIM2->CCR3=0;
		else
			TIM2->CCR3=TIM2->CCR3+1000;
		//printf("\r\n PWM3[%x]",__HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_3));
		break;
	}
#else
	switch(color)
	{
	case RED:
		if(HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1)>65530)
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
		else
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,__HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_1)+100);

		//printf("\r\n PWM1[%lx]",__HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_1));
		break;

	case GREEN:
		if(HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_2)>65530)
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
		else
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,__HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_2)+100);
		//printf("\r\n PWM2[%lx]",__HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_2));
		break;

	case BLUE:
		if(HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_3)>65530)
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,0);
		else
			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,__HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_3)+100);
		//printf("\r\n PWM3[%lx]",__HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_3));
		break;
	}
#endif
}
