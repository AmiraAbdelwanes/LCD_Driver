#include<util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"

#include"DIO_register.h"
#include"DIO_interface.h"

#include"lcd_conf.h"
#include"lcd_inter.h"


void main()
{
	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN0,DIO_U8_OUTPUT);//RS
	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN1,DIO_U8_OUTPUT);//RW
	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN3,DIO_U8_OUTPUT);//EN
	DIO_enumSetPortDirection(DIO_U8_PORT_A,0xff);                    //SET PORT_A as O/P
	LCD_enuInit();                                                   //Initialization of LCD

	LCD_enuSendCMD(0x01);                                            //Clear entire display and sets DDRAM address to 00H
	lcd_gotox_y(0,1);                                                //Set the Cursor to 1st row and 2nd column position
	LCD_vidWriteString("Choose Option");                             //Function take the data to send it to LCD
	_delay_ms(100);                                                  //Data display time on LCD
	LCD_enuSendCMD(0x01);                                            //Clear the display to write again
	lcd_gotox_y(0,1);
	LCD_vidWriteString("1-Light   2-Fan");
	lcd_gotox_y(1,1);
	LCD_vidWriteString("3-Temp 4-safety");

	while (1)
	{}




}
