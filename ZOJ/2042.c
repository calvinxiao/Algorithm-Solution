/*
#Problem ID: 2042
#Submit Time: 2014-01-26 13:25:46
#Run Time: 50
#Run Memory: 172
#ZOJ User: calvinxiao
*/

#include <stdio.h>

int read_int(){
    int a=0;
    int b=1,c=getchar();
    if(c=='-')b=-1;
    else a=c-48;
    while((c=getchar())!=' '&&c!='\n')
        a=a*10+c-48;
    a*=b;
    return a;
}

int line, i, j, t, n, a, k, m1[101], m2[101];

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  scanf("%d", &t);
  while (t--) {
    if (line)
      puts("");
    line++;

    scanf(" %d%d ", &n, &k);

    for (i = 0; i < k; i++)
      m1[i] = m2[i] = 0;

    m1[0] = 1;
    for (i = 0; i < n; i++) {
      for (j = 0; j < k; j++)
        m2[j] = 0;
      /*scanf("%d", &a);**/
      a = read_int();
      for (j = 0; j < k; j++) {
        if (m1[j]) {
          int t = j + a;
          if (t < 0)
            t += 10000 * k;
          t %= k;
          m2[t] = 1;
          t = j - a;
          if (t < 0)
            t += 10000 * k;
          t %= k;
          m2[t] = 1;
        }
      }
      for (j = 0; j < k; j++)
        m1[j] = m2[j];
    }
    if (m1[0])
      puts("Divisible");
    else
      puts("Not divisible");
  }
	return 0;
}
