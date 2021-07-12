#include "./binHeap.h"

struct HeapStruct{
	int Capacity;
	int Size;
	ElementType *Elements;
}

PriorityQueue Initialize( int MaxElements ){
	PriorityQueue H;
	if( MaxElements < MinPQSize ){
		Error( "Priority queue size is too small" );
	}
	
	H = malloc(sizeof( struct HeapStruct ) );
	if( H == NULL ){
		FatalError( "Out of space" );
	}

	/* Allocate the array plus one extra for sentinel */
	H->Elements = malloc((MaxElements +1 ) * sizeof( ElementType ));

	if( H->Elements == NULL){
		FatalError("Out of space");
	}

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = minData;

	return H;
}

//percolate up
/* H->Element[0] is a sentinel */
void Insert(ElementType X,PriorityQueue H){
	int i;
	if(IsFull( H )){
		Error("Priority queue is full");
		return;
	}
	
	for( i= ++H->Size;H->Elements[1/2] > X; i/=2){
		H->Elements[i] = H->Elements[ i/ 2 ];
	}
	H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H) {
	init i,Child;
	ElementType MinElement,LastElement;

	if(IsEmpty( H )){
		Error("Priority queue is empty")
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];

	for(i=1;i*2 <=H-Size;i=child){
		/* Find smaller child */
		Child = i * 2;
		// 此判断处理元素为偶数个的问题
		if(Child != H->Size && H->Elements[Child+1] < H->Elements[Child]){
			Child++;
		}
		
		/* Percolate one leve */
		if(LastElement > H->Elements[Child]){
			H->Elements[i] = H->Elements[Child];
		}else {
			break;
		}
	}

	H->Elements[i] = H->Elements[Child];
	return MinElement;
}
