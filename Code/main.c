/**
 * @brief  Hossam Eldobi (hossameldobi12@gmail.com)
 * 
 * @return main.c
 */

#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
#include "EEPROM_int.h"
#include "UART_int.h"
#include "ADC_int.h"
#include "main.h"
#include "MENU.h"
#include "RELAY_config.h"
#include "RELAY_int.h"
#include "BUZZER_int.h"
#include "MOTOR_Private.h"
#include "LM35_Private.h"
#include "GIE_int.h"
#include  "EXT0_int.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>


int main (void)
{
	
 
  u8 keypad_pressed = KEYPAD_U8_NULL ;
  u8 block_mode_flag = FALSE;
  u8 Login_Mode = NO_MODE;
  u16 temp = 0;
  u8 recive = 0;

          /***********************************************initalization**************************************************************/
  lcd_init();
  KEYPAD_voidInit();  
  UART_Initialize(Asynchronous,Disable,Bit_1,Bits_8);
  ADC_Initialization();
  Motor_Initialize();
  buzzer_init(Buzzer_1_Port,Buzzer_1_Pin);
  GIE_enable();
  EXT0_init();
  EXT0_enable();
  relay_init(RELAY_1_Port,RELAY_1_Pin);
  DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN6,DIO_U8_OUTPUT);
  DIO_voidSetPinDir(DIO_U8_PORTC,DIO_U8_PIN7,DIO_U8_OUTPUT);
  DIO_voidSetPinDir(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_OUTPUT); 
  /************************************************************************/

  lcd_display_string("welcome to smart");
  lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
  lcd_display_string("home system");
  _delay_ms(1000);
  lcd_clear();
  /***************************************************************************/

  /*Setting Admin and Guest passwords if not set */
	if ( (EEPROM_ui8ReadByteFromAddress(ADMIN_PASS_STATUS_ADDRESS)!=PASS_SET) || (EEPROM_ui8ReadByteFromAddress(GUEST_PASS_STATUS_ADDRESS)!=PASS_SET) )
	{
		lcd_display_string("login for");
	    lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
		lcd_display_string("first time");
		_delay_ms(1000);
		lcd_clear();
		lcd_display_string("set admin pass");
	    lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
		lcd_display_string("Admin pass:");

		/********************************* setting Admin password **********************************************/
		
		u8 pass_counter =0;
		u8 pass[PASS_SIZE]= {NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};
        while(pass_counter < PASS_SIZE)
		{
		keypad_pressed = KEYPAD_U8_NULL ;	
		 while(keypad_pressed == KEYPAD_U8_NULL )
		 {
			keypad_pressed = KEYPAD_u8GetButton();
		 }
		  pass[pass_counter] = keypad_pressed;
		  lcd_display_data(keypad_pressed);
		  _delay_ms(300);
		  lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_12+pass_counter);
		  lcd_display_data(PASSWORD_SYMBOL);
		  _delay_ms(100);
		  pass_counter++;
		}
        EEPROM_vWriteBlockToAddress(EEPROM_ADMIN_ADDRESS,pass,PASS_SIZE);
		EEPROM_vWriteByteToAddress(ADMIN_PASS_STATUS_ADDRESS,PASS_SET);
		lcd_clear();
		lcd_display_string("pass saved");
		_delay_ms(500);
		lcd_clear();

		
		/********************************* setting guest password **********************************************/
		pass_counter =0;
		lcd_display_string("set guest pass");
		lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
		lcd_display_string("guest pass:");
		_delay_ms(1000);
		while(pass_counter < PASS_SIZE)
		{
			keypad_pressed = KEYPAD_U8_NULL;
			while (keypad_pressed == KEYPAD_U8_NULL)
			{
				keypad_pressed = KEYPAD_u8GetButton();
			}
			pass[pass_counter]= keypad_pressed;
			lcd_display_data(keypad_pressed);
		    _delay_ms(300);
		    lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_12+pass_counter);
		    lcd_display_data(PASSWORD_SYMBOL);
		    _delay_ms(100);
		     pass_counter++;
		}
			EEPROM_vWriteBlockToAddress(EEPROM_GUEST_ADDRESS,pass,PASS_SIZE);
		    EEPROM_vWriteByteToAddress(GUEST_PASS_STATUS_ADDRESS,PASS_SET);
			lcd_clear();
			lcd_display_string("pass saved");
			_delay_ms(300);
			lcd_clear();
			EEPROM_vWriteByteToAddress(LOGIN_BLOCKED_ADDRESS,FALSE);
	}
	    else
	   {
         block_mode_flag = EEPROM_ui8ReadByteFromAddress(LOGIN_BLOCKED_ADDRESS);
	   }
	   
	while(1) //The start of the periodic code
	{
		keypad_pressed = KEYPAD_U8_NULL;
        u8 pass_tries_count=0 ;
		while (Login_Mode == NO_MODE)
		{
			if(block_mode_flag == TRUE)
			{
				lcd_clear();
				lcd_display_string("Blocked mode");
				lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
				lcd_display_string("wait 10 second");
				_delay_ms(5000);
				pass_tries_count=0;
				block_mode_flag = FALSE;
				EEPROM_vWriteByteToAddress(LOGIN_BLOCKED_ADDRESS,FALSE);
			}
			lcd_clear();
			lcd_display_string("select mode:");
			lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
			lcd_display_string("0:admin 1:guest");
			while (keypad_pressed == KEYPAD_U8_NULL)
			{
				keypad_pressed =KEYPAD_u8GetButton();
			}
			if (keypad_pressed !=CHECK_ADMIN_MODE && keypad_pressed !=CHECK_GUEST_MODE)
			{
				lcd_clear();
				lcd_display_string("wrong Mode");
				keypad_pressed = KEYPAD_U8_NULL;
				_delay_ms(1000);
				continue;
			}
			u8 pass_counter=0;
			u8 pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};
			u8 stored_pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};
			switch (keypad_pressed)
			{
				/********************************* Admin login **********************************************/
			case CHECK_ADMIN_MODE:
			while (Login_Mode != ADMIN)
			{
				keypad_pressed = KEYPAD_U8_NULL;
				lcd_clear();
				lcd_display_string("Admin mode");
				lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
				lcd_display_string("entre pass:");
				_delay_ms(200);
				pass_counter=0;
				while(pass_counter < PASS_SIZE)
				{
					while(keypad_pressed == KEYPAD_U8_NULL)
					{
						keypad_pressed = KEYPAD_u8GetButton();
					}
					pass[pass_counter]= keypad_pressed;
					lcd_display_data(keypad_pressed);
					_delay_ms(300);
					lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_12+pass_counter);
					lcd_display_data(PASSWORD_SYMBOL);
					pass_counter++;
					keypad_pressed = KEYPAD_U8_NULL;
				}
                 EEPROM_vReadBlockFromAddress(EEPROM_ADMIN_ADDRESS,stored_pass,PASS_SIZE);
				 if ((ui8ComparePass(pass,stored_pass,PASS_SIZE)) == TRUE)
				{
					Login_Mode = ADMIN;
					lcd_clear();
					lcd_display_string("right pass");
					lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
					lcd_display_string("Admin Mode");
					_delay_ms(500);
					lcd_clear();
						UART_SENDSTRING("Admin Mode \r\n");
						UART_SENDSTRING("Enter your choice please \r\n");
						UART_SENDSTRING("0:On kitchen \r\n");
						UART_SENDSTRING("1:off kitchen \r\n");
						UART_SENDSTRING("2:On bathroom \r\n");
						UART_SENDSTRING("3:off bathroom \r\n");
						UART_SENDSTRING("4:Open Oven \r\n");
						UART_SENDSTRING("5:Close Oven \r\n");
						UART_SENDSTRING("6:motor 1 is on \r\n");
						UART_SENDSTRING("7:motor 1 is off \r\n");
						UART_SENDSTRING("8:motor 2 is on \r\n");
						UART_SENDSTRING("9:motor 2 is off \r\n");
					
					pass_tries_count=0;
				}
			    else 
				{
					pass_tries_count++;
					Login_Mode = NO_MODE;
					lcd_clear();
					lcd_display_string("Wrong pass");
					lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
					lcd_display_string("tries left");
					lcd_display_data(TRIES_ALLOWED-pass_tries_count+ASCII_ZERO);
					_delay_ms(1000);
					lcd_clear();

					if(pass_tries_count >= TRIES_ALLOWED)
					{
						EEPROM_vWriteByteToAddress(LOGIN_BLOCKED_ADDRESS,TRUE);
							block_mode_flag = TRUE;
							break;
					}
			    }
	

				}
				
				break;
				/********************************* guest login **********************************************/
	
			case CHECK_GUEST_MODE:
			{
				while (Login_Mode != GUEST)
				{
					keypad_pressed = KEYPAD_U8_NULL;
					lcd_clear();
					lcd_display_string("guest mode");
					lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
					lcd_display_string("entre pass:");
					_delay_ms(200);
					pass_counter=0;
				   while(pass_counter < PASS_SIZE)
				{
					while(keypad_pressed == KEYPAD_U8_NULL)
					{
						keypad_pressed = KEYPAD_u8GetButton();
					}
					pass[pass_counter]= keypad_pressed;
					lcd_display_data(keypad_pressed);
					_delay_ms(300);
					lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_12+pass_counter);
					lcd_display_data(PASSWORD_SYMBOL);
					pass_counter++;
					keypad_pressed = KEYPAD_U8_NULL;
				}
                  EEPROM_vReadBlockFromAddress(EEPROM_GUEST_ADDRESS,stored_pass,PASS_SIZE);
				   if ((ui8ComparePass(pass,stored_pass,PASS_SIZE)) == TRUE)
				{
					Login_Mode = GUEST;
					lcd_clear();
					lcd_display_string("right pass");
					lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
					lcd_display_string("guest Mode");
					_delay_ms(500);
					lcd_clear();
						UART_SENDSTRING(" guest mode \r\n");
						UART_SENDSTRING("0:On bathroom \r\n");
						UART_SENDSTRING("1:off bathroom \r\n");
						UART_SENDSTRING("2:Open Oven \r\n");
						UART_SENDSTRING("3:Close Oven \r\n");
						UART_SENDSTRING("4:motor 1 is on \r\n");
						UART_SENDSTRING("5:motor 1 is off \r\n");	
						UART_SENDSTRING("6: temp \r\n");
						UART_SENDSTRING("7: open air cond \r\n");	
						UART_SENDSTRING("8: close air cond \r\n");
					pass_tries_count=0;
				}
				    else 
				{
					pass_tries_count++;
					Login_Mode = NO_MODE;
					lcd_clear();
					lcd_display_string("Wrong pass");
					lcd_setcursor(LCD_U8_ROW2,LCD_U8_COL_1);
					lcd_display_string("tries left");
					lcd_display_data(TRIES_ALLOWED-pass_tries_count+ASCII_ZERO);
					_delay_ms(1000);
					lcd_clear();

					if(pass_tries_count >= TRIES_ALLOWED)
					{
						EEPROM_vWriteByteToAddress(LOGIN_BLOCKED_ADDRESS,TRUE);
							block_mode_flag = TRUE;
							break;
					}
			    }

				}
				break;
				
			}
		
			}


	
		}
		          /********************************* Admin case **********************************************/

		while (Login_Mode == ADMIN)
		{
			recive = UART_Received();
			if (recive == '0')
			{
				lcd_clear();
				lcd_display_string("kitchen is on");
				DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN6,DIO_U8_HIGH);
			}
			else if (recive == '1')
			{
				lcd_clear();
				lcd_display_string("kitchen is off");
				DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN6,DIO_U8_LOW);
			}
				else if (recive == '2')
			{
				lcd_clear();
				lcd_display_string("bathroom is off");
				DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN7,DIO_U8_HIGH);
			}
				else if (recive == '3')
			{
				lcd_clear();
				lcd_display_string("bathroom is off");
				DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN7,DIO_U8_LOW);
			}
				else if (recive == '4')
			{
				lcd_clear();
				lcd_display_string("Oven is off");
				 DIO_voidSetPinDir(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_HIGH);

			}
				else if (recive == '5')
			{
				lcd_clear();
				lcd_display_string("oven is off");
                DIO_voidSetPinDir(DIO_U8_PORTA,DIO_U8_PIN2,DIO_U8_OUTPUT);
			}
				else if (recive == '6')
			{
				lcd_clear();
				lcd_display_string("motor 1 is on");
				Motor_ON(clockwise,enable1);
				_delay_ms(500);
				lcd_display_string("motor 1 is off");
				Motor_OFF(enable1);
			}
				else if (recive == '7')
			{
				lcd_clear();
				lcd_display_string("motor 1 is off");
				Motor_OFF(enable1);
			}
				else if (recive == '8')
			{
				lcd_clear();
				lcd_display_string("motor 2 is on");
				Motor_ON(clockwise,enable2);
			}
				else if (recive == '9')
			{
				lcd_clear();
				lcd_display_string("motor 2 is off");
				Motor_OFF(enable2);
			}
			else
			{

			}
		}
		   /********************************* guest case **********************************************/
		while (Login_Mode == GUEST)
		{
			recive = UART_Received();

			 if (recive == '0')
			{
				lcd_clear();
				lcd_display_string("bathroom is on");
				DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN7,DIO_U8_HIGH);
			}
				else if (recive == '1')
			{
				lcd_clear();
				lcd_display_string("bathroom is off");
				DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN7,DIO_U8_LOW);
			}
				else if (recive == '2')
			{
				lcd_clear();
				lcd_display_string("Oven is on");
				 relay_on(RELAY_1_Port,RELAY_1_Pin);

			}
				else if (recive == '3')
			{
				lcd_clear();
				lcd_display_string("oven is off");
				 relay_off(RELAY_1_Port,RELAY_1_Pin);
				 
                
			}
				else if (recive == '4')
			{
				lcd_clear();
				lcd_display_string("motor 1 is on");
				Motor_ON(clockwise,enable1);
				
			}
				else if (recive == '5')
			{
				lcd_clear();
				lcd_display_string("motor 1 is off");
				Motor_OFF(enable1);
			}
			else if (recive == '6')
			{
				lcd_clear();
				temp = First_LM35_read();
				lcd_display_string("temperature=");
				lcd_setcursor(LCD_U8_ROW1,LCD_U8_COL_13);
				lcd_display_data(30);
		        lcd_display_data((temp%10)+48);
				lcd_display_data(0xDF);
				lcd_display_data('C');
            }
			else if (recive == '7')
			{
				lcd_clear();
				lcd_display_string("air cond is on");
				DIO_voidSetPinVal(DIO_U8_PORTA, DIO_U8_PIN2,DIO_U8_HIGH);
				
			}
			else if (recive == '8')
			{
				lcd_clear();
				lcd_display_string("air cond is off");
				DIO_voidSetPinVal(DIO_U8_PORTA, DIO_U8_PIN2,DIO_U8_LOW);

				
			}
	         else
	        {

	        }
	  
		}
	
}
}

ISR(INT0_vect)
{
	/*This Interrupt Is used For Emergency */
	static u8 flag = 1;
	buzzer_on(Buzzer_1_Port,Buzzer_1_Pin);
	DIO_voidSetPinDir(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_OUTPUT);
	lcd_display_string("Emergency Alarm");
	if(flag == 1)
	{
       DIO_voidSetPinVal(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_HIGH);
		flag = 0;
	}
	else if(flag == 0)
	{
    DIO_voidSetPinVal(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_LOW);	
		flag = 1;
	} 
	

}
  
  /*
  Hossam Adel Mostafa Elsayed Ebrahim       hossameldobi12@gmail.com
  */
