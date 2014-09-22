/*
#Problem ID: 2723
#Submit Time: 2013-03-20 10:21:34
#Run Time: 450
#Run Memory: 4092
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
#define REPN(i, a, n) for (int i = (a); i <= (n); ++i)

const int maxn = 1000005;

int n, p, a, b, good;

int pr[maxn];


int main() {
    REPN(i, 2, maxn-1) pr[i] = 1;
    for (int i = 4; i < maxn; i += 2) pr[i] = 0;
    REP(i, maxn) if (pr[i]) {
        for (int j = i+i; j < maxn; j += i)
            pr[j] = 0;
    }
    while (~scanf("%d", &p)) {
        good = 0;
        REPN(i, 2, p/2) if (p%i == 0) {
            a = i; b = p / a;
            if (pr[a] && pr[b]) {
                    //cout << a << ' ' << b <<endl;
                good = 1;
                break;
            }
        }
        if (good)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
