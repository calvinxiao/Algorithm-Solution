/*
#Problem ID: 2290
#Submit Time: 2013-09-07 02:20:48
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
vector<int> v;
int n, sz;

int bs(int nn)
{
    int l = 0, r = sz - 1, m, ans;
    while (l <= r) {
        m = l + r >> 1;
        if (v[m] <= nn - 1) {
            ans = m;
            l = m + 1;
        } else
            r = m - 1;
    }
    return v[ans];
}

int f(int nn)
{
    if (binary_search(v.begin(), v.end(), nn))
        return -1;
    else {
        int lb = bs(nn);
        if (binary_search(v.begin(), v.end(), nn - lb))
            return nn - lb;
        else
            return f(nn - lb);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("0.in", "r", stdin);
#endif
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    int a = 1, b = 2, t = 2;
    while (t <= 100000000) {
        t = a + b;
        a = b;
        b = t;
        v.push_back(t);
    }
    //cout << t << endl;
    sz = v.size();
    while (cin >> n) {
        int ans = f(n);
        if (ans == -1)
            cout << "lose\n";
        else
            cout << ans << endl;
    }
    return 0;
}
