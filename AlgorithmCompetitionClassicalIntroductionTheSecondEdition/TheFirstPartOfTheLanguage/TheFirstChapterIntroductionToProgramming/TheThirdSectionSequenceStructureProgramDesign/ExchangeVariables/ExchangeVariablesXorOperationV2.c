#include<stdio.h>
int
main ()
{
  int a, b;

  //scanf("%d%d", &a, &b);
  //这个每办法，我只能直接分析！
  //这里展示的是ｂｉｔ级别的合并与分离
  int i, j;
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 2; j++)
	{
	  a = i, b = j;

	  //只是看一下这个代码能够得到正确的结果不，对代码的理解，我已经在书上做了笔记！
	  printf ("before(a=%d,b=%d)\n", a, b);
	  a ^= b ^=a^=b;//这个代码有警告，但是还是可以编译通过！
	  printf ("after(a=%d,b=%d)\n", a, b);
	}
    }
  return 0;
}
