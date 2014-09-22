/*
#Problem ID: 3551
#Submit Time: 2012-09-20 03:27:10
#Run Time: 420
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
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;

int n, a, b;
double p, ans;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> n >> p;
        ans = 0.0;
        a = n - 1;
        b = 1;
        while(a) {
            ans += 1.0 / (1.0 - 1.0*a*(a-1)/n/(n-1) - 1.0*b*(b-1)/n/(n-1)) / p;
            a--;
            b++;
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
