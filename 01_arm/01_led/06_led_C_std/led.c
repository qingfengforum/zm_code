//volatile:关键字，防止编译器优化
// 类似于*p的作用
#define rGPBCON *(volatile unsigned long*)0x56000010
#define rGPBDAT *(volatile unsigned long*)0x56000014

#define GPB5_OUT 1<<2*5
#define GPB6_OUT 1<<2*6
#define GPB7_OUT 1<<2*7
#define GPB8_OUT 1<<2*8

//设置GPB对应的led管脚为out模式
//对应位置1 ；用或
void init_led()
{
	rGPBCON |= GPB5_OUT|GPB6_OUT|GPB7_OUT|GPB8_OUT;
}

//light up the led_n
//set 0 by &
void led_on(int num) //num: 1-4
{
	switch (num) {
		case 1: rGPBDAT &= ~(1<<5);
				break;
		case 2: rGPBDAT &= ~(1<<6);
				break;
		case 3: rGPBDAT &= ~(1<<7);
				break;
		case 4: rGPBDAT &= ~(1<<8);
				break;
		default:
				break;
	}
	
}

// turn down the led_n
// set 1 by |
void led_off(int num) // num:1-4
{
	switch (num) {
		case 1: rGPBDAT |= (1<<5);
				break;
		case 2: rGPBDAT |= (1<<6);
				break;
		case 3: rGPBDAT |= (1<<7);
				break;
		case 4: rGPBDAT |= (1<<8);
				break;
	}
}

void led_on_all()
{
	rGPBDAT &= ~(0xf<<5);
}

void led_off_all()
{
	rGPBDAT |= (0xf<<5);
}
