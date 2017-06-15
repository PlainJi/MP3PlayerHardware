#include "timer.h"
#include "uart.h"
#include "touch.h"

data u8  cnt=0;
data u16 second=0;			//开机时间？

#ifdef XTAL22_1184
void InitTimer0(void)	//10'000us
{
	TMOD = 0x01;
	TH0 = 0x0B8;
	TL0 = 0x00;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}
#endif

#ifdef XTAL33_1776
void InitTimer0(void)	//10'000us
{
    TMOD = 0x01;
    TH0 = 0x94;
    TL0 = 0x00;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
#endif

void Timer0Interrupt(void) interrupt 1
{
#ifdef XTAL22_1184
    TH0 = 0x0B8;
    TL0 = 0x00;
#endif

#ifdef XTAL33_1776
    TH0 = 0x94;
    TL0 = 0x00;
#endif
	cnt++;
	if(cnt==100)		//到达1s
	{
		cnt=0;
		second++;
	}
}












