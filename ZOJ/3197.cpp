/*
#Problem ID: 3197
#Submit Time: 2013-02-27 12:29:40
#Run Time: 50
#Run Memory: 224
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

#define REP(i, n) for(int (i) = 0; (i) < (int)(n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int BIG = (int)1e9 + 7;

int t, n, a[5005][2], start, end;

void Sort(int l, int r) {
    int i = l, j = r, x = a[(l+r) >> 1][0], y = a[(l+r) >> 1][1];
    do {
        while (a[i][0] < x || (a[i][0] == x && a[i][1] < y)) ++i;
        while (x < a[j][0] || (a[j][0] == x && y < a[j][1])) --j;
        if (i <= j) {
            int t;
            t = a[i][0]; a[i][0] = a[j][0]; a[j][0] = t;
            t = a[i][1]; a[i][1] = a[j][1]; a[j][1] = t;
            ++i; --j;
        }
    } while (i <= j);
    if (l < j) Sort(l, j);
    if (i < r) Sort(i, r);
}

int main()
{
	scanf("%d", &t);
	while (t--) {
        scanf("%d", &n);
        REP(i, n) {
            scanf("%d%d", &a[i][0], &a[i][1]);
        }
        Sort(0, n-1);
        int i = 0, j = 0;
        start = end = 0;
        int ans = 0;
        while (i < n && start < n) {
            end = 0;
            int newi = i;
            for (j = i; j < n; ++j) {
                if (a[j][0] > start + 1)
                    break;
                if (a[j][1] > end) {
                    end = a[j][1];
                    newi = j;
                }
            }
            start = end;
            i = j;
            ans += 1;
        }
        printf("%d\n", ans);
	}
}
