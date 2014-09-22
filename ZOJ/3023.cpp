/*
#Problem ID: 3023
#Submit Time: 2012-10-24 18:06:52
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

int main()
{
	//freopen("0.in", "r", stdin);
	int n, m;
	int a[105], b[105];
	while(1) {
		cin >> n >> m;
		if(!n && !m) break;

		int suma = 0, sumb = 0;
		REP(i, n) cin >> a[i], suma += a[i];
		REP(i, m) cin >> b[i], sumb += b[i];

		sort(a, a + n); sort(b, b + m);

		int sa = 1000, sb = 1000;
		REP(i, n) REP(j, m) {
			if(suma - a[i] + b[j] == sumb - b[j] + a[i])
				if(a[i] + b[j] < sa + sb) {
					sa = a[i];
					sb = b[j];
				}
		}

		if(sa == 1000) cout << -1 << endl;
		else cout << sa << ' ' << sb << endl;
	}
    return 0;
}
