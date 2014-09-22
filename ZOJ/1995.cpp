/*
#Problem ID: 1995
#Submit Time: 2013-08-30 02:00:45
#Run Time: 0
#Run Memory: 2148
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

const short int N = 1002;
int tc, n;
short int d[N], f[N][N];

template<class T> inline T MIN(T a, T b) {
    if (a < b)
        return a;
    return b;
}

template<class T> inline T MAX(T a, T b) {
    if (a < b)
        return b;
    return a;
}


void P(int t, int h) {
    if (t == 0) {
        return;
    }
    t--;
    if (f[t][h+d[t]] <= f[n][0]) {
        P(t, h+d[t]);
        printf("D");
    } else if (f[t][h-d[t]] <= f[n][0]) {
        P(t, h-d[t]);
        printf("U");
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        REP(i, n) scanf("%d", d+i);
        REP(i, n+1) REP(j, N) f[i][j] = N;
        f[0][0] = 0;
        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0, mm = m; j <= mm; j++) {
                if (f[i][j] != N) {
                    short int t = j + d[i];
                    if (m < t)
                        m = t;
                    f[i+1][t] = MIN(f[i+1][t], MAX(t, f[i][j]));
                    t = j - d[i];
                    if (t >= 0) {
                        f[i+1][t] = MIN(f[i+1][t], f[i][j]);
                    }
                }
            }
        }

        if (f[n][0] == N) {
            puts("IMPOSSIBLE");
        } else {
            P(n, 0);
            puts("");
        }
    }
    return 0;
}
