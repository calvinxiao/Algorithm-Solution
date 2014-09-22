/*
#Problem ID: 2346
#Submit Time: 2013-06-28 20:56:55
#Run Time: 190
#Run Memory: 23624
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

int t[30][100000], p[30][100000], idx;

void put(int root, string &s, int si) {
    if (si == s.size())
        return;
    t[s[si]-'a'][root]++;
    if (p[s[si]-'a'][root] == 0)
        p[s[si]-'a'][root] = ++idx;
    int next = p[s[si]-'a'][root];
    put(next, s, si+1);
}

int get(int root, string &s, int si) {
    if (si == s.size())
        return si;
    if (t[s[si]-'a'][root] == 1)
        return si+1;
    return get(p[s[si]-'a'][root], s, si+1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
	#endif
	int tc;
	string s;
	cin >> tc;
	getchar();
	getline(cin, s);
	for (int qq = 0; qq < tc; ++qq) {
        if (qq)
            cout << endl;
        memset(t, 0, sizeof t);
        memset(p, 0, sizeof p);
        idx = 0;
        vector<string> ls;

        while (1) {
            getline(cin, s);
            //cout << s << endl;
            if (s.size() == 0)
                break;
            ls.push_back(s);
        }

        for (int i = 0; i < ls.size(); ++i) {
            put(0, ls[i], 0);
        }

        for (int i = 0; i < ls.size(); ++i) {
            int len = get(0, ls[i], 0);
            cout << ls[i] << ' ' << ls[i].substr(0, len) << endl;
        }

	}
    return 0;
}
