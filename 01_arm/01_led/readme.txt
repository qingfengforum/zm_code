01_base: 最基本的linux汇编指令实例
led:
	1.汇编跑马灯
		通过汇编指令，配置GPBCON，设置管脚的模式为输出
		通过汇编指令，配置GPBDAT，控制管脚输出电压的高低，从而控制led等的亮/灭

	2.c语言
		通过地址，直接访问通用寄存器，GPBCON/GPBDAT
		定义宏来表示寄存器中的数据：
			#define rGPBCON *(volatile unsigned long*)0x56000000;
		然后直接操作rGPBCON
