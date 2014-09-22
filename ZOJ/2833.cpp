/*
#Problem ID: 2833
#Submit Time: 2013-03-19 22:41:28
#Run Time: 480
#Run Memory: 968
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

int f[100005], c[100005], a, b, n, m, tc;
char command;

int main() {
    //freopen("0.in", "r", stdin);
    while(~scanf("%d%d", &n, &m)) {
        tc++;
        if (tc > 1)
            puts("");
        printf("Case %d:\n", tc);
        REP(i, n+1) {
            f[i] = i;
            c[i] = 1;
        }
        REP(mm, m) {
            scanf(" %c", &command); 
            if (command == 'M') {
                scanf("%d%d", &a, &b);
                while (f[a] != f[f[a]]) f[a] = f[f[a]];
                while (f[b] != f[f[b]]) f[b] = f[f[b]];
                if (f[a] != f[b]) {
                    c[f[b]] += c[f[a]];
                    f[f[a]] = f[b];
                }
            } else {
                scanf("%d", &a);
                while (f[a] != f[f[a]]) f[a] = f[f[a]];
                printf("%d\n", c[f[a]]);
            }
        }
    }
    return 0;
}