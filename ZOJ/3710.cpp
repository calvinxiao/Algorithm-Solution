/*
#Problem ID: 3710
#Submit Time: 2013-08-19 14:46:53
#Run Time: 90
#Run Memory: 236
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


int N, M, K, g[111][111], tc;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    scanf("%d", &tc);
    while (tc--) {
        scanf(" %d %d %d ", &N, &M, &K);
        memset(g, 0, sizeof g);
        REP(i, M) {
            int a, b;
            //scanf("%d%d", &a, &b);
            a = read_int(); b = read_int();
            g[a][b] = g[b][a] = 1;
        }
        int cnt = 0, ans = 0, yes = 1;
        while (yes) {
            yes = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    if (!g[i][j]) {
                        cnt = 0;
                        for (int k = 0; k < N; ++k) {
                            if (g[i][k] && g[j][k])
                                cnt++;
                        }
                        if (cnt >= K) {
                            g[i][j] = g[j][i] = 1;
                            ans++;
                            yes = 1;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}