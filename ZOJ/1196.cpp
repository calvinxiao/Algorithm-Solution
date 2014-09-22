/*
#Problem ID: 1196
#Submit Time: 2012-07-13 23:19:36
#Run Time: 0
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cmath>
#include<cstdio>
#include<memory.h>
using namespace std;
const int MAX = 2100000000;

int main()
{
    int n, k, i, j, t, caseCnt = 1;
    int p[200], dp[200][31], ad[200][200];

    while(scanf("%d%d", &n, &k) != EOF)
    {
        if(n == 0 && k == 0) break;

        for(i = 0; i < n; i++)
            scanf("%d", &p[i]);

        memset(ad, 0, sizeof(ad));

        for(i = 0; i < n; i++)
            for(j = 2; j <= k; j++)
                dp[i][j] = MAX;



        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                int mid = (i + j) / 2;
                for(t = i; t < mid; t++)
                    ad[i][j] += p[mid] - p[t];
                for(t = mid+1; t <= j; t++)
                    ad[i][j] += p[t] - p[mid];
            }
        }

        for(i = 0; i < n; i++)
            dp[i][1] = ad[0][i];

        for(j = 2; j <= k; j++)
            for(i = j-1; i < n; i++)
                for(t = 0; t < i; t++)
                    dp[i][j] = min(dp[i][j], dp[t][j-1]+ad[t+1][i]);

        printf("Chain %d\nTotal distance sum = %d\n\n", caseCnt++, dp[n-1][k]);
    }

    return 0;
}
