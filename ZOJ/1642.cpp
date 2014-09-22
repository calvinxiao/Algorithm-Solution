/*
#Problem ID: 1642
#Submit Time: 2012-08-04 03:33:20
#Run Time: 90
#Run Memory: 15748
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
const int MAX = 100001;
int N;
string s1, s2;
int n, m;
int score[256];
int main()
{
    while(cin >> N) {
        for(int i = 0; i < N; ++i) {
            char a; int p;
            cin >> a >> p;
            score[a] = p;
            //cout << score['d'] << endl;
        }
        cin >> s1 >> s2;
        n = s1.size();
        m = s2.size();
        int **dp;
        dp = new int*[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = new int[m];
        }
        //cout << n << endl << m << endl;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                dp[i][j] = 0;
        }
        //cout << dp[0][0] << endl;
        for(int i = 0; i < n; ++i) {
            if(s1[i] == s2[0])
                dp[i][0] = score[s2[0]];
        }

        for(int i = 0; i < m; ++i) {
            if(s2[i] == s1[0])
                dp[0][i] = score[s1[0]];
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if(s1[i] == s2[j]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + score[s1[i]]);
                }
                //cout << dp[i][j] << endl;
            }
        }
        cout << dp[n-1][m-1] << endl;

        for(int i = 0; i < n; ++i) {
            delete[] dp[i];
        }
        delete[] dp;
        dp = NULL;
        //delete[] dp;
    }
    return 0;
}
