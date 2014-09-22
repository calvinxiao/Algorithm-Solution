/*
#Problem ID: 2975
#Submit Time: 2012-08-06 01:25:47
#Run Time: 130
#Run Memory: 432
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int MAX = 251;
int g[MAX][MAX];
int N, M;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                char t;
                cin >> t;
                if(t == 'B') g[i][j] = 0;
                if(t == 'J') g[i][j] = 1;
                if(t == 'H') g[i][j] = 2;
                if(t == 'Y') g[i][j] = 3;
                if(t == 'N') g[i][j] = 4;
                //cout << g[i][j];
            }
            //cout << endl;
        }

        int sum = 0;
        for(int i = 0; i < M - 1; ++i) {
            for(int j = i + 1; j < M; ++j) {
                //count how many same row...
                bool vis[5] = {0, 0, 0, 0, 0};
                int dp[5] = {0, 0, 0, 0, 0};
                for(int k = 0; k < N; ++k) {
                    if(g[k][i] == g[k][j]) dp[g[k][i]] += 1;
//                    if(!vis[g[k][i]] && g[k][i] == g[k][j]) {
//                        int t = g[k][i];
//                        vis[t] = true;
//                        int cnt = 1;
//                        for(int p = k + 1; p < N; ++p) {
//                            if(g[p][i] == t && g[p][j] == t) cnt += 1;
//                        }
//
//                        if(cnt > 1) {
//                            sum += cnt * (cnt - 1) / 2;
//                        }
//                        //cout << cnt << ' ' << sum<< endl;
//                    }
                    //cout << g[k][i] << g[k][j] << endl;
                    //cout << i << ' ' << j << ' ' << k << ' ' << cnt << endl;
                }

                for(int p = 0; p < 5; ++p) {
                    if(dp[p] > 1) sum += dp[p] * (dp[p] - 1)  / 2;
                }

            }
        }

        cout << sum << endl;
    }
    return 0;
}
