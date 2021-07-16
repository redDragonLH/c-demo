// 左子节点公式 
#define LeftChild(i)(2 * (i) + 1)

// 堆的二叉树构建性能较差,但是代码与逻辑清晰
// 数组模拟二叉树实现占用内存少,性能较好,但是内部代码可读性较差,需要详细分析
void PercDown( ElementType A[],int i,int n){
	int Child;
	ElementType Tmp;
	// 交换位置构建模拟二叉树
	for(Tmp = A[i]; LeftChild(i) < N; i =Child){
		// 获取当前节点的左子节点位置
		Child = LeftChild(i);
		// 子节点没有超过最长限度,且右节点?比左子节点大
		if(Child != N - 1 && A[Child + 1] > A[Child] ){
			// 待处理数据转为右子节点
			CHild++;
		}
		// 当前元素 小于子元素,交换位置
		if(Tmp < A[Child]) {
			A[i] = A[Child];
		}else {
			// 遇到一个大于的就跳出循环吗
			break;
		}
	}
	A[i] = Tmp;
}

void HeapSort(ElementType A[], int N){
	int i;

	for(i = N / 2; i >= 0; i--){
		// 一次一构建.我说 遇到一个判断失败就break
		PercDown(A, i, N);
	}
	for(i = N - 1; i > 0;i--){
		// 把最前面的值提出来,然后用新的数据构建堆
		Swap(&A[0], &A[i]); // Delete Max
		PercDown(A, 0, i);
	}
}
