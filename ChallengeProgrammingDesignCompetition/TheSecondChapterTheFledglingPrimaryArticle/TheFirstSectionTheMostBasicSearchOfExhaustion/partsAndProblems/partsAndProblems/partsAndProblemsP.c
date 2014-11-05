/*如果想打印出答案，那么可以分两步走，一步先打印出一种结果，第二步打印出所有可能的结果*/
#include<stdio.h>
#define MAX_N 20
int n, a[MAX_N], k;
//我先根据这个状态转移的样子，利用函数递归来实现一下，能实现多少是多少！
int countPrintf=0;
int find=0;
int
state (int i, int sum)
{
countPrintf++;
	printf("%d:state(%d,%d)\n",countPrintf,i,sum);
	//我们可以让程序找到一个后返回1,每找到返回0,这样我们可以从state函数的最终返回值判断有几个满足要求的答案！
	//或者单独写一个find变量，来记录找到了几个！
  if (sum == k)
    {
	    find=1;
      return 0;
    }
  if (i>=n) { return 0; }
  return state (i + 1, sum + a[i]) + state (i + 1, sum);
}

int
main ()
{
  scanf ("%d", &n);
  int i;
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &a[i]);
    }
  scanf ("%d", &k);
  state (0, 0);
  if (find) printf("Yes\n");
  else printf("No\n");
  return 0;
}
