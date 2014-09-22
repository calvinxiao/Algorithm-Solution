/*
#Problem ID: 1850
#Submit Time: 2012-10-11 17:51:20
#Run Time: 0
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

#define FOR(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

bool gao(int n, int m) {
	if(n == 1) {
		return true;
	}

	if(m == 0 || n == 0) return false;

	int sq = (int)(sqrt((double)n));
	//cout << sq << endl;
	map<int, int> dict;
	for(int i = 2; i <= sq; ++i) {
		if(n % i == 0) {
			dict[i] = dict[i] + 1;
			n /= i;
			i -= 1;
		}
	}

	if(n != 1) dict[n] = dict[n] + 1;

	for(map<int, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
		int start, k;
		start = k = it->first;
		int div = it->first;
		int cnt = it->second;
		while(start <= m && cnt > 0) {
			int g = start;
			while(g % div == 0) {
				g /= div;
				cnt --;
			}
			start += k;
		}

		if(cnt > 0) return false;
	}

	return true;
}

int main()
{
	int n, m;
	while(cin >> m >> n) {
		if(gao(n, m))
			cout << n << " divides " << m << '!' << endl;
		else
			cout << n << " does not divide " << m << '!' << endl;
	}
    return 0;
}
