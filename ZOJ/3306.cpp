/*
#Problem ID: 3306
#Submit Time: 2013-12-19 00:44:49
#Run Time: 4810
#Run Memory: 272
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <algorithm>
using namespace std;

char g[22][22];

int main()
{
    while (1) {
        int n; cin >> n; if (n == 0) break;
        int ans = 0;
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++) {
                cin >> g[i][j];
            }
        for (int m = 0; m < (1<<20); m++) {
            int rcnt = __builtin_popcount(m);
            if (rcnt >= n)
                continue;
            int c[22];
            for (int i = 0; i < 22; i++) c[i] = 0;
            for (int i = 0; i < 20; i++) {
                if ( (1<<i) & m) {
                    for (int j = 0; j < 20; j++)
                        if (g[i][j] == '#') {
                            c[j]++;
                        }
                }
            }
            int tans = 0;
            sort(c, c + 20);
            reverse(c, c + 20);
            int ccnt = n - rcnt;
            if (ccnt > 20)
                ccnt = 20;
            for (int i = 0; i < ccnt; i++)
                tans += c[i];
            if (ans < tans)
                ans = tans;
        } 
        cout << ans << endl;
    } 
    return 0;
}