#include "./include/apue.h"

int main(void){
	// getpid 返回一个 pid_t 数据类型,标准会保证它能保存在一个长整型中,
	// 所以也需要强制转换类型,一般是长整型可以提高可移植性
	printf("process ID is %ld\n",(long)getpid());
	return 0;
}
