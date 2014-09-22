/*
#Problem ID: 2418
#Submit Time: 2013-06-08 17:49:41
#Run Time: 10
#Run Memory: 188
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

const int MAX = 55;

int n, g[7][7], dd[7][7], ans, d[7];

void dfs(int step, int idx){
    d[step] = idx;
    if (step > 0) {
        for (int j = 0; j < n; ++j) {
            dd[step][j] = dd[step-1][j] + g[step][(j+idx)%n];
            if (dd[step][j] >= ans)
                return ;
        }
    }
    if (n - 1 == step) {
        int ma = -999999999;
        REP(i, n)
            if (ma < dd[step][i])
                ma = dd[step][i];
        //cout << ma << endl;
        if (ma < ans)
            ans = ma;
        return;
    }
    REP(i, n)
        dfs(step+1, i);
}

int main()
{
    //freopen("0.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == -1)
            break;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                scanf("%d", &g[i][j]);// g[i][j];
        }
        //
        int m[7];
        REP(i, n) {
            m[i] = -111111;
            REP(j, n)
                if (m[i] < g[i][j])
                    m[i] = g[i][j];
        }

        REP(i, n) {
            for (int j = i + 1; j < n; ++j) {
                if (m[j] > m[i]) {
                    int t;
                    t = m[i]; m[i] = m[j]; m[j] =t;
                    for (int k = 0; k < n; ++k) {
                        t = g[i][k]; g[i][k] = g[j][k]; g[j][k] = t;
                    }
                }
            }
        }

        ans = 999999999;
        for (int i = 0; i < n; ++i)
            dd[0][i] = g[0][i];
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}
