// 快速排序

/* Return median of Left,Center, and Right */
/* Order these and hide the pivot */
ElementType Median3 Median3(ElementType A[], int Left, int Right){
	int Center = (Left + Right) / 2;
	if(A[Left] > A[Center]){
		Swap(&S[Left], &A[Center]);
	}
	if(A[Left] > A[Righr]){
		Swap(&A[Left], &A[Right]);
	}
	if(A[Center] > A[Right]){
		Swap( &A[Center],&A[Right]);
	}

	/* Invariant: A[Left] <= A[Center] <= A[Right] */

	Swap( &A[Center],&A[Right - 1]);
	return A[Right-1];
}
#define Cutoff(3)

void Qsort(ElementType A[], int Left, int Right){
	int i,j;
	ElementType Pivot;

	if(Left + Cutoff <= Right){
		Pivot = Median3(A,Left, Right);
		i = Left + 1; j = Right - 2;
		for(;;){
			while(A[i] < Pivot) i++
			while(A[j] > Pivot ) j--
			if(i < j){
				Swap(&A[i], &A[j]);
			}else {
				break;
			}
		}
		Qsort(A, Left, i - 1);
		Qsort(A,i + 1, Right);
	}else {
		InsertionSort(A + Left,Right - Left + 1);
	}
}

void quickSort(ElementType A[], int N){
	Qsort( A, 0, N - 1);
}
