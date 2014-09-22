/*
#Problem ID: 3119
#Submit Time: 2012-05-23 02:07:27
#Run Time: 560
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<ctime>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<functional>
#include<bitset>
#include<memory.h>

using namespace std;

int main()
{
    int c, n;
    while(cin >> c)
    {
        cin >> n;

        int dp[n][n];

        memset(dp, 0, sizeof(dp));


        for(int i = 0 ; i < n; ++i)
        {
            for(int j = i; j < n; ++j)
            {
                cin >> dp[i][j];
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; ++j)
            {
                if(i==0) dp[i][j] = c + dp[i][j];
                else
                  dp[i][j]=(dp[i-1][i-1]+c+dp[i][j])<(dp[i-1][j])?(dp[i-1][i-1]+c+dp[i][j]):(dp[i-1][j]);
            }
        }


        cout<<dp[n-1][n-1]<<endl;
    }
    return 0;
}
