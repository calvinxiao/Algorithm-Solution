/*
#Problem ID: 2759
#Submit Time: 2013-05-28 11:03:04
#Run Time: 80
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

const int MAX = 100;

long long N, a[22];
vector<pair<long long, int> > v;
int used[22];

int main()
{
	//freopen("0.in", "r", stdin);
	a[0] = 1;
	REPN(i, 1, 19)
        a[i] = a[i-1] * 3;
    reverse(a, a + 20);

	while (~scanf("%lld", &N)) {

        vector<long long> ans0, ans1;

	    REP(i, 20) {
            used[i] = N / a[i];
            N %= a[i];
	    }

	    for (int i = 19; i >= 0; i--) {
            if (used[i] == 1)
                ans1.push_back(a[i]);
            else if (used[i] == 2) {
                used[i-1] += 1;
                ans0.push_back(a[i]);
            } else if (used[i] == 3)
                used[i-1] += 1;
	    }

        if (ans0.size() == 0)
            ans0.push_back(-1);

	    REP(i, ans0.size())
            printf("%lld%c", ans0[i], (i == ans0.size() - 1) ? '\n' : ' ');
	    REP(i, ans1.size())
            printf("%lld%c", ans1[i], (i == ans1.size() - 1) ? '\n' : ' ');
        puts("");

	}
    return 0;
}
