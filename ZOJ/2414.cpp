/*
#Problem ID: 2414
#Submit Time: 2013-05-28 17:24:25
#Run Time: 200
#Run Memory: 264
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

const int MAX = 10001;
int p[MAX];
int pp[MAX];

void add(int n, vector<int> &a) {
    if (n == 0) return;
    a.push_back(pp[n]);
    add(n-pp[n], a);
}

int main()
{
    int n;
	//freopen("0.in", "r", stdin);
	for (int i = 2; i < MAX; ++i)
        p[i] = 1;
    for (int i = 2; i < MAX; ++i) {
        if (p[i]) {
            pp[i] = i;
            for (int j = i + i; j < MAX; j += i)
                p[j] = 0;
        }
        if (!p[i]) {
            for (int j = 2; j <= (i>>1); ++j) {
                if (p[j]) {
                    int k = i - j;
                    if (p[k]) {
                        if (p[i] == 0 || p[i] > p[j] + p[k] || p[i] == p[j] + p[k]) {
                            if (p[i] == p[j] + p[k]) {
                                int ma = max(pp[j], pp[k]);
                                if (pp[i] > ma)
                                    pp[i] = ma;
                                continue;
                            }
                            p[i] = p[j] + p[k];
                            pp[i] = max(pp[j], pp[k]);
                        }
                    }
                }
            }
        }
    }

    while (~scanf("%d", &n)) {
        printf("%d\n", p[n]);
        if (p[n] > 0) {
            vector<int> ans;
            add(n, ans);
            for (int i = 0; i < ans.size(); ++i)
                printf("%d%c", ans[i], i == ans.size() - 1 ? '\n':' ');
        }
    }
    return 0;
}
