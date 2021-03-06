/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: intervalSchedulingProblemBookCode.cpp
 * 创建日期: 2014年11月29日 星期六 06时37分07秒
 */
//书中不管输入是好事，突出主要代码
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 100000;	//这是ｃ＋＋定义常量的风格，在ｃ中这种风格不好！

//输入
int N, S[MAX_N], T[MAX_N];

//用于对工作排序的ｐａｉｒ数组
pair < int, int >itv[MAX_N];
void
input ()
{
  scanf ("%d", &N);
  int i;
  for (i = 0; i < N; i++)
    {
      scanf ("%d", &S[i]);
      printf ("%d\t", S[i]);
    }
  printf ("\n");

  for (i = 0; i < N; i++)
    {
      scanf ("%d", &T[i]);
      printf ("%d\t", T[i]);
    }
  printf ("\n");
}

void
printitv ()
{
  int i;
  for (i = 0; i < N; i++)
    {
      printf ("(%d,%d)\t", itv[i].second, itv[i].first);
    }
  printf ("\n");
}

void
solve ()
{
  //对ｐａｉｒ进行的是字典序比较
  //为了让结束时间早的工作排在前面，把Ｔ存入ｆｉｒｓｔ，把Ｓ存入ｓｅｃｏｎｄ
  //这里又在小细节上变换，这要看这种变换能带来多大的好处，我的代码中这个不变！
  //或许这里的变化，可以实现用ｓｏｒｔ对一个二元数组进行排序，因为我的排序是自己实现的，所以不需要作出改变去适应他人排序函数的要求，这是作者作出这种小变换的原因！
  for (int i = 0; i < N; i++)
    {
      itv[i].first = T[i];
      itv[i].second = S[i];
    }
  printitv ();
  sort (itv, itv + N);
  printitv ();

  //ｔ是最后所选工作的结束时间
  int ans = 0, t = 0;			//t 是ｔｉｍｅ的第一个字母
  //ａｎｓ是ａｎｓｗｅｒ的前三个字母
  for (int i = 0; i < N; i++)
    {
      if (t < itv[i].second)	//t的更新实现了我想要的比较！

	{
      printf ("%d--(%d,%d)\t",i, itv[i].second, itv[i].first);
	  ans++;
	  t = itv[i].first;
	  //更准确地说，ｔ是上一个时间区间的结束时间，ｉｔｖ［ｉ］．ｓｅｃｏｎｄ是当前时间区间的开始时间，所以只要上一个时间区间的结束时间比当前时间的开始时间就做一次统计，并且把ｔ更新为当前时间的结束时间，进行下一次循环，直至所有的循环结束
	  //这里的算法和我的算法实现的东西是相同的，只不过，我使用了双循环，书中使用的是单循环！不能简单说谁的代码好，我的标准是只要是可以轻松实现，而且测试正确的代码就是好代码，或许作者可以轻松实现他思维中的代码，我必须轻松实现我思维中的代码！
	}
    }
  //printf ("%d\n", ans);
  printf ("\n最多能参加%d项工作\n", ans);
}


int
main ()
{

  input ();
  solve ();
  return 0;
}
