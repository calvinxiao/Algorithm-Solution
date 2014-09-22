/*
#Problem ID: 3326
#Submit Time: 2014-01-01 18:43:52
#Run Time: 0
#Run Memory: 1040
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

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
	int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	vector<int> days;
	for (int year = 1000; year <= 2999; year++) {
		int leap = 0;
		if (year % 4 == 0) {
      if (year % 100 == 0) {
        if (year % 400 == 0)
          leap = 1;
      } else
        leap = 1;
		}
		for (int i = 0; i < 11; i++) {
			int month = prime[i];
			if (month > 11)
				break;
			for (int j = 0; j < 11; j++) {
				int day = prime[j];
				if (month == 2) {
					if (leap && day > 29) break;
					if (!leap && day > 28) break;
				}
				if (day > 30 && month != 1 && month != 3 && month != 5 && month != 7 && month != 8 && month != 10 && month != 12)
					break;
				days.push_back(year * 10000 + month * 100 + day);
			}
		}
	}
	int t; cin >> t;
	while (t--) {
		int y, m, d;
		cin >> y >> m >> d;
		vector<int>::iterator it1, it2;
		it1 = lower_bound(days.begin(), days.end(), y*10000+m*100+d);
		cin >> y >> m >> d;
		it2 = upper_bound(days.begin(), days.end(), y*10000+m*100+d);
		cout << it2 - it1 << endl;
	}
	return 0;
}
