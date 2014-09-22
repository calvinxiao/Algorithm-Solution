/*
#Problem ID: 3310
#Submit Time: 2013-08-19 23:38:35
#Run Time: 110
#Run Memory: 9952
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


const int MAX = 1000002;
int dp[MAX][2], n, i, j;
short int h[MAX];

int first(int chosen) {
    dp[0][1] = chosen * h[0];
    dp[0][0] = 0;
    for (i = 1; i < n-1; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + h[i];
    }
    dp[n-1][1] = 0;
    if (!chosen)
        dp[n-1][1] = dp[n-2][0] + h[n-1];
    dp[n-1][0] = max(dp[n-2][0], dp[n-2][1]);
    return max(dp[n-1][0], dp[n-1][1]);
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (~scanf(" %d ", &n)) {
        for (i = 0; i < n; ++i)
            h[i] = read_int();
            //scanf("%d", h + i);
        if (n == 1)
            printf("%d\n", h[0]);
        else {
            int a = first(0), b = first(1);
            printf("%d\n", max(a, b));
        }
	}
    return 0;
}