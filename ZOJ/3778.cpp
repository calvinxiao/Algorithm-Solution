/*
#Problem ID: 3778
#Submit Time: 2014-04-17 16:36:52
#Run Time: 40
#Run Memory: 168
#ZOJ User: calvinxiao
*/

#include <cstdio>
using namespace std;

inline int read_int(){
    int a=0, c = getchar();
    a=c-48;
    while((c=getchar())!=' '&&c!='\n'&&c!=EOF)
        a=a*10+c-48;
    return a;
}

int tc, n, nn, m, maxV, i, v, ans, sum;

int main()
{
	tc = read_int();
	while (tc--) {
		n = read_int();
		m = read_int();
		//printf("%d %d\n", n, m);
		nn = n;
		maxV = 0;
		sum = 0;
		while (nn--) {
			v = read_int();
			sum += v;
			if (maxV < v)
				maxV = v;
			//printf("%d ", v);
		}
		//printf("\n");
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