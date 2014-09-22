/*
#Problem ID: 2401
#Submit Time: 2012-12-05 11:42:35
#Run Time: 50
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

int n, m, x, y, x1[11], yy[11], x2[11], y2[11];
char  s1[202], s2[202], t[404];

int main()
{
	//freopen("0.in", "r", stdin);
	int TC, n1, n2, n3, i, j, k, dp[202][202];
	cin >> TC;
	for(int tc = 1; tc <= TC; ++tc) {
		scanf(" %s %s %s", s1+1, s2+1, t+1);
		n1 = strlen(s1+1);
		n2 = strlen(s2+1);
		n3 = strlen(t+1);
		//cout << n1 << ' ' << n2 << ' ' << n3 << endl;
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for(i = 0; i <= n1; ++i) {
			for(j = 0; j <= n2; ++j) {
				if(i) {
					dp[i][j] |= (s1[i] == t[i+j] && dp[i-1][j]);
				}
				if(j) {
					dp[i][j] |= (s2[j] == t[i+j] && dp[i][j-1]);
				}
			}
		}
		cout << "Data set " << tc << ": ";
		if(dp[n1][n2])
			cout << "yes\n";
		else
			cout << "no\n";
	}
    return 0;
}
