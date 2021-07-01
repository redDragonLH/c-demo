#include "./list.h"

struct Node {
	// 定义时确定元素类型
	ElementType Element;
	Position Next;
};

// Return true if L is empty
int IsEmpty(List L){
	return L->Next == NULL;
};

/*  Return true if P is the last position in list L.
    Parameter L is unused in this implementation */
int IsLast(Position P,List L) {
	return P->Next == NULL;
};

// Return Position of x in L ;NULL if not found
// 逻辑有问题,如果找不到怎么办
Position Find(ElementType X,List L){
	Position P;
	P = L->Next;
	while(P != NULL && P->Element != X)
		P= P->Next;

	return P;
};

// Delete first occurrence of X from a list
// Assume use of a header node *
void Delete (ElementType X,List L){
	Position P,TmpCell;

	P = findPrevious(X,L);

	if(!IsLast(P,L)){
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	} 
}

// If X is not found,then Next field of returned
// Position is NULL;
// Assumes a header

Position FindPrevious(ElementType X,List L){

	Position P;
	P = L;
	while(P->Next != NULL && P->Next->Element != X){
		P = P->Next;
	}
	return P;

}

// Insert (after legal position P)
// Header implementation assumed
// Parameter L is unused in this implementation

void Inser(ElementType X,List L,Position P){
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL){
		FatalError("Out of space");
	}

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
