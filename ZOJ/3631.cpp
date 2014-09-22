/*
#Problem ID: 3631
#Submit Time: 2013-04-02 16:01:11
#Run Time: 90
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

int a[33], s[33];
int n, m, ans, temp;

void watashi(int step) {
    if (temp > ans) 
        ans = temp;
    if (temp + s[step] <= ans)
        return;

    if (step == n)
        return;

    //cout << step << ' ' << temp << ' ' << ans <<  endl;

    temp += a[step];
    if (temp <= m) {
        watashi(step + 1);
    }

    temp -= a[step];
    watashi(step + 1);
}

int main() {

    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        sort(a, a + n);
        reverse(a, a + n);
        for (int i = 0; i <= n+1; ++i)
            s[i] = 0;
        for (int i = n - 1; i >= 0; --i)
            s[i] = a[i] + s[i+1];

        ans = 0;
        temp = 0;
        watashi(0);
        printf("%d\n", ans);
    }
    return 0;
}