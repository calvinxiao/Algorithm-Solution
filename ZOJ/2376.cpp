/*
#Problem ID: 2376
#Submit Time: 2013-08-19 14:49:18
#Run Time: 40
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

const int MAX = 100;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    int tc, l, n, a, b, c;
    //cin >> tc; 
    tc = read_int();
    while (tc--) {
        //cin >> l >> n;
        l = read_int(); n = read_int();
        a = b = 0;
        for (int i = 0; i < n; ++i) {
            //cin >> c;
            c = read_int();
            a = max(a, min(c, l-c));
            b = max(b, max(c, l-c));
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}