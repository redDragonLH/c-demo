#ifndef _LeftHeap_H

struct TreeNode;
typedef struct TreeNode *PriorityQueue;

// temp
typedef int ElementType;

/* Minimal set of priority queue operations */
/* Node that nodes will be shared among several */
/* leftist heaps after a merge; the user must */
/* make sure to not use the old leftist heaps */

PriorityQueue Initialize( void );
ElementType FindMin( PriorityQueue H );
int IsEmpty( PriorityQueue H );
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2 );


/* 有参数宏定义.没有类型检查  */
/* 定义的Insert 方法,(X,H)是参数,旁边的() 内部是函数体 */
#define Insert(X,H)(H=Insert1((X),H))
/* DeleteMin macro is left as an exercise */

PriorityQueue Insert1( ElementType X,PriorityQueue H );
PriorityQueue DeleteMin1( PriorityQueue H );

#endif
