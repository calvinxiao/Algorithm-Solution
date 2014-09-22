/*
#Problem ID: 3787
#Submit Time: 2014-05-14 15:54:13
#Run Time: 60
#Run Memory: 508
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

inline int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return x;
}

pair<int, int> t[20042];
int ans[20042], cnt;

int main()
{
  #ifndef ONLINE_JUDGE
	freopen("0.in", "r", stdin);
  #endif
	int tc;
	tc = get();
	//scanf("%d", &tc);
	while (tc--) {
		int n, l;
		//scanf("%d%d", &n, &l);
		n = get(), l = get();
		for (int i = 0; i < n; ++i)
		{
			int a, b, c;
			//scanf("%d:%d:%d", &a, &b, &c);
			a = get(), b = get(), c = get();
			int temp = a * 3600 + b * 60 + c;
			t[i].first = temp;
			t[i].second = i + 1;
		}
		sort(t, t + n);
		int pre = -7200;
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
		  if (t[i].first - pre < l)
        continue;
			pre = t[i].first;
			ans[cnt++] = t[i].second;
		}
		sort(ans, ans + cnt);
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; ++i)
		{
			printf("%d%c", ans[i], i == cnt - 1 ? '\n':' ');
		}
	}
	return 0;
}
