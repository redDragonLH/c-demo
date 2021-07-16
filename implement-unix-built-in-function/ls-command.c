#include "./include/apue.h"
#include <dirent.h>

// argc 代表传入参数的个数,argv是一个数组,每个元素都是一个char *
// * 在声明指针时需要加在定义变量的前面,也就是说 char *a 定义的是一个指针,也就是一个地址,地址内保存数据的类型是char
int main (int argc,char *argv[]) {
	// 定义一个DIR结构的指针
	// DIR:一个目录的相关信息保存在这个结构里
	DIR *dp;
	// struct dirent: 包含了其他文件的名字以及指向与这些文件有关的信息的指针
	struct dirent *dirp;
	// 因为第一个参数是这个文件的名,也就是要调用的程序名,所以从第二个判断
	if(argc != 2)
		err_quit("usage: ls directory_name");
	// opendir : 用来打开参数name 指定的目录,并返回DIR*形态的目录流
	if((dp = opendir(argv[1])) == NULL)
		// err_sys 函数会返回具体错误类型,比如: Permission denied or Not a directory
		err_sys("can`t open %s",argv[1]);
	// 返回参数dir 目录流的下个目录的进入点
	// 每次读取返回都是不一样的数据;
	while ((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	return 0;
}
