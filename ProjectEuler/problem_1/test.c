#include<stdio.h>
#define MAX_N 1000
int main() {

	int n=MAX_N-1;
    printf("浮点数形式：%lf\n", 7 * n * n / 30.0 + n / 2.0);
    printf("整数形式一：%d\n", 7 * n * n / 30 + n / 2);
    printf("整数形式二：%d\n", (int) (7 * n * n / 30.0 + n / 2.0));
    return 0;
}