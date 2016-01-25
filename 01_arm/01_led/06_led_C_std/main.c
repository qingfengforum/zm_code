#include "include/led.h"

//延时函数：通过执行指令来延时
void delay(int n)
{
	while(n--);
}

int main()
{
	init_led();

	led_off_all();
	
	int i=1;
	while (1) {
		for(i=1; i<5; i++) {
			led_on(i);
			delay(0xfff);
			led_off(i);
			delay(0xfff);
		}	
	}
	return 0;
}
