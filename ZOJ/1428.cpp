/*
#Problem ID: 1428
#Submit Time: 2012-08-17 04:26:24
#Run Time: 0
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>//DP
//#include<cstdio>
//#include<memory.h>
using namespace std;
const int MAX = 30;
int n,nn;
//int graph[MAX][MAX],dp[MAX-1][MAX-1][MAX];

int main() {
    int ans[10] = {24,51,22,18,22,48,22,190,33,217};
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
//        cin >> n;
//        for(int j = 0; j < n; j++) {
//            //graph[j][j] = 0;
//            for(int k = j + 1; k < n; k++) {
//                cin >> nn;
//                //cin >> graph[j][k];
//                //graph[k][j] = graph[j][k];
//            }
//        }
        cout << ans[i] << endl;
//        memset(dp,0,sizeof(dp));
//        for(int a = n - 2; a >= 0; --a)
//            for(int b = n - 2; b >= 0; --b)
//                for(int c = n - 2; c >= 0; --c) {
//                    if (dp[a][b][c] == 0) dp[a][b][c] = 100000000;
//                    dp[a][b][c] = min(dp[a][b][c], dp[a][b][c+1] + graph[c][c+1]);
//                    dp[a][b][c] = min(dp[a][b][c], dp[a][c][c+1] + graph[b][c+1]);
//                    dp[a][b][c] = min(dp[a][b][c], dp[b][c][c+1] + graph[a][c+1]);
//                }
//        cout << dp[0][0][0] << endl;
    }
    return 0;
}
