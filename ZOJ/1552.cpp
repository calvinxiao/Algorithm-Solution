/*
#Problem ID: 1552
#Submit Time: 2013-07-09 22:52:10
#Run Time: 0
#Run Memory: 304
#ZOJ User: calvinxiao
*/

/**
Calvin Xiao
calvin.xiao at scaurugby.com
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std ;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPN(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define REPI(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

char s[20007], t[20007];

int D(char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    else
        return c - 'A' + 10;
}

string DD(int a) {
    string ret = "  ";
    int b = a / 16;
    if (0 <= b && b <= 9)
        ret[0] = '0' + b;
    else
        ret[0] = 'A' + b - 10;
    b = a % 16;
    if (0 <= b && b <= 9)
        ret[1] = '0' + b;
    else
        ret[1] = 'A' + b - 10;
    return ret;
}

int e1[10003], e2[10003], k, c;
int main()
{
    //freopen("decode.in", "r", stdin);
    //freopen("decode.out", "w", stdout);
    while (~scanf("%s%s", s, t)) {
    	int n = strlen(s) / 2;
    	for (int i = 0; i < n; ++i) {
            e1[i] = D(s[i<<1]) * 16 + D(s[i<<1|1]);
    	}
    	for (int i = 0; i < n + 1; ++i) {
            e2[i] = D(t[i<<1]) * 16 + D(t[i<<1|1]);
    	}
    	c = 32;
    	string ans(n*2+2, ' ');
    	for (int i = 0; i < n+1; i++) {
            k = e2[i] ^ c;
            c = k ^ e1[i];
            string ret = DD(k);
            ans[i<<1] = ret[0];
            ans[i<<1|1] = ret[1];
    	}
        cout << ans << endl;
    }
    return 0;
}
