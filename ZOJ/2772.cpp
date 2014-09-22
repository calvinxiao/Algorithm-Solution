/*
#Problem ID: 2772
#Submit Time: 2013-03-20 10:34:00
#Run Time: 0
#Run Memory: 188
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

int b[4], n, TC;

int main() {
    int a[4] = {25, 10, 5, 1};
    scanf("%d", &TC);
    REPN(tc, 1, TC) {
        scanf("%d", &n);
        REP(i, 4) {
            b[i] = n / a[i];
            n -= a[i] * b[i];
        }
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", tc, b[0], b[1], b[2], b[3]);
    }
    return 0;
}
