#include "./include/apue.h"

int main(int argc, char *argv[]){
	int i;
	// argv[argc] 必须是一个空指针
	for(i = 0; argv[i] != NULL; i++) /* echo all command-line args*/
		printf("argv[%d]: %s\n",i,argv[i]);
	exit(0);
}
