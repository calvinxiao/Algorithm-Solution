/*
#Problem ID: 1268
#Submit Time: 2013-05-30 09:21:46
#Run Time: 0
#Run Memory: 968
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

const int MAX = 100001;

int f[MAX], v[MAX], s, t;

int ff(int _) {
	if (f[f[_]] != f[_])
		f[_] = ff(f[_]);
	return f[_];
}

int main()
{
	//freopen("0.in", "r", stdin);
	int tc = 0;
	while (scanf("%d%d", &s, &t) && s >= 0 && t >= 0) {
		tc++;
		memset(v, 0, sizeof v);
		REP(i, MAX)
			f[i] = i;
		int cnt = 0;
		set<int> se;
		int good = 1;
		while (s != 0 && t != 0) {
			// deal with s, t, then update them
			//printf("%d %d\n", s, t);
			cnt++;
			se.insert(s);
			se.insert(t);
			if (v[t]) {
				good = 0;
			}
			v[t] = 1;
			int fs = ff(s);
			int ft = ff(t);

			if (fs == ft)
                good = 0;

			f[ft] = fs;

			scanf("%d%d", &s, &t);
			if (s == 0 && t == 0)
				break;
		}
		//cout << endl;

		if (good)
            // empty
			if (cnt != 0 && cnt != se.size() - 1) {
				good = 0;
			}

		if (cnt > 0 && good) {
			vector<int> p;
			p.insert(p.begin(), se.begin(), se.end());
			int fp = ff(p[0]);
			for (int i = 1; i < p.size(); ++i) {
				int tp = ff(p[i]);
				if (fp != tp) {
					good = 0;
					break;
				}
			}
		}

		if (good) {
			printf("Case %d is a tree.\n", tc);
		} else {
			printf("Case %d is not a tree.\n", tc);
		}
	}
    return 0;
}
