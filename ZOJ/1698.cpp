/*
#Problem ID: 1698
#Submit Time: 2012-10-25 01:56:47
#Run Time: 0
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

using namespace std;

const int MAX = 100;

bool isV(char c) {
	string v = "aeiou";
	REP(i, v.size()) if (c == v[i]) return true;
	return false;
}

bool AC(string s) {
	int n = s.size();
	bool good = false;
	REP(i, n) if(isV(s[i])) good = true;
	if(!good) return false;
	for(int i = 0; i + 3 <= n; ++i) {
		int cnt1 = 0, cnt2 = 0;
		REP(j, 3)
			if(isV(s[i+j]))
				cnt1 += 1;
			else
				cnt2 += 1;
		if(cnt1 == 3 || cnt2 == 3) return false;
	}
	REP(i, n-1) {
		if(s[i] != 'e' && s[i] != 'o' && s[i] == s[i+1])
			return false;
	}

	return true;
}

int main()
{
	//freopen("0.in", "r", stdin);
	string s;
	while (cin >> s) {
		if (s == "end") break;
		if(AC(s)) 
			printf("<%s> is acceptable.\n", s.c_str());
		else
			printf("<%s> is not acceptable.\n", s.c_str());
	}
    return 0;
}
