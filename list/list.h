#ifndef _List_H
// 定义节点 Node
struct Node;
// typedef 为类型定义一个关键字
// 把*PtrToNode 定义为Node的别名,应该是定义了一个指针吧~~
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;
List MakeEmpty( List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete (ElementType X , List L);
Position FindPrevious( ElementType X,List L);
void Insert( ElementType X,List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif /* _list_H */
