/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: errno.c
 * 创建日期: 2014年12月04日 星期四 22时13分11秒
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input() {
}

void solve() {
    int i = 0;
    for (i = 0; i < 256; i++)
	printf("errno.%02d is: %s\n", i, strerror(i));
}

int main() {

    input();
    solve();
    return 0;
}
