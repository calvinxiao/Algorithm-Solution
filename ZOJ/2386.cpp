/*
#Problem ID: 2386
#Submit Time: 2014-07-07 00:27:35
#Run Time: 170
#Run Memory: 3520
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;

inline int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9'));
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return x;
}

int n, a[500000];

long long gao(int l, int r) {
    if (l == r)
        return 0;
    if (l + 1 == r) {
        if (a[l] < a[r])
            return 0;
        int t = a[l];
        a[l] = a[r]; 
        a[r] = t;
        return 1;
    }
    int mid = (l + r) >> 1;
    long long lans = gao(l, mid);
    long long rans = gao(mid + 1, r);
    long long ans = lans + rans;
    int i = l;
    for (int j = mid + 1; j <= r; j++) {
        if (i <= mid && a[i] > a[r]) {
            ans += (long long)(r - j + 1) * (mid - i + 1);
            break;
        }
        while (a[i] < a[j] && i <= mid)
            i++;
        if (i > mid) {
            break;
        }

        ans += mid - i + 1;
    }
    if (l != 0 || r != n - 1) {
        inplace_merge(a + l, a + mid + 1, a + r + 1);
    }
    return ans;

}
int main()
{
  #ifndef ONLINE_JUDGE
	freopen("0.in", "r", stdin);
  #endif

	while (1) {
		n = get();
		if (!n)
			break;

    long long ans = 0;

		for (int i = 0; i < n; i++) {
            a[i] = get();
		}

    ans = gao(0, n-1);
		printf("%lld\n", ans);
	}
	return 0;
}