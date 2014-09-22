/*
#Problem ID: 2480
#Submit Time: 2012-12-05 09:19:51
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

int n, m, x, y, x1[11], yy[11], x2[11], y2[11];

int main()
{
	//freopen("0.in", "r", stdin);
	while(1) {
		cin >> n;
		if(!n) break;
		REP(i, n) cin >> x1[i] >> yy[i] >> x2[i] >> y2[i];
		cin >> m;
		REP(mm, m) {
			cin >> x >> y;
			int found = 0;
			for(int i = n-1; i >= 0; --i) {
				if(x1[i] <= x && x <= x2[i] && yy[i] <= y && y <= y2[i]) {
					cout << i << endl;
					// int tx1 = x1[i], tx2 = x2[i], ty1 = yy[i], ty2 = y2[i];
					// for(int j = i; j < n-1; ++j) {
					// 	x1[j] = x1[j+1];
					// 	x2[j] = x2[j+1];
					// 	yy[j] = yy[j+1];
					// 	y2[j] = y2[j+1];
					// }
					// x1[n-1] = tx1;
					// x2[n-1] = tx2;
					// yy[n-1] = ty1;
					// y2[n-1] = ty2;
					found = 1;
					break;
				}

			}

			if(!found) 
				cout << -1 << endl;
			
		}
	}
    return 0;
}
