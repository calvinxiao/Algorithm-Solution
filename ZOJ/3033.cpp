/*
#Problem ID: 3033
#Submit Time: 2012-11-15 16:17:59
#Run Time: 1380
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
const long long BIG = 100000000000000LL;
int main()
{
	//freopen("0.in", "r", stdin);
	int p, n, I, F, m, a, b;
	long long c, mini[301][301];
	cin >> p;
	for(int pp = 0; pp < p; ++pp) {
		cin >> n >> I >> F >> m;
		for(int i = 0; i < n; ++i) 
			for(int j = 0; j < n; ++j) {
				mini[i][j] = BIG;
				//maxi[i][j] = -100000000000000LL;
			}

		for(int i = 0; i < m; ++i) {
			cin >> a >> b >> c;
			mini[a][b] = c;
		}

		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				if(mini[i][k] != BIG)
				for(int j = 0; j < n; ++j) if(mini[k][j] != BIG){
					if(mini[i][k] + mini[k][j] < mini[i][j]) mini[i][j] = mini[i][k] + mini[k][j];
					//if(maxi[i][k] + maxi[k][j] > maxi[i][j]) maxi[i][j] = maxi[i][k] + maxi[k][j];
				}

		if(mini[I][F] == BIG) {
			cout << "infinity\n";
			continue;
		}

		long long ans = mini[I][F];
		for(int i = 0; i < n; ++i)
			if(mini[i][i] < 0LL) {
				ans = BIG;
				break;
			}
		//cout << mini[1][1] << endl;
		if(ans == BIG) {
			cout << "infinity\n";
			continue;
		}
		cout << ans << endl;
	}
    return 0;
}
