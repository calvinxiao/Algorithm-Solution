/*
#Problem ID: 2006
#Submit Time: 2014-05-19 09:27:27
#Run Time: 510
#Run Memory: 64224
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

int tc, n;
pair<string, int> s[10005];

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  cin >> tc;
  while (tc--) {
    string str; cin >> str;
    n = str.size();
    str += str;
    for (int i = 0; i < n; i++) {
      s[i].first = str.substr(i, n);
      s[i].second = i + 1;
    }
    sort(s, s + n);
    cout << s[0].second << endl;
  }
	return 0;
}
