/*
#Problem ID: 1133
#Submit Time: 2013-04-12 22:08:34
#Run Time: 30
#Run Memory: 228
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
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 100;

int prime[11111];
vector<int> p;
int n;

int d(int b) {
	int ret = 0;
	while (b) {
		ret += b % 10; 
		b /= 10;
	}
	return ret;
}

int gao(int a) {
	if (a < 11111 && !prime[a]) return 0; // confusing, eh?
	int o1 = 0, o2 = 0, aa = a;
	for (int i = 0; i < p.size() && aa > p[i]; ++i) {
		while (aa && aa % p[i] == 0) {
			aa /= p[i];
			o1 += d(p[i]);
		}
	}
	if (aa == a)
		return 0;
	if (aa > 1)
		o1 += d(aa);

	o2 = d(a);

	return o1 == o2;
}

int main()
{
	//freopen("0.in", "r", stdin);
	p.push_back(2);
	prime[0] = prime[1] = 1;
	for (int i = 4; i < 11111; i += 2)
		prime[i] = 1;
	for (int i = 3; i < 11111; i += 2) {
		if (!prime[i]) {
			p.push_back(i);
			for (int j = i + i; j < 11111; j += i)
				prime[j] = 1;
		}
	}
	while (scanf("%d", &n) && n) {
		for (int i = n + 1; ; i++) {
			int ret = gao(i);
			if (ret) {
				printf("%d\n", i);
				break;
			}
		}
	}
    return 0;
}
