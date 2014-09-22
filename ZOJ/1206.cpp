/*
#Problem ID: 1206
#Submit Time: 2012-09-04 11:39:02
#Run Time: 180
#Run Memory: 4096
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
const int MAX = 10001;
int N, M,n, m, i, j, k, dp[MAX][10][10], p[1000], maxI, maxJ;


int main()
{
    while(scanf(" %d%d", &M, &N) != EOF) {
        //memset(dp, 0, sizeof dp);
        for(n = 2; n < N; ++n)
            for(i = 0; i < 10; ++i)
                for(j = 0; j < 10; ++j) {
                    dp[n][i][j] = -100000000;
                }

        memset(p, 0, sizeof p);
        for(i = 0; i < M; ++i) {
            //cin >> j >> k;
            scanf(" %d%d", &j, &k);
            p[j] = k;
        }

        for(n = 2; n < N; ++n) {
            for(i = 0; i < 10; ++i) {
                for(j = 0; j < 10; ++j) {
                    for(k = 0; k < 10; ++k) {
                        if(dp[n][i][j] < dp[n-1][j][k] + p[i*100 + j * 10 + k]) {
                            dp[n][i][j] = dp[n-1][j][k] + p[i*100 + j * 10 + k];
                        }
                        //cout << n << ' ' << i << ' ' << j << ' ' << dp[n][i][j] << endl;
                    }

                }
            }
        }

        int MAX = -1000000000;
        for(i = 0; i < 10; ++i)
        for(j = 0; j < 10; ++j)
            if(dp[N-1][i][j] > MAX)
                maxI = i, maxJ = j, MAX = dp[N-1][i][j];

        for(n = N - 1; n > 1; --n) {
            //cout << maxI;
            printf("%d", maxI);
            for(k = 0; k < 10; ++k)
            if(dp[n][maxI][maxJ] == dp[n-1][maxJ][k] + p[maxI * 100 + maxJ * 10 + k]) {
                maxI = maxJ; maxJ = k;
                break;
            }
        }
        cout << maxI << maxJ << endl;

    }
    //cout << 0 << endl;
    return 0;
}
