/*
#Problem ID: 1092
#Submit Time: 2013-03-15 11:35:54
#Run Time: 50
#Run Memory: 268
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

int n, m, idx, cnt[MAX], inq[MAX];
double g[MAX][MAX], cash[MAX], rate;
map<string, int> dict;
string s, t;
bool bad;
int tc;

void check(int u) {
    memset(cnt, 0, sizeof cnt);
    memset(inq, 0, sizeof inq);
    memset(cash, 0, sizeof cash);
    queue<int> q;
    q.push(u); cash[u] = 1.0;
    while (!q.empty() && !bad) {
        int f = q.front(); q.pop(); inq[f] = 0;
        //cout << f << ' ' << cash[f] << endl;
        REP(v, n) {
            double newrate = cash[f] * g[f][v];
            if (newrate > cash[v]) {
                cnt[v]++;
                if (cnt[v] > n) {
                    bad = true;
                    break;
                }
                cash[v] = newrate;
                if (!inq[v]) {
                    q.push(v); inq[v] = 1;
                }
            }
        }
    }
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (cin >> n && n) {
        tc++;
        idx = 0;
        dict.clear();
        bad = false;
        memset(g, 0, sizeof g);
        REP(i, n) {
            cin >> s;
            dict[s] = idx++;
        }
        cin >> m;
        REP(i, m) {
            cin >> s >> rate >> t;
            g[dict[s]][dict[t]] = rate;
        }
        REP(i, n) if (!bad) {
            check(i);
        }
        cout << "Case " << tc << ": ";
        if (bad)
            cout << "Yes\n";
        else
            cout << "No\n";
	}
    return 0;
}
