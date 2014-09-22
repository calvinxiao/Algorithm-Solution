/*
#Problem ID: 1501
#Submit Time: 2013-07-10 00:29:33
#Run Time: 0
#Run Memory: 264
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

const int MAX = 142;
int g[MAX][MAX], f[MAX];
int n;
int tc;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    while (scanf("%d", &n) && n) {
        if (tc)
            puts("");
        tc++;
        memset(g, 0, sizeof g);
        vector<int> e[8];
        for (int i = 1; i <= (1<<n); ++i)
            e[0].push_back(i), f[i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < (1<<(n-i)); ++j) {
                int t; scanf("%d", &t);
                e[i].push_back(t);
                f[t] = i;
                g[t][t^e[i-1][j<<1]^e[i-1][j<<1|1]] = 1;
            }
        }
        REPN(k, 1, (1<<n)) {
            REPN(i, 1, (1<<n)) {
                REPN(j, 1, (1<<n)) {
                    if (g[i][k] && g[k][j])
                        g[i][j] = 1;
                }
            }
        }
        int m; scanf("%d", &m);
        while (m--){
            int t; scanf("%d", &t);
            int a = 1, b = 1<<n;
            int nn = e[f[t]].size() >> 1;

            for (int i = 0; i < e[f[t]].size(); ++i) {
                int j = e[f[t]][i];
                if (g[j][t])
                    a++;
            }
            for (int i = 1; i <= (1<<n); ++i)
                if (g[t][i])
                    b--;
            printf("Player %d can be ranked as high as %d or as low as %d.\n", t, a, b);
        }

    }

    return 0;
}
