/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: stringPointer.c
 * 创建日期: 2014年12月13日 星期六 07时39分03秒
 * 程序想法：学习一下字符串中的指针是如何使用的！ 
 */
#include<stdio.h>

void input() {
}

void way1() {
    char string1[] = "I love China!";
    printf("%s\n", string1);
    char *string = "I love China!";
    printf("%s\n", string);
    char *ps = "this is a book";
    int n = 10;
    ps = ps + n;
    printf("%s\n", ps);

    //static int a[3][4] = { {0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, {10, 11}};
    static int a[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    char *PF;
    PF = "%d,%d,%d,%d,%d\n";
    printf(PF, a, *a, a[0], &a[0], &a[0][0]);
    printf(PF, a + 1, *(a + 1), a[1], &a[1], &a[1][0]);
    printf(PF, a + 2, *(a + 2), a[2], &a[2], &a[2][0]);
    printf("%d,%d\n", a[1] + 1, *(a + 1) + 1);
    printf("%d,%d\n", *(a[1] + 1), *(*(a + 1) + 1));
}
void solve() {
}

int main() {
    input();
    solve();
    way1();
    return 0;
}
