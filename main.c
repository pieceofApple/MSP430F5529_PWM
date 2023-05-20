
/*
 * main.c
 */
#include"msp430f5529.h"
void main(void) {
    WDTCTL=WDTPW+WDTHOLD;  //关闭看门狗
//PWM波功能配置
/**************/
//TA0~TA2,均为普通定时器，各有4个管家
//Timer_A,TA0
    P1DIR |= BIT2 + BIT3+BIT4+BIT5;  //管脚P1.2,3,4,5设置为输出
    P1SEL |= BIT2 + BIT3+BIT4+BIT5;  //管脚P1.2,3,4,5选择复用功能
    TA0CCR0 = 20000;    //设置PWM波周期
    TA0CCTL1 =OUTMOD_7;  //TA0比较捕获器1输出模式设置为reset/set模式;//配置P1.2为OUTMOD_7模式；
    TA0CCR1 = 1000; //设置PWM波的占空比，P1.2
    TA0CCTL2 = OUTMOD_7;//配置P1.3为OUTMOD_7模式；
    TA0CCR2 =2000;  //设置PWM波的占空比，P1.3
    TA0CCTL3 = OUTMOD_7;//配置P1.3为OUTMOD_7模式；
    TA0CCR3 =2000;  //设置PWM波的占空比，P1.4
    TA0CCTL4 = OUTMOD_7;//配置P1.3为OUTMOD_7模式；
    TA0CCR4 =2000;  //设置PWM波的占空比，P1.5
    TA0CTL = TASSEL_2 + MC_1 +TACLR; //设置定时器A的时钟输入源为SMCLK增计数模式,MC1为Up模式，同时清零定时器计数值
//Timer_A,TA1
    P2DIR |= BIT0 + BIT1+BIT3+BIT4;  //管脚P1.0,1,3,4设置为输出
    P2SEL |= BIT0 + BIT1+BIT3+BIT4;  //管脚P1.0,1,3,4选择复用功能
    TA1CCR0 = 20000;    //设置PWM波周期
    TA1CCTL1 =OUTMOD_7;  //TA1比较捕获器1输出模式设置为reset/set模式;//配置P2.0为OUTMOD_7模式；
    TA1CCR1 = 1000; //设置PWM波的占空比，P2.0
    TA1CCTL2 = OUTMOD_7;//配置P2.1为OUTMOD_7模式；
    TA1CCR2 =3000;  //设置PWM波的占空比，P2.1
    TA1CTL = TASSEL_2 + MC_1 +TACLR; //设置定时器A的时钟输入源为SMCLK增计数模式,MC1为Up模式，同时清零定时器计数值
//TA2
    TA2CCR0 = 20000;//PWM波周期
    TA2CCTL1 = OUTMOD_7;//配置P2.4为OUTMOD_7模式；
    TA2CCR1 = 5000;//配置P2.4占空比
    //TA2CCTL2 = OUTMOD_7;//配置P2.5为OUTMOD_7模式；
    //TA2CCR2 =3000;    //设置PWM波的占空比，P2.5
    /*P2.5口暂时有问题*/
    TA2CTL = TASSEL_2 + MC_1 +TACLR;
//Timer_B,TA0
    P3DIR |= BIT5 + BIT6; //管脚P3.5,6设置为输出
    P3SEL |= BIT5 + BIT6; //管脚P3.5,6选择复用功能
    P5DIR |= BIT7;
    P5SEL |= BIT7;
    P7DIR |= BIT4+BIT5+BIT6+BIT7;
    P7SEL |= BIT4+BIT5+BIT6+BIT7;   
    TB0CCR0 = 20000;      //设置PWM波周期
    TB0CCTL5 =OUTMOD_7;   //TB0比较捕获器输出模式设置为reset/set模式;//配置P3.5为OUTMOD_7模式；
    TB0CCR5 = 1000;       //设置PWM波的占空比，P3.5
    TB0CCTL6 = OUTMOD_7;  //配置P3.6为OUTMOD_7模式；
    TB0CCR6 = 2000;       //设置PWM波的占空比，P3.6
    TB0CCTL1 =OUTMOD_7;   //TB0比较捕获器输出模式设置为reset/set模式;//配置P5.7为OUTMOD_7模式；
    TB0CCR1 = 1000;       //设置PWM波的占空比，P5.7
    TB0CCTL2 = OUTMOD_7;  //配置P7.4为OUTMOD_7模式；
    TB0CCR2 = 2000;       //设置PWM波的占空比，P7.4
    TB0CCTL3 =OUTMOD_7;   //TB0比较捕获器输出模式设置为reset/set模式;//配置P7.5为OUTMOD_7模式；
    TB0CCR3 = 1000;       //设置PWM波的占空比，P7.5
    TB0CCTL4 = OUTMOD_7;  //配置P7.6为OUTMOD_7模式；
    TB0CCR4 = 2000;       //设置PWM波的占空比，P7.6
    TB0CTL = TASSEL_2 + MC_1 +TACLR; //设置定时器A的时钟输入源为SMCLK增计数模式,MC1为Up模式，同时清零定时器计数值
//Timer_B,TB0,高级定时器
/**************/
    //_bis_SR_register(LPM0_bits);  //进入低功耗模式
    //_no_operation();
}
