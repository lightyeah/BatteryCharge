/****************************************Copyright (c)**************************************************                         
**
**                                 http://www.powermcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			GLCD.h
** Descriptions:		TFT操作函数库(模拟IO)
**
**------------------------------------------------------------------------------------------------------
** Created by:			AVRman
** Created date:		2011-1-26
** Version:				1.0
** Descriptions:		The original version
**
**------------------------------------------------------------------------------------------------------
** Modified by:			
** Modified date:	
** Version:
** Descriptions:		
********************************************************************************************************/

#ifndef __GLCD_H 
#define __GLCD_H

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"

/* Private define ------------------------------------------------------------*/

/* 8bit to 16bit LCD Interface

   PINS:
   - EN      = P1.25
   - DIR     = P1.24
   - LE      = P1.23
   - WR      = P0.23
   - CS      = P0.22
   - RD      = P0.21
   - RS      = P0.20
   - DB[0.7] = P2.0...P2.7
   - DB[8.15]= P2.0...P2.7                                                     */

#define PIN_EN		(1 << 25)
#define PIN_DIR		(1 << 24)
#define PIN_LE		(1 << 23)
#define PIN_WR		(1 << 23)
#define PIN_CS      (1 << 22)
#define PIN_RD		(1 << 21)
#define PIN_RS		(1 << 20)

/* Pin EN setting to 0 or 1                                                   */
#define LCD_EN(x)   ((x) ? (LPC_GPIO1->FIOSET = PIN_EN) : (LPC_GPIO1->FIOCLR = PIN_EN));
/* Pin DIR setting to 0 or 1                                                   */
#define LCD_DIR(x)   ((x) ? (LPC_GPIO1->FIOSET = PIN_DIR) : (LPC_GPIO1->FIOCLR = PIN_DIR));
/* Pin LE setting to 0 or 1                                                   */
#define LCD_LE(x)   ((x) ? (LPC_GPIO1->FIOSET = PIN_LE) : (LPC_GPIO1->FIOCLR = PIN_LE));
/* Pin WR setting to 0 or 1                                                   */
#define LCD_WR(x)   ((x) ? (LPC_GPIO0->FIOSET = PIN_WR) : (LPC_GPIO0->FIOCLR = PIN_WR));
/* Pin CS setting to 0 or 1                                                   */
#define LCD_CS(x)   ((x) ? (LPC_GPIO0->FIOSET = PIN_CS) : (LPC_GPIO0->FIOCLR = PIN_CS));
/* Pin RD setting to 0 or 1                                                   */
#define LCD_RD(x)   ((x) ? (LPC_GPIO0->FIOSET = PIN_RD) : (LPC_GPIO0->FIOCLR = PIN_RD));
/* Pin RS setting to 0 or 1                                                   */
#define LCD_RS(x)   ((x) ? (LPC_GPIO0->FIOSET = PIN_RS) : (LPC_GPIO0->FIOCLR = PIN_RS));

/* LCD color */
#define White          0xFFFF
#define Black          0x0000
#define Grey           0xF7DE
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

#define HZ_LIB         0
#define ASCII_LIB      1

/******************************************************************************
* Function Name  : RGB565CONVERT
* Description    : 24位转换16位
* Input          : - red: R
*                  - green: G 
*				   - blue: B
* Output         : None
* Return         : RGB 颜色值
* Attention		 : None
*******************************************************************************/
#define RGB565CONVERT(red, green, blue)\
(uint16_t)( (( red   >> 3 ) << 11 ) | \
(( green >> 2 ) << 5  ) | \
( blue  >> 3 ))

/* Private function prototypes -----------------------------------------------*/
void LCD_Initializtion(void);
void LCD_Clear(uint16_t Color);	
uint16_t LCD_BGR2RGB(uint16_t color);
uint16_t LCD_GetPoint(uint16_t Xpos,uint16_t Ypos);
void LCD_SetPoint(uint16_t Xpos,uint16_t Ypos,uint16_t point);
void LCD_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,uint16_t color);
void LCD_SetWindows(uint16_t xStart,uint16_t yStart,uint16_t xLong,uint16_t yLong);
void LCD_DrawPicture(uint16_t StartX,uint16_t StartY,uint16_t EndX,uint16_t EndY,uint16_t *pic);
void GUI_Text(uint16_t Xpos, uint16_t Ypos, uint8_t *str,uint16_t Color, uint16_t bkColor);
void PutChar(unsigned short Xpos,unsigned short Ypos,unsigned char c,unsigned short charColor,unsigned short bkColor);
void PutChinese(uint16_t Xpos,uint16_t Ypos,uint8_t *str,uint16_t Color,uint16_t bkColor);
void GUI_Chinese(uint16_t Xpos, uint16_t Ypos, uint8_t *str,uint16_t Color, uint16_t bkColor);

#endif 
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/





