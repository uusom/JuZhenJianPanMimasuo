#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNumber;
unsigned int Password,count;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNumber=MatrixKey();
		if(KeyNumber)  //if(KeyNum!=0)
		{
			if(KeyNumber<=10)  //如果S1~S10按键按下，输入密码
			{
				if(count<4)   //如果输入次数小于4
				{
					Password*=10;             //密码左移一位
					Password+=KeyNumber%10;  //获取一位密码
					count++;
				}
				
			}
			LCD_ShowNum(2,1,Password,4);  //更新显示
		}
		if(KeyNumber==11)  //如果S11按下，即确认
		{
			if(Password==1234)      //如果密码等于正确密码
			{
				LCD_ShowString(1,14,"OK ");  //显示OK
				Password=0;                 //密码清零
				count=0;                    //计次清零
				LCD_ShowNum(2,1,Password ,4);  //更新显示
			}
			else
			{
				LCD_ShowString(1,14,"ERR");  //否则，显示ERR
				Password=0;
				count=0;
				LCD_ShowNum(2,1,Password,4);  //更新显示
			}
		}
		if(KeyNumber==12)     //如果S12按下，取消
		{
			Password=0;                 //密码清零
			count=0;                    //计次清零
			LCD_ShowNum(2,1,Password,4);  //更新显示
		}
	}
}