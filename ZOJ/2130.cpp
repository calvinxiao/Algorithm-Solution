/*
#Problem ID: 2130
#Submit Time: 2013-03-19 21:49:08
#Run Time: 170
#Run Memory: 196
#ZOJ User: calvinxiao
*/

/**
Calvin's Code
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;

#define REP(i, n) for (int i = 0; i < (n); ++i)

const int maxn = 66;
char a[maxn][maxn], b[maxn][maxn];
int N, M, n, m, ans, cnt;

int main() {
    //freopen("0.in", "r", stdin);
    while(~scanf("%d%d%d%d", &N, &M, &n, &m)) {
        REP(i, N) REP(j, M) scanf(" %c", &a[i][j]);
        REP(i, n) REP(j, m) scanf(" %c", &b[i][j]);
        ans = 0;
        REP(i, N-n+1) REP(j, M-m+1) {
            int cnt = 1;
            REP(ii, n) 
                if (cnt)
                    REP(jj, m)
                        if (b[ii][jj] != '.' && b[ii][jj] != a[i+ii][j+jj]) {
                            cnt = 0;
                            break;
                        }
            ans += cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}