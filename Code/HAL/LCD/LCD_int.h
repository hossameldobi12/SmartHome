/**
 * @file LCD_int.h
 * @author Hossam Eldobi (hossameldobi12@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_U8_ROW1       0
#define LCD_U8_ROW2       1
                          
#define LCD_U8_COL_1      0
#define LCD_U8_COL_2      1
#define LCD_U8_COL_3      2
#define LCD_U8_COL_4      3
#define LCD_U8_COL_5      4
#define LCD_U8_COL_6      5
#define LCD_U8_COL_7      6
#define LCD_U8_COL_8      7
#define LCD_U8_COL_9      8
#define LCD_U8_COL_10     9
#define LCD_U8_COL_11     10
#define LCD_U8_COL_12     11
#define LCD_U8_COL_13     12
#define LCD_U8_COL_14     13
#define LCD_U8_COL_15     14
#define LCD_U8_COL_16     15

void lcd_init(void);
void lcd_display_data(u8 Copy_u8Data);
void lcd_display_inist(u8 Copy_u8Inst);
void lcd_display_string(s8 *P_s8String);
void lcd_clear(void);
void lcd_setcursor(u8 Copy_u8Row ,u8 Copy_u8Col);


#endif