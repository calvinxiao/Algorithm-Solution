/*
#Problem ID: 2037
#Submit Time: 2013-12-06 00:48:08
#Run Time: 0
#Run Memory: 9916
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
double f[1111][1111];

int main()
{
    f[0][0] = f[1][0] = 1;
    for (int i = 1; i < 1001; i++)
        f[i][i] = i;
    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j <= i; j++) {
            if (f[i][j] < f[i][j-1])
                f[i][j] = f[i][j-1];
            double k = j * f[i-j][min(i-j, j-1)];
            if (k > f[i][j])
                f[i][j] = k;
        }
    }
    int TC; cin >> TC;
    for (int tc = 0; tc < TC; tc++) {
        if (tc)
            cout << endl;
        cin >> n;
        bool b = true;
        vector<int> ans;
        int pre = n + 1;
        while (n) {
            int mi = 0;
            double m = 0;
            for (int i = pre - 1; i > 1; i--) {
                double k = f[n-i][min(n-i, i - 1)] * i;
                if (k - f[n][i] < 1e-9 && f[n][i] - k < 1e-9 && f[n][i] > m) {
                    m = f[n][i];
                    mi = i;
                }
            }
            pre = mi;
            ans.push_back(mi);
            n -= mi;
            if (mi == 0)
                break;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < (int)(ans.size()); i++) {
            if (!b)
                cout << ' ';
            b = false;
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}