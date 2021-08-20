#include "./include/apue.h"

int main(void){
	char *ptr;
	size_t size;
	if(chdir("/Users/asw/work/c-language/")<0)
		err_sys("chdir failed");

	//ptr = path_alloc(&size); /* our own function */
	size = 1024;
	ptr = malloc(size);
	if(getcwd(ptr,size) == NULL)
		err_sys("getcwd failed");

	printf("cwd =%s\n",ptr);
	exit(0);
}
