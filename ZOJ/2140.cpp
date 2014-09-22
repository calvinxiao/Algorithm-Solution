/*
#Problem ID: 2140
#Submit Time: 2013-12-03 21:40:38
#Run Time: 90
#Run Memory: 320
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <algorithm>
using namespace std;

int tc, n, g[111][111], v[111];
pair<int, int> a[111];
int main()
{
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        if (tc > 0)
            cout << endl;
        tc++;
        for (int i = 0; i < n; i++) 
            cin >> a[i].first, a[i].second = i;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = 0;
        while (1) {
            sort(a, a + n);
            reverse(a, a + n);
            if (a[0].first == 0)
                break;
            int m = a[0].first;
            int j = a[0].second;
            for (int i = 1; i <= m && i < n; i++) {
                if (a[i].first > 0) {
                    a[0].first--;
                    a[i].first--;
                    int k = a[i].second;
                    g[j][k] = g[k][j] = 1;
                }
            }
            if (a[0].first > 0)
                break;
        }
        int good = 1;
        for (int i = 0; i < n; i++)
            if (a[i].first > 0) {
                good = 0;
                break;
            }
        if (!good)
            cout << "~><~\n";
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << g[i][j];
                    if (j == n - 1)
                        cout << endl;
                    else
                        cout << " ";
                }
            }
        }
    }
    return 0;
}