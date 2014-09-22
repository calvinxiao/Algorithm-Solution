/*
#Problem ID: 1542
#Submit Time: 2013-02-26 12:51:21
#Run Time: 50
#Run Memory: 344
#ZOJ User: calvinxiao
*/

#include <stdio.h>

#define MAX 15005

int n, m, a[MAX], b[MAX], c[MAX], f[1005], maxLen, cnt, e[1005];

void Sort(int l, int r) {
    int i = l, j = r, x = c[(l+r) >> 1];
    do {
        while (c[i] < x) ++i;
        while (x < c[j]) --j;
        if (i <= j) {
            int t;
            t = a[i]; a[i] = a[j]; a[j] = t;
            t = b[i]; b[i] = b[j]; b[j] = t;
            t = c[i]; c[i] = c[j]; c[j] = t;
            ++i; --j;
        }
    } while (i <= j);
    while (i < r && c[i] == c[i+1]) ++i;
    while (l < j && c[j] == c[j-1]) --j;
    if (l < j) Sort(l, j);
    if (i < r) Sort(i, r);
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
        maxLen = 0; cnt = 0;
        int i, j;
        for (i = 1; i <= m; ++i) {
            scanf("%d%d%d", a+i, b+i, c+i);
        }
        Sort(1, m);
        for (i = 1; i <= n; ++i)
            f[i] = i;
        for (i = 1; i <= m; ++i) {
            while (f[a[i]] != f[f[a[i]]]) f[a[i]] = f[f[a[i]]];
            while (f[b[i]] != f[f[b[i]]]) f[b[i]] = f[f[b[i]]];
            if (f[a[i]] != f[b[i]]) {
                if (maxLen < c[i])
                    maxLen = c[i];
                f[f[a[i]]] = f[b[i]];
                e[cnt++] = i;
            }
            if (cnt == n - 1)
                break;
        }
        printf("%d\n%d\n", maxLen, cnt);
        for (i = 0; i < cnt; ++i)
            printf("%d %d\n", a[e[i]], b[e[i]]);

	}
	return 0;
}
