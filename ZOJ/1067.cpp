/*
#Problem ID: 1067
#Submit Time: 2013-03-28 07:32:46
#Run Time: 0
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

const int BIG = (int)1e9 + 7;
const int MAX = 16;

int R[MAX], G[MAX], B[MAX], r, g, b, idx, ans, d;

int D(int i) {
    return (R[i] - r) * (R[i] - r) + (G[i] - g) * (G[i] - g) + (B[i] - b) * (B[i] - b) ;
}

int main() {
    //freopen("0.in", "r", stdin);
    REP(i, MAX)
        scanf("%d%d%d", &R[i], &G[i], &B[i]);
    while(1) {
        idx = 0, ans = BIG;

        scanf("%d%d%d", &r, &g, &b);
        if (r == -1 && g == -1 && b == -1)
            break;
        REP(i, MAX) {
            d = D(i);
            if (d == 0) {
                idx = i;
                break;
            }
            if (d < ans) {
                idx = i;
                ans = d;
            }
        }

        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, R[idx], G[idx], B[idx]);
    }
    
    return 0;
}
