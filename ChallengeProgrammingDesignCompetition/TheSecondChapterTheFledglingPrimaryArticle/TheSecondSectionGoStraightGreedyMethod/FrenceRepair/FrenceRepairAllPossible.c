/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: FrenceRepairAllPossible.c
 * 创建日期: 2014年12月28日 星期日 06时38分01秒
 * 程序想法：先实现给定一个排列，我找出所有分割下的花销！ 
 */
#include<stdio.h>
#define MAX_N 20000
//输入数据
int N;
int L[MAX_N];
//内部数据
int spending = 0;
int indent = 0;

void swap(int *Aj, int *Aj1) {
    int originAj = (*Aj);
    *Aj = (*Aj1);
    *Aj1 = originAj;
}
void printarray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
	printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n) {
    int swapped;
    do {
	swapped = 0;
	int i;
	//这里依然是每一次都从头开始比较，调换次序
	for (i = 1; i <= n - 1; i++) {
	    //printarray(A, n);
	    if (A[i - 1] > A[i]) {
		swap(&A[i - 1], &A[i]);
		swapped = 1;
	    }
	    //printarray(A, n);
	}
	//这里调换一次就让ｎ减一，这是一个我没有见过的处理办法！
	n = n - 1;
	//printf("a round end n=%d\n", n);
    } while (swapped);
}
void input() {
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++) {
	scanf("%d", &L[i]);
    }
}
void test_input() {
    printf("N=%d\n", N);
    int i;
    for (i = 0; i < N; i++) {
	printf("L[%d]=%d\n", i, L[i]);
    }
}

//需要内部计算ｓｐｅｎｇｉｎｇ,计算出每一种状态下的ｓｐｅｎｄｉｎｇ．
void cutting(int start, int end) {
    if (start > end) {
	    printf("------end >\n");
	return;
    }
    if (start == end) {
	    printf("------end =\n");
	return;
    }
    if (start + 1 == end) {
	    printf("------end +1\n");
	return;
    }

    int cuttingPoint;
    for (cuttingPoint = start; cuttingPoint < end; cuttingPoint++) {

	//应该是产生一次切割加一次
	int i;
	for (i = start; i <= end; i++) {
	    spending += L[i];
	}

	indent++;

	for (i = 0; i < indent; i++) {
	    printf("\t");
	}

	printf("cutting(%d-|%d|-%d)\n", start, cuttingPoint, end);
	printf("\tcurrent spending = %d\n", spending);
	cutting(start, cuttingPoint);
	for (i = start; i <= end; i++) {
	    spending -= L[i];
	}
	for (i = start; i <= end; i++) {
	    spending += L[i];
	}
	indent++;
	indent--;

	printf("cutting(%d-|%d|-%d)\n", start, cuttingPoint, end);
	printf("\tcurrent spending = %d\n", spending);
	cutting(cuttingPoint + 1, end);
	indent--;
	for (i = 0; i < indent; i++) {
	    printf("\t");
	}

	for (i = start; i <= end; i++) {
	    spending -= L[i];
	}

    }
    //这里感觉用队列，广度优先搜索比较好可以写一个广度优先搜索的版本
    //

}

void test_cutting() {
    int start = 0, end = N - 1;
    cutting(start, end);
}
void solve() {
    int i;
    int spending = 0;
    bubbleSort(L, N);
    for (i = 0; i < N; i++) {
	spending += L[i] * (N - i);
    }
    spending -= L[0];
    //printf("spending = %d\n", spending);
    printf("%d\n", spending);
}

int main() {
    input();
    test_input();
    //solve();
    //这里提出一个新问题，所有点都被切割掉的最后状态才是我们需要的状态！
    test_cutting();
    return 0;
}