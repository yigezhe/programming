/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: 35Other.c
 * 创建日期: 2015年01月04日 星期日 07时15分00秒
 * 程序想法： 

Mon, 13 Sep 2004, 15:14 
naimad 
Switzerland	
   Quote   Report    31
Hi there, As everybody is posting his code, I will do so too. It looks like this:
	
Hide Code

#include <stdio.h>
#include <math.h>

// Calculate the sum of all multiples of 3 or 5 bellow 1000 //

int main(int argc, char *argv[]) {
	double mcp1(double n, double m);
	printf("--- %.1f\n",
		mcp1(3.0, 999.0) + mcp1(5.0, 999.0) - mcp1(15.0, 999.0));
	return 0;
}

double mcp1(double n, double m) {
	double floor(double x);
	double fl = floor(m/n);
	return n * fl * (fl + 1) / 2;
}

Comments are wellcome.
[Permanent post] 
这里我只关注ｃ,c++ｃｏｄｅ，其他编程语言的代码我就不关注了！
 */
#include<stdio.h>
#include <math.h>

void input() {
}

// Calculate the sum of all multiples of 3 or 5 bellow 1000 //
double mcp1(double n, double m) {
    double floor(double x);	//怎么在函数内部做另一个函数的声明？
    double fl = floor(m / n);
    return n * fl * (fl + 1) / 2;
}

void solve() {
	//这里使用９９９，而不是１０００对我是一个帮助！
    double mcp1(double n, double m);
    printf("--- %.1f\n",
	   mcp1(3.0, 999.0) + mcp1(5.0, 999.0) - mcp1(15.0, 999.0));
}

int main() {
    input();
    solve();
    return 0;
}
