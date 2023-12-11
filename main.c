#define F_CPU 8000000UL

#include "Includes.h"

int main(void)
{
    LCD_voidInit();
	KeyPad_Init();
	u8 keypad_data_out;
	int First_num, Second_num; u8 Oper; 
	u8 result[10];
	char val[10]; int index = 0;
    while (1) 
    {
		keypad_data_out = KeyPad_getkey();
		if(keypad_data_out != '\0') 
		{
			if((keypad_data_out<=9 || keypad_data_out >= 0))
			{
					val[index] = keypad_data_out;
					index++;
					LCD_voidSendData(keypad_data_out);
					_delay_ms(200);
			}
			if(keypad_data_out == '+')
			{
				Oper = '+';
				LCD_voidSendData(keypad_data_out);
				_delay_ms(200);
				sscanf(val,"%d",&First_num);
				index = 0;
			}
			else if(keypad_data_out == '-')
			{
				Oper = '-';
				LCD_voidSendData(keypad_data_out);
				_delay_ms(200);
				sscanf(val,"%d",&First_num);
				index = 0;
			}
			else if(keypad_data_out == '*')
			{
				Oper = '*';
				LCD_voidSendData(keypad_data_out);
				_delay_ms(200);
				sscanf(val,"%d",&First_num);
				index = 0;
			}
			else if(keypad_data_out == '/')
			{
				Oper = '/';
				LCD_voidSendData(keypad_data_out);
				_delay_ms(200);
				sscanf(val,"%d",&First_num);
				index = 0;
			}
			
			if(keypad_data_out == '=')
			{
				LCD_voidSendData(keypad_data_out);
				_delay_ms(200);
				sscanf(val,"%d",&Second_num);
				index = 0;
				
				if(Oper=='+')
					sprintf(result, "%d", (First_num+Second_num));
				else if(Oper == '-')
					sprintf(result, "%d", (First_num-Second_num));
				else if(Oper == '*')
					sprintf(result, "%d", (First_num*Second_num));
				else if(Oper=='/')
					sprintf(result, "%d", (First_num/Second_num));
				
				LCD_voidSendCommand(0xC0);
				lcdPrint(result);
			}
			if(keypad_data_out == 'N') main();
		}
		
    }
}

