/*
#Problem ID: 1909
#Submit Time: 2013-05-27 15:43:15
#Run Time: 3940
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 100;

int tc, n, a[22];

int main()
{
	//freopen("0.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
        scanf("%d", &n);
        REP(i, n) scanf("%d", a + i);

        vector<int> ans; // save the combination of index that can form a line

        int sum = 0;
        REP(i, n) sum += a[i];
        if (sum % 4 != 0) {
            printf("no\n");
            continue;
        }
        sum /= 4;

        for (int i = 0; i < (1<<n); ++i) {
            int temp = 0;
            for (int j = 0; j < n; ++j) {
                if ((1<<j) & i)
                    temp += a[j];
            }
            if (temp == sum)
                ans.push_back(i);
        }
        int m = ans.size();
        if (m < 4) {
            printf("no\n");
            continue;
        }

        bool found = false;
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) if ((ans[i] & ans[j]) == 0) {
                for (int k = j + 1; k < m; ++k) {
                    int an = (ans[i] & ans[j]) | (ans[i] & ans[k]) | (ans[j] & ans[k]); // if the combination doesn't conflict each other
                    if (an == 0) {
                        found = true;
                        //break;
                        goto dingdingding;
                    }
                }
            }
        }

        dingdingding:
            int go = 1;

        if (found) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
	}
    return 0;
}
