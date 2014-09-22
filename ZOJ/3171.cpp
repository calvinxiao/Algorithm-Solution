/*
#Problem ID: 3171
#Submit Time: 2013-04-19 01:14:28
#Run Time: 0
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
#include <algorithm>
#include <cstring>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;


long long dp[6];
char c[10002];
int len;

int main() {
    //freopen("0.in", "r", stdin);
    int diff = 'a' - 'A';
    while (~scanf("%s", c)) {
        for (int i = 0; i < 6; ++i)
            dp[i] = 0;
        len = strlen(c);
        for (int i = 0; i < len; ++i) {
            if ('A' <= c[i] && c[i] <= 'Z')
                c[i] += diff;
            if (c[i] == 's')
                dp[1]++;
            else if (c[i] == 'e') {
                dp[4] += dp[3];
                dp[2] += dp[1];
            } else if (c[i] == 'v') {
                dp[3] += dp[2];
            } else if (c[i] == 'n')
                dp[5] += dp[4];
        }
        printf("%lld\n", dp[5]);
    }
    return 0;
}
