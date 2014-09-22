/*
#Problem ID: 1110
#Submit Time: 2013-04-12 22:48:47
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
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

int good(int S, int P, int Y, int s , int p, int y) {
	if (S - P - s <= 1 && S - P - s >= 0 && P - Y - p <= 1 && P - Y - p >= 0 && S - Y - y <= 1 && S - Y - y >= 0)
		return 1;
	return 0;
}

int main()
{
	//freopen("0.in", "r", stdin);
	int D = 12, J, S, P, Y, s, p, y;
	while (cin >> s >> p >> y >> J) {
		Y = (D + J - s - y) / 3;
		S = y + Y;
		P = p + Y;
		
		int found = 0;
		for (int ss = S - 2; ss <= S + 2; ++ss) if (!found)
			for (int pp = P - 2; pp <= P + 2; ++pp) if (!found)
				for (int yy = Y - 2; yy <= Y + 2; ++yy) if (!found)
					if (ss + pp + yy == D + J && good(ss, pp, yy, s, p, y)) {
						cout << ss << ' ' << pp << ' ' << yy << endl;
						found = 1;
						break;
					}


	}
    return 0;
}
