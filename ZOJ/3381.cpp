/*
#Problem ID: 3381
#Submit Time: 2013-09-27 16:06:25
#Run Time: 240
#Run Memory: 1552
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

const int N = 50005;

int t[N<<2], S[N], X[N], Y[N], n;
int L, R;

void modify(int x, int l, int r, int rt) {
	if (L <= l && r <= R) {
		t[rt] = x;
		return;
	}
	int mid = l + r >> 1;
	if (L <= mid) modify(x, l, mid, rt << 1);
	else if (mid < R) modify(x, mid + 1, r, rt << 1 | 1);
	t[rt] = max(t[rt << 1], t[rt << 1 | 1]);
	return;
}

int what(int l, int r, int rt) {
	if (L <= l && r <= R)
		return t[rt];
	int mid = l + r >> 1;
	int t1 = 0, t2 = 0;
	if (L <= mid) t1 = what(l, mid, rt << 1);
	if (mid < R)  t2 = what(mid + 1, r, rt << 1 | 1);
	return max(t1, t2);
}

inline int read_int(){
    int a=0;
    int b=1,c=getchar();
    if(c=='-')b=-1;
    else a=c-48;
    while((c=getchar())!=' '&&c!='\n')
        a=a*10+c-48;
    a*=b;
    return a;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    while (~scanf(" %d ", &n)) {
    	//REP(i, n) scanf("%d%d%d", S+i+1, X+i+1, Y+i+1);
    	REP(i, n) {
    		S[i+1] = read_int();
    		X[i+1] = read_int();
    		Y[i+1] = read_int();
    	}
	    memset(t, 0, sizeof t);
	    for (int i = n; i >= 1; i--) {
	    	int t1 = S[i];
	    	if (i + X[i] <= n) {
	    		L = i + X[i];
	    		R = i + Y[i] - 1;
	    	  t1 += what(1, n, 1);
	    	}
	    	L = R = i;
	    	modify(t1,1, n, 1);
	    }
	    L = R = 1;
	    printf("%d\n", what(1, n, 1));
    }

    return 0;
}
