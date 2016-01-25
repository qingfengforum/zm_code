
int main()
{
	unsigned *WDT=0x53000000;
	*WDT = 0;

	//设置GPB5-8为输出模式
	unsigned * GPBCON = 0x56000010;
	unsigned gpbcon_info = 0x15400;
	*GPBCON = gpbcon_info;

	unsigned * GPBDAT = 0x56000014;
	int i;

	while (1) {
		//关闭led1-4，就是把GPB5-8的管脚抬高
		*GPBDAT = 0xffffffff;
		//延时 
			for(i=0xffff;i--;);
		//打开led1-4，就是把GPB5-8的管脚拉低
			*GPBDAT = 0x0;
		//延时
			for(i=0xffff;i--;);
		
	}

	return 0;
}
