/*
#Problem ID: 3100
#Submit Time: 2012-10-24 16:08:19
#Run Time: 0
#Run Memory: 284
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
char s[100005], t[7];
int n, type;

int main()
{
	//freopen("0.in", "r", stdin);

	int n;
	int a[105];
	while(true) {
		cin >> n;
		if(!n) break;
		REP(i, n) cin >> a[i];
		sort(a, a + n);
		int sum = 0;
		REP(i, n - 2) sum += a[i + 1];
		cout << sum / (n - 2) << endl;
	}

    return 0;
}
