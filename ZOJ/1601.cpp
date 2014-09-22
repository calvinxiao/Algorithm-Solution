/*
#Problem ID: 1601
#Submit Time: 2012-10-25 01:42:37
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
	double A, MIN;
	int N, D, L;
	int ansN, ansD;
	while (cin >> A >> L) {
		MIN = 10000000.0;
		for (D = 1; D <= L; ++D) {
			N = D * A;
			if (N > L) N = L;
			if (N == 0) N = 1;
			int temp = N;
			for(N = temp; N < temp + 2; ++N)
				if(1 <= N && N <= L) {
					double newA = 1.0 * N / D;
					if(MIN > fabs(newA - A)) {
						MIN = fabs(newA - A);
						ansN = N;
						ansD = D;
					}
				}
		}
		cout << ansN << ' ' << ansD << endl;
	}
    return 0;
}
