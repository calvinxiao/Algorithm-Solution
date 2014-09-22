/*
#Problem ID: 1183
#Submit Time: 2012-07-05 23:05:06
#Run Time: 380
#Run Memory: 4100
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
int dp[1001][1001];
const int MAX = 2000000000;
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int n, l, c, t[1001], T = 0;
        cin>>n;
        while(n)
        {
            cin>>l>>c;
            for(int i = 1; i <= n; ++i)cin>>t[i];
            for(int i = 0; i <= n; ++i)
                for(int j = 0; j <= n; ++j)
                    dp[i][j] = MAX;
            dp[0][0] = 0;
            int i;
            for(i = 0; i <= n; ++i)
            {
                if(dp[i][n] != MAX)break;
                for(int j = i; j <= n; ++j)
                {
                    if(dp[i][j] == MAX)break;
                    int lec = l;
                    for(int k = j + 1; k <= n; ++k)
                    {
                        lec -= t[k];
                        if(lec < 0)break;
                        if(lec == 0)
                        {
                            if(dp[i + 1][k] > dp[i][j])
                                dp[i + 1][k] = dp[i][j];
                        }
                        else if(lec >= 1 && lec <= 10)
                        {
                            if(dp[i + 1][k] > dp[i][j] - c)
                                dp[i + 1][k] = dp[i][j] - c;
                        }
                        else if(lec > 10)
                        {
                            int ll = dp[i][j] + (lec - 10) * (lec - 10);
                            if(dp[i + 1][k] > ll)
                                dp[i + 1][k] = ll;
                        }

                    }
                }
            }
            cout<<"Case "<<++T<<":\n"<<endl;
            cout<<"Minimum number of lectures: "<<i<<endl;
            cout<<"Total dissatisfaction index: "<<dp[i][n]<<endl;
            cin>>n;
            if(n)cout<<endl;
        }
        if(N)cout<<endl;
    }
    return 0;
}