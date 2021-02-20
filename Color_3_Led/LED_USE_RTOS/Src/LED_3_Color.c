#include "User_Header.h"


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
