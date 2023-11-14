#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  矩阵键盘读取按键键码
  * @param  无
  * @retval  KeyNumber按下按键的键码值
	如果按键按下不放，程序会停留在此函数，松手的一瞬间，返回按键键码，没有按键按下时，返回0
  */
  
unsigned char MatrixKey() //有返回值
{
	unsigned char KeyNumber=0;
	P1=0XFF; //1111 1111 1111 1111
	P1_3=0;//把第一列置0，扫描第一列
	if(P1_7==0){Delay(20);while(P1_7==0);KeyNumber=1;} //(1,1)
	if(P1_6==0){Delay(20);while(P1_6==0);KeyNumber=5;} //(2.1)
	if(P1_5==0){Delay(20);while(P1_5==0);KeyNumber=9;} //(3,1)
	if(P1_4==0){Delay(20);while(P1_4==0);KeyNumber=13;} //(4,1)
	
	P1=0XFF; //1111 1111 1111 1111
	P1_2=0;//把第二列置0，扫描第一列
	if(P1_7==0){Delay(20);while(P1_7==0);KeyNumber=2;} //(1,1)
	if(P1_6==0){Delay(20);while(P1_6==0);KeyNumber=6;} //(2.1)
	if(P1_5==0){Delay(20);while(P1_5==0);KeyNumber=10;} //(3,1)
	if(P1_4==0){Delay(20);while(P1_4==0);KeyNumber=14;} //(4,1)
	
	P1=0XFF; //1111 1111 1111 1111
	P1_1=0;//把第三列置0，扫描第一列
	if(P1_7==0){Delay(20);while(P1_7==0);KeyNumber=3;} //(1,1)
	if(P1_6==0){Delay(20);while(P1_6==0);KeyNumber=7;} //(2.1)
	if(P1_5==0){Delay(20);while(P1_5==0);KeyNumber=11;} //(3,1)
	if(P1_4==0){Delay(20);while(P1_4==0);KeyNumber=15;} //(4,1)
	
	P1=0XFF; //1111 1111 1111 1111
	P1_0=0;//把第四列置0，扫描第一列
	if(P1_7==0){Delay(20);while(P1_7==0);KeyNumber=4;} //(1,1)
	if(P1_6==0){Delay(20);while(P1_6==0);KeyNumber=8;} //(2.1)
	if(P1_5==0){Delay(20);while(P1_5==0);KeyNumber=12;} //(3,1)
	if(P1_4==0){Delay(20);while(P1_4==0);KeyNumber=16;} //(4,1)
	
	return KeyNumber;  //返回KeyNumber
}