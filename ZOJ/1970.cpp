/*
#Problem ID: 1970
#Submit Time: 2013-05-27 14:34:29
#Run Time: 0
#Run Memory: 404
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

int max(int a, int b) {
    if (a < b)
         a = b;
    return a;
}

char s[111111], t[111111];

int main()
{
	//freopen("0.in", "r", stdin);
	s[0] = t[0] = ',';
	while (~scanf(" %s %s", s, t)) {
        int n = strlen(s);
        int m = strlen(t);
        int cnt = 0, j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i])
                j++;
            if (s[i] == t[j]) {
                cnt++; j++;
            }
        }
        if (cnt == n)
            puts("Yes");
        else
            puts("No");
	}
    return 0;
}
