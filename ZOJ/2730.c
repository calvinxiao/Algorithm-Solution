/*
#Problem ID: 2730
#Submit Time: 2013-08-15 20:39:45
#Run Time: 0
#Run Memory: 164
#ZOJ User: calvinxiao
*/

#include <stdio.h>

#define N 49

int n, cnt;
char a[1177], g[N][N];
int i, j;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    while (~scanf("%d", &n)) {
        if (n == 1) {
            printf("1\n0\n");
            continue;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                g[i][j] = 0;
        }
        cnt = 0;
        a[cnt++] = n-1;
        while (1) {
            int t = a[cnt-1], update = 0;
            for (i = 0; i < n; i++) if (i != t) {
                if (!g[t][i]) {
                    update = 1;
                    a[cnt++] = i;
                    g[t][i] = g[i][t] = 1;
                    break;
                }
            }
            if (!update)
                break;
        }
        cnt--;
        printf("%d\n", cnt);
        for (i = 0; i < cnt; i++)
            printf("%d%c", a[i], i == (cnt-1)?'\n':' ');

    }
    return 0;
}
