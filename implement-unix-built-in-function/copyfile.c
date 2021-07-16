#include "./include/apue.h"

#define BUFFSIZE 4096

// ./a.out < file > file_another
// 会把输入重定位到另一个接收端

// ./a.out > file
// 会进入输入模式,程序会把用户输入传入文件呢
int main(void){
	int n;
	char buf[BUFFSIZE];
	
	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
		if(write(STDOUT_FILENO,buf,n) != n){
			err_sys("write error");
		}
	}
	
	if(n < 0) {
		err_sys("read error");
	}
	exit(0);
}
