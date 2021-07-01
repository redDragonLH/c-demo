#include <stdio.h>
#include "./list.c"
//typedef int ElementType;`
int  main(){
	struct Node node;
	node.Element = 10010;
	printf("%d",node.Element);
	return 0;
};
