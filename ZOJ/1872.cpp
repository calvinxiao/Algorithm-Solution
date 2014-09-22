/*
#Problem ID: 1872
#Submit Time: 2012-09-08 01:22:34
#Run Time: 0
#Run Memory: 268
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<memory.h>
using namespace std;
const int MAX = 101;
double d[MAX][MAX], x[MAX], y[MAX], ans, MIN;
int f[MAX], n, i, j, k, ti, tj;

int main()
{

    //cout<<dp[0][0]<<endl;
    while( cin >> n) {
        ans = 0.0;
        for(i = 0; i < n; ++i) f[i] = i;
        for(i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }

        for(i = 0; i < n; ++i)
        for(j = i + 1; j < n; ++j) {
            d[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) );
            d[j][i] = d[i][j];
        }

        for(k = 0; k < n - 1; ++k) {
            MIN = 999999999.0;
            for(i = 0; i < n; ++i) {
                for(j = i + 1; j < n; ++j) {
                    while(f[f[i]] != f[i]) f[i] = f[f[i]];
                    while(f[f[j]] != f[j]) f[j] = f[f[j]];

                    if(f[i] != f[j]) {
                        if(d[i][j] < MIN) {
                            ti = i;
                            tj = j;
                            MIN = d[i][j];
                        }
                    }

                }
            }
            //cout << MIN << endl;
            ans += MIN;
            f[f[ti]] = f[tj];
        }

        printf("%.2f\n", ans);

    }
    return 0;
}
