// 归并排序
/* Lops = start of left half, Rpos = start of right half */
void Merge(ElementType A[],ElementType TmpArray[],int Lops, int Rpos, int RightEnd){
	int i, LeftEnd, NumElements, TmpPos;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	/* main loop */
	while(Lpos <= LeftEnd && Rpos <= RightEnd) {
		if( A[Lpos] <= A[Rpos]){
			TmpArray[TmpPos++] = A[Lpos++];
		}else {
			TmpArray[TmpPos++] = A[Rpos++];
		}
	}

	// copy rest of first half
	while( Lpos <= LeftEnd){
		TmpArray[TmpPos++] = A[Lpos++];
	}
	// copy rest of second half
	while(Rpos <= RightEnd){
		TmpArray[TmpPos++] = A[Rpos++];
	}

	// copy TmpArray back
	for(i = 0; i < NumElements; i++, RightEnd--){
		A[RightEnd] = TmpArray[RightEnd];
	}
}

void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right){
	int Center;

	if(Left < Right){
		Center = (Left + Right ) / 2;
		MSort(A, TmpArray, Left,Center);
		MSort(A, TmpArray,center + 1, Right);
		// merge 放在最后保证任意时刻只需要一个临时数组活动.而且可以使用该临时数组的任意部分
		Merge(A, TmpArray,Left,Center+1,Right);
	}
}

void MergeSort( ElementType A[], int N){
	ElementType *TmpArray;

	TmpArray = malloc(N * sizeof(ElementType) );
	if(TmpArray != NULL){
		MSort(A, TmpArray,0, N-1);
		free(TmpArray);
	}else {
		FatalError("No space for tmp array")
	}
}

