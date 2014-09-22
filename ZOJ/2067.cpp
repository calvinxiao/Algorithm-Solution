/*
#Problem ID: 2067
#Submit Time: 2013-03-25 02:40:09
#Run Time: 810
#Run Memory: 268
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

const int MAX = 101;
int n, g[MAX][MAX], s[MAX][MAX], ans;
char c;

int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf("%d", &n)) {
        memset(g, 0, sizeof g);
        memset(s, 0, sizeof s);
        ans = 0;
        REPN(i, 1, n) REPN(j, 1, n) {
            scanf(" %c", &c);
            if (c == '#') { g[i][j] = 1;}
        }
        REPN(i, 1, n) REPN(j, 1, n)
            s[i][j] = s[i][j-1] + g[i][j];
        REPN(j, 1, n) REPN(i, 1, n)
            s[i][j] += s[i-1][j];

        ans = 0;
        REPN(a, 1, n) REPN(b, 1, n) REPN(c, a, n) REPN(d, b, n){
            int cnt = s[c][d] - s[c][b-1] - s[a-1][d] + s[a-1][b-1];
            if (!cnt) ans++;
            else
                break;
        }
        printf("%d\n", ans);

	}
    return 0;
}
