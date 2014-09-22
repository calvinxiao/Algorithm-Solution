/*
#Problem ID: 1149
#Submit Time: 2012-07-03 16:33:14
#Run Time: 0
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdio>
#include<memory.h>
using namespace std;
int a[37];
int b[6];
int main()
{
    int CASE = 0;
    while(1) {
        CASE ++;
        bool ok = false;
        int S = 0;
        int T = 0;
        int idx = 0;
        int n;
        cin>>b[0]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5];
        for(int i = 0; i < 6; ++i) {
            if(b[i] == 0) continue;
            if(b[i] % 6 != 0) b[i] %= 6;
            else b[i] = 6;
            ok = true;
            for(int j = 0; j < b[i]; ++j) {
                a[idx++] = i + 1;
                S += i + 1;
                //cout<<i + 1<<" ";
            }
        }
        //cout<<endl;
        n = idx;
        if(!ok) break;
        if(S % 2 == 1) {
            printf("Collection #%d:\nCan't be divided.\n\n", CASE);
            continue;
        }

        T = S / 2 + 1;
        bool dp[n][T];
        bool found = false;
        memset(dp, 0, sizeof dp);
        dp[0][0] = true;

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < T ; ++j) {
                if ( j >= a[i] && dp[i - 1][j - a[i]]) dp[i][j] = true;
                if ( dp[i-1][j] ) dp[i][j] = true;
                //cout<<j<<" "<<dp[j]<<endl;
            }

            if ( dp[i][T-1] ) {
                found = true;
                break;
            }
        }

        if(found) {
            printf("Collection #%d:\nCan be divided.\n\n", CASE);
        } else {
            printf("Collection #%d:\nCan't be divided.\n\n", CASE);
        }

    }


    return 0;
}
