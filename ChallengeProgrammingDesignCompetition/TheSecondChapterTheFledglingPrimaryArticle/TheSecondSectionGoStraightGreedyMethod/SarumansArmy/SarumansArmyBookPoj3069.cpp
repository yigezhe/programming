/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: SarumansArmy.c
 * 创建日期: 2014年12月17日 星期三 07时03分24秒
 * 程序想法：直接写代码了，我的思路就体现在代码中！ 
 * 书中的问题算是解决了，ｐｏｊ中相同的问题，有一些变换，我需要作出改变来实现之！
 *  一种检查我的代码错误的办法是看书中的程序与我的程序各自产生的标记点是不是相同，不同，我就要分析原因了！
 *  检查的结果是书中的代码是对了，我的代码不对！
 *  标记点右边的点就是最左未标记点！
测试结果！
13732122	docode	3069	Accepted	404K	16MS	G++	2092B	2014-12-22 06:10:46
 */
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 1000
//输入
int N, R;
int X[MAX_N];

void input() {
    scanf("%d", &N);
    scanf("%d", &R);
    int i;
    for (i = 0; i < N; i++) {
	scanf("%d", &X[i]);
    }
}
void test_input() {
    input();
    printf("N=%d\n", N);
    printf("R=%d\n", R);
    printf("X={");
    int i;
    for (i = 0; i < N; i++) {
	printf("%d,", X[i]);
    }
    printf("}\n");

}

int oneCaseInput() {
    scanf("%d%d", &R, &N);
    if (N == (-1) && R == (-1))
	return 0;
    int i;
    for (i = 0; i < N; i++) {
	scanf("%d", &X[i]);
    }
    return 1;
}
void test_oneCaseInput() {
    while (oneCaseInput()) {
	printf("R=%d\t", R);
	printf("N=%d\n", N);
	printf("X={");
	int i;
	for (i = 0; i < N; i++) {
	    printf("%d,", X[i]);
	}
	printf("}\n");
    }

}
void solveOneCase() {
    sort(X, X + N);

    int i = 0, ans = 0;
    //看一下ｗｈｉｌｅ的执行情况
    //ｉ＝０，ｓ＝Ｘ［０］，ｉ＝１，ｘ［ｉ］＜＝X[0]＋Ｒ
    //i=2
    //p=X[2-1];
    //有必要全面关注ｉ的变化
    while (i < N) {
	//ｓ是没有被覆盖的最左的点的位置
	//前一个的最右未标记点就是下一个的最左未标记点！
	//printf("在最左未标记点　i=%d\n", i);
	int s = X[i++];		//ｉ＋＋帮助从下一个开始搜索！
	//这里的ｉ＋＋很重要，直接推动着搜索的进行！
	//一直向右前进直到距ｓ的距离大于Ｒ的点
	while (i < N && X[i] <= s + R)
	    i++;
	//printf("推进到标记点附近 ｉ＝%d\n", i);
	//p
	//ｐ是新加上标记的点的位置
	int p = X[i - 1];
	//printf("被标记的点 i=%d\n", i - 1);
	//printf("%d:%d\t",i-1,X[i-1]);
	//一直向右前进直到距ｐ的距离大于Ｒ的点
	while (i < N && X[i] <= p + R)
	    i++;
	//printf("推进到最右未标记点i=%d\n", i);
	ans++;
	//printf("\n-------------------\n");
    }
    printf("%d\n", ans);
    //好了，有了一个较完整的理解，程序写得很精妙，但是我还是需要用自己的程序语言来表达相同的构想！
}

void solve() {
    while (oneCaseInput()) {
	solveOneCase();
    }
}


int main() {
    //test_oneCaseInput();
    solve();
    return 0;
}
