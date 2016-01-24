@ code
.text 
.global _start
_start:
	@ initial stack
	mov sp,#4096 

stop:
	b . @=>b stop . 跳到当前语句
