/*
#Problem ID: 2180
#Submit Time: 2013-05-04 00:43:13
#Run Time: 130
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>

using namespace std;

int tc, n, m, i, j, k, kk, a[1001], r[1001], ans;
char c;

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &m);
        ans = 0;
        memset(a, 0, sizeof a);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                scanf(" %c", &c);
                if (c == 'F')
                    ++a[j];
                else
                    a[j] = 0;
            }
            k = 0;
            while (k < m) {
                r[k] = k;
                while (r[k] != 0 && a[r[k] - 1] >= a[k])
                    r[k] = r[r[k] - 1];
                ++k;
            }
            // k = m
            while (--k >= 0) {
                kk = k;
                while (kk < m-1 && a[kk+1] >= a[kk])
                    kk = r[kk + 1];
                if ( ans < (kk - r[k] + 1) * a[k] )
                    ans = (kk - r[k] + 1) * a[k];
                r[k] = kk;
            }
        }
        printf("%d\n", (ans << 2) - ans);
    }

    return 0;
}
