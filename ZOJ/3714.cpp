/*
#Problem ID: 3714
#Submit Time: 2013-06-19 14:03:00
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
#define BIG 1000000009;
using namespace std;

int n, m, a[222];

int main()
{
    //freopen("0.in", "r", stdin);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        REPN(i, 1, n) cin >> a[i];
        REPN(i, 2, n) a[i] += a[i-1];
        int ans = 0;
        REPN(i, 1, n) {
            int j = i + m - 1;
            if (j <= n) {
                ans = max(ans, a[j] - a[i-1]);
            } else {
                ans = max(ans, a[n] - a[i-1] + a[j-n]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
