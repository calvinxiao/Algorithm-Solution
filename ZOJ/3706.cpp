/*
#Problem ID: 3706
#Submit Time: 2014-04-10 12:27:49
#Run Time: 10
#Run Memory: 272
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

int find(int a, int b)
{
	int ans = 0;
	for (int i = 0; i < a; i++) {
		int j = a - i;
		set<int> s;
		s.insert(a);
		s.insert(b);
		s.insert(a + b);
		s.insert(i);
		s.insert(j);
		int t;
		t = abs(i - b);
			s.insert(t);
		t = abs(j - b);
			s.insert(t);
		t = abs(i + b);
			s.insert(t);
		t = abs(j + b);
			s.insert(t);
		t = abs(i - j - b);
			s.insert(t);
		t = abs(j - i - b);
			s.insert(t);
		t = abs(i + j - b);
			s.insert(t);
    t = abs(i - j);
			s.insert(t);
    s.erase(0);
		if ((int)s.size() > ans)
			ans = (int)s.size();
	}
	return ans;
}

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
	int tc; cin >> tc;
	while (tc--) {
		int a, b; cin >> a >> b;
		cout << max(find(a, b), find(b, a)) << endl;
	}
	return 0;
}
