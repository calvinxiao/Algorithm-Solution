/*
#Problem ID: 3778
#Submit Time: 2014-04-17 16:28:55
#Run Time: 90
#Run Memory: 168
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

int tc, n, nn, m, maxV, i, v, ans, sum;

int main()
{
	scanf("%d ", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		nn = n;
		maxV = 0;
		sum = 0;
		while (nn--) {
			scanf("%d", &v);
			sum += v;
			if (maxV < v)
				maxV = v;
		}
		if (n <= m)
			printf("%d\n", maxV);
		else {
			ans = sum / m + (sum % m != 0);
			if (ans < maxV)
				printf("%d\n", maxV);
			else
				printf("%d\n", ans);
		}
	}
	return 0;
}