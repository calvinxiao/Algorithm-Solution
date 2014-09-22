/*
#Problem ID: 2857
#Submit Time: 2012-09-09 22:56:13
#Run Time: 20
#Run Memory: 224
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
int g[100][100];
int tc, n, m, temp;
int main()
{

    //cout<<dp[0][0]<<endl;
    while(1) {
        tc += 1;
        cin >> n >> m;
        if(!n && !m) break;

        memset(g, 0, sizeof g);

        for(int k = 0; k < 3; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    cin >> temp;
                    g[i][j] += temp;
                }
            }
        }

        printf("Case %d:\n", tc);
        for(int i = 0; i < n; ++i) {
            cout << g[i][0] / 3;
            for(int j = 1; j < m; ++j) {
                cout << ',' << g[i][j] / 3;
            }
            cout << endl;
        }

    }
    return 0;
}
