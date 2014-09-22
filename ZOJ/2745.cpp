/*
#Problem ID: 2745
#Submit Time: 2012-08-01 03:03:30
#Run Time: 10
#Run Memory: 292
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<memory.h>
using namespace std;
long long dp[111][11][11];
long long N,K,temp;
inline void init() {
    memset(dp,0,sizeof(dp));
    dp[1][1][0]=1;
    dp[1][0][1]=1;
}
void dpstart() {
    init();
    for(int i=2; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            dp[i][0][j]=dp[i-1][1][j-1]+dp[i-1][0][j-1];
            dp[i][j][0]=dp[i-1][j-1][1]+dp[i-1][j-1][0];
        }
        for(int x=1; x<K; x++) {
            for(int y=1; y<K; y++) {
                dp[i][x][y]=dp[i-1][x+1][y-1]+dp[i-1][x-1][y+1];
            }
        }
        for(int j=1; j<K; j++) {
            dp[i][K][j]=dp[i-1][K-1][j+1];
            dp[i][j][K]=dp[i-1][j+1][K-1];
        }
    }
    temp=0;
    for(int i=0; i<=K; i++) {
        for(int j=0; j<=K; j++) {
            temp+=dp[N][i][j];
        }
    }
    cout<<temp<<endl;
    return ;
}
int main() {
    while(cin>>N>>K) {
        dpstart();
    }
    return 0;
}
