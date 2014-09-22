/*
#Problem ID: 2297
#Submit Time: 2012-10-22 11:52:56
#Run Time: 290
#Run Memory: 4284
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

int c[22], r[22], n, p;
int dp[1<<20];

int main()
{
	while(cin >> n) {
		n -= 1;
		REP(i, n) cin >> c[i] >> r[i];
		cin >> p;
		
		memset(dp, 255, sizeof dp);
		//cout << dp[0] << dp[1] << endl;
		dp[0] = 100;
		REP(i, 1 << n) {
			if(dp[i] != -1)
			REP(j, n) {
				if(~i & (1<<j)) {
					int temp = dp[i] - c[j];
					if(temp < 0) continue;
					temp += r[j];
					if(temp > 100) temp = 100;
					if(dp[i | (1<<j)] < temp) dp[i | (1<<j)] = temp;
				}
			}
		}
		//cout << dp[(1<<n) - 1] << endl;
		if(dp[(1<<n) - 1] >= p)
			cout << "clear!!!\n";
		else
			cout << "try again\n";
	}
    return 0;
}
