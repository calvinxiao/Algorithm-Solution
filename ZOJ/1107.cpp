/*
#Problem ID: 1107
#Submit Time: 2012-07-02 17:47:39
#Run Time: 80
#Run Memory: 268
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
const int MAX = 101;
int M[MAX][MAX];
int dp[MAX][MAX];
int n, k;
const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int rec(int I, int J)
{
    int &res = dp[I][J];
    if (res != -1)
        return res;
    int cur = M[I][J];
    res = 0;

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < 4; ++j) {
            int ii = I + i * dir[j][0];
            int jj = J + i * dir[j][1];
            if (ii >= 0 && ii < n && jj >= 0 && jj < n && M[ii][jj] > cur) {
                res = max(res, rec(ii, jj));
            }
        }
    }
    res += cur;
    return res;
}

int main()
{

    //cout<<dp[0][0]<<endl;
    while(1) {
        memset(dp, -1, sizeof dp);
        cin >> n >> k;
        if(n == -1 && k == -1)
            break;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &M[i][j]);
            }
        }
        cout << rec(0, 0) << endl;
    }
    return 0;
}
