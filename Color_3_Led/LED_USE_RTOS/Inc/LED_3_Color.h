/*
 * LED_3_Color.h
 *
 *  Created on: Feb 21, 2021
 *      Author: kangij
 */

#pragma once
#ifndef INC_LED_3_COLOR_H_
#define INC_LED_3_COLOR_H_

enum
{
	RED=0,
	GREEN=1,
	BLUE=2
};


extern void RGB_LED_ctl(uint8_t color);

#endif /* INC_LED_3_COLOR_H_ */
