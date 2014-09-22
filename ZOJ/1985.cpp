/*
#Problem ID: 1985
#Submit Time: 2013-08-19 14:43:36
#Run Time: 60
#Run Memory: 1352
#ZOJ User: calvinxiao
*/

#include <cstdio>

using namespace std;

inline int read_int(){
	int a=0;
	int b=1,c=getchar();
	if(c=='-')b=-1;
	else a=c-48;
	while((c=getchar())!=' '&&c!='\n')
		a=a*10+c-48;
	a*=b;
	return a;
}

#define N 100010
int a[N], p[N], p1[N], s, h;
long long ans;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
	int n;
	while (scanf(" %d ", &n) && n) {
		s = ans = 0;
		for (int i = 0; i < n; i++) {
			//scanf("%d", &h);
                        h = read_int();
			if (ans < h)
				ans = h;
			if (s == 0) {
				a[s] = h;
				p[s] = i;
				p1[s++] = i;
			} else {
				long long t;
				int mini = i;
				int maxi = i;
				while (s - 1 >= 0 && a[s - 1] > h) {
					t = (long long)(i - p[s - 1]) * a[s - 1];
					if (ans < t)
						ans = t;
					s--;
					mini = p[s];
				}
				a[s] = h;
				p[s] = mini;
				p1[s++] = maxi;
			}
		}
		long long t;
		int i = p1[s - 1] + 1;
		while (s - 1 >= 0) {
			t = (long long)(i - p[s - 1]) * a[s - 1];
			if (ans < t)
				ans = t;
			s--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}