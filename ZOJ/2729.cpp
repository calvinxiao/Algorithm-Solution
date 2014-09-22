/*
#Problem ID: 2729
#Submit Time: 2012-09-28 14:29:35
#Run Time: 30
#Run Memory: 324
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

#define FOR(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

int b[7070];
bool a[7070*16];
int n, m, sum;

int main()
{
	while(cin >> n && n != -1) {
		m = n * 16;

		for(int i = 0; i < n; ++i) cin >> b[i];

		memset(a, 0, sizeof a);

		int k = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < 16; ++j) {
				if(b[i] & (1 << j)) {
					a[k + 15 - j] = true;
				}
			}
			k += 16;
		}

		/*
		for(int i = 0; i < m; ++i)
			if(a[i]) cout << 1;
			else	 cout << 0;
		cout << endl;
		*/

		sum = 0;
		for(int i = 0; i < m; i += 7) {
			int temp = 0;
			for(int j = 1; j < 7; ++j) {
				temp *= 2;
				temp += (a[i + j]);
			}
			if(a[i]) temp = -temp;
			sum += temp;
		}

		cout << sum << endl;

	}

	return 0;
}
