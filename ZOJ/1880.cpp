/*
#Problem ID: 1880
#Submit Time: 2012-08-07 23:45:48
#Run Time: 590
#Run Memory: 4624
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<memory.h>
using namespace std;

const int MAX = 45000;
bool w[MAX + 1][101];
int N;
int abs(int a) {
    if(a < 0) return -a;
    return a;
}

int min(int a, int b) {
    return a<b?a:b;
}

int main()
{
    while(cin >> N) {
        memset(w, 0, sizeof w);
        int total = 0;
        w[0][0] = 1;
        int tempMax = N * 450;
        for(int n = 0; n < N; ++n) {
            int v;
            cin >> v;
            total += v;
            for(int i = tempMax / 2; i >= v; --i) {
                for(int j = N / 2 + 1; j >= 1; --j) {
                    if(w[i-v][j-1])
                        w[i][j] = 1;
                }
            }
        }
        int ans = 45000;
        for(int i = 0; i <= total/2; ++i) {
            if(w[i][N/2])
             ans = min(ans, total - 2 * i);
        }
        if(N%2==1) {
            for(int i = 0; i <= total/2; ++i) {
                if(w[i][N/2+1])
                 ans = min(ans, total - 2 * i);
            }
        }
        //cout << ans << endl;
        cout << (total - ans) / 2 << ' ' << total - (total - ans) /2 << endl;
    }

    return 0;
}
