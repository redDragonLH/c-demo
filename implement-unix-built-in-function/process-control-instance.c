/*
  使用方法:运行之后在 % 后面输入想要运行的内部方法,回车提交,ctrl +D 退出程序
*/

#include "./include/apue.h"
#include <sys/wait.h>

int main(void){
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");

	// fgets 返回的每一行都以换行符终止
	// 但是execlp 函数要求的参数是以 null 结束的而不是以换行符结束
	while(fgets(buf,MAXLINE,stdin) != NULL){
		if(buf[strlen(buf) - 1] == '\n'){
			// 所以需要用 null 字节替换换行符
			buf[strlen(buf) - 1] = 0;
		}
		
		// fork 创建一个新进程,新进程是调用进程的一个副本,
		// fork 会对父进程返回新子进程的进程ID,对子进程则返回0
		// 因为fork 创建一个新进程,所以说它被调用一次(由父进程),但返回两次(分别在父进程和子进程中)

		// 我还以为会递归的创建下去.那就是用户/软件启动的进程只能创建一层子进程喽?不能创建多层么
		// 代码一样但环境不一样运行结果也不一样
		if((pid = fork()) < 0){
			err_sys("fork error");
		}else if(pid == 0){
			//  从标准输入读入命令.用新的程序文件替换子进程原先执行的程序文件
			// fork 和跟随其后的exec 两者的组合就是某些操作系统所称的产生(spawn)一个新进程
			execlp(buf,buf, (char *)0);
			err_ret("couldn`t execute: %s",buf);
			exit(127);
		}

		// parent
		if((pid = waitpid(pid, &status,0)) < 0){
			err_sys("waitpid error");
		}
		printf("%% ");
	}
	return 0;
}
