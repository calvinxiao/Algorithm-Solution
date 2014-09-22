/*
#Problem ID: 3600
#Submit Time: 2013-03-07 22:56:02
#Run Time: 0
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPN(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)

int old(double d, double t) {
	double ret = 10;
	if (d > 3.0) {
		d -= 3.0;
		if (d < 7.0) ret += d * 2;
		else {
			ret += 7.0 * 2 + (d-7.0) * 3;
		}
	}
	ret += t / 5 * 2 + 1;
	return (int)(ret + 0.5);
}

int NEW(double d, double t) {
	double ret = 11;
	if (d > 3.0) {
		d -= 3.0;
		if (d < 7.0) ret += d * 2.5;
		else {
			ret += 7.0 * 2.5 + (d-7.0) * 3.75;
		}
	}
	ret += t / 4 * 2.5;
	return (int)(ret + 0.5);
}
int main()
{
    //freopen("0.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		double d ,t; scanf("%lf%lf", &d, &t);
		printf("%d\n", NEW(d, t) - old(d, t));
	}
    return 0;
}