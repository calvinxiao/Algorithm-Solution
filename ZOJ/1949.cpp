/*
#Problem ID: 1949
#Submit Time: 2013-05-27 16:41:33
#Run Time: 0
#Run Memory: 236
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 100;

int n, g[111][111];

int main()
{
	//freopen("0.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n) && n) {
        REP(i, n) REP(j, n) scanf("%d", &g[i][j]);
        int r = -1, c = -1;
        REP(i, n) {
            int s = 0;
            REP(j, n) s ^= g[i][j];
            if (s) {
                if (r == -1)
                    r = i;
                else
                    r = 999;
            }
        }

        REP(j, n) {
            int s = 0;
            REP(i, n) s ^= g[i][j];
            if (s) {
                if (c == -1)
                    c = j;
                else
                    c = 999;
            }
        }

        if (r == -1 && c == -1) {
            puts("OK");
        } else if (r != -1 && r != 999 && c != -1 && c != 999) {
            printf("Change bit (%d,%d)\n", r+1, c+1);
        } else
            puts("Corrupt");

	}
    return 0;
}
