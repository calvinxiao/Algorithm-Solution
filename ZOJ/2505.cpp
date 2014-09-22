/*
#Problem ID: 2505
#Submit Time: 2012-11-14 11:52:47
#Run Time: 1660
#Run Memory: 204
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

const int MAX = 4096;
int a[MAX];

int main()
{
	//freopen("0.in", "r", stdin);
	int t, n, b, c;
	cin >> t;
	while(t--) {
		memset(a, 0, sizeof a);
		cin >> n;
		int maxcnt = 0;
		while(n--) {
			cin >> b;
			a[b-1] ^= 1;
			int cnt = 0;
			for(int i = 0; i < MAX; ++i) {
				if(a[i]) {
					cnt += 1;
					if(maxcnt < cnt) maxcnt = cnt;

				}
				else
					cnt = 0;
			}
		}
		
		cout << maxcnt << endl;
	}
    return 0;
}
