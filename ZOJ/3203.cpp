/*
#Problem ID: 3203
#Submit Time: 2013-02-02 22:02:28
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
const double eps = 1e-10;

int T;
double H, h, D, d, dd1, dd2, ansL, ansR, ans, L, R, LT, RT;

double func1(double x) {
	return H * x / (H - h);
}

// len of shadow
double func2(double x) {
	return (x - D) * H / x;
}

double func3(double x) {
	if (D - x > eps) return x;
	else return D + func2(x);
}

int main()
{
	//freopen("0.in", "r", stdin);
	cin >> T;
	while(T--) {
		cin >> H >> h >> D;
		L = 0.0, R = D;
		ans = 0.0;
		for (int search = 0; search < 50; ++search) {
			if (R - L < eps) break;

			LT = (L * 2.0 + R) / 3.0;
			RT = (L + R * 2.0) / 3.0;
			dd1 = func1(LT);
			dd2 = func1(RT);
			ansL = func3(dd1) - LT;
			ansR = func3(dd2) - RT;
			//cout << LT << ' ' << RT << ' ' << ansL << ' ' << ansR << endl;
			ans = max(ans, ansL);
			ans = max(ans, ansR);
			if (ansL > ansR)
				R = RT;
			else
				L = LT;
		}

		printf("%.3f\n", ans);
	}
    return 0;
}
