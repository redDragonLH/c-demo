//  标准输入复制到标准输出
#include "./include/apue.h"

int main(void){
	int c;

	// getc 一次读取一个字符,然后函数putc将此字符写到标准输出	
	while((c = getc(stdin)) != EOF){
		if(putc(c,stdout) == EOF){
			err_sys("output error");
		}
	}

	if(ferror(stdin)){
		err_sys("input error");
	}

	return 0;
}
