/*
#Problem ID: 1551
#Submit Time: 2013-07-09 22:02:50
#Run Time: 60
#Run Memory: 188
#ZOJ User: calvinxiao
*/

/**
Calvin Xiao
calvin.xiao at scaurugby.com
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std ;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPN(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define REPI(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

int n, w, h;
int x[111], y[111];

int main()
{
    //freopen("cricket.in", "r", stdin);
    //freopen("cricket.out", "w", stdout);
    while (~scanf("%d%d%d", &n, &w, &h)) {
    	int L = 1, p = 0, q = 0;
    	REPN(i, 1, n) {
    	    scanf("%d%d", x+i, y+i);
    	}
    	REP(i, n+1) {
            REP(j, n+1) {
                int temp = min(w - x[i], h - y[j]);
                REPN(k, 1, n) {
                    if (x[k] > x[i] && y[k] > y[j]) {
                        temp = min(temp, max(x[k] - x[i], y[k] - y[j]));
                    }
                }
                if (L < temp) {
                    L = temp;
                    p = x[i];
                    q = y[j];
                }
            }
    	}
    	printf("%d %d %d\n", p, q, L);
    }
    return 0;
}
