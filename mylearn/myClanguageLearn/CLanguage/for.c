/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: for.c
 * 创建日期: 2014年12月27日 星期六 06时32分16秒
 * 程序想法：检测ｆｏｒ循环中初始条件是不是也要通过判断函数！ 
 */
#include<stdio.h>

void input() {
}

void solve() {
	int i;
	printf("test 1:\n");
	for(i=0;i<0;i++) {
		printf("i=%d\n",i);
	}
	printf("test 2:\n");
	for(i=0;i<1;i++) {
		printf("i=%d\n",i);
	}

}

int main() {
    input();
    solve();
    return 0;
}

