/*
#Problem ID: 2510
#Submit Time: 2013-09-25 02:02:22
#Run Time: 20
#Run Memory: 264
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

const int N = 10005;
pair<int, int> p[N];

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
    int n;
    while (~scanf(" %d ", &n)) {
    	for (int i = 0; i < n; ++i)
    		p[i].second = read_int(), p[i].first = read_int();
    	sort(p, p+n);
    	reverse(p, p+n);
    	int yi = p[0].first, xi = p[0].second;
    	int sz = 1;
    	for (int i = 1; i < n; ++i) {
    		int yj = p[i].first, xj = p[i].second;
    		if (yj <= xi) {
    			xi = xj, yi = yj;
    			sz++;
    		} else if (xj >= xi)
    			xi = xj, yi = yj;
    		else
    			continue;
    	}
    	printf("%d\n", n - sz);
    }
    return 0;
}
