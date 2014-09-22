/*
#Problem ID: 2002
#Submit Time: 2013-04-09 21:49:44
#Run Time: 50
#Run Memory: 192
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
using namespace std;

int n, m, cnt, i, j;
long long a[555], l, r, mid, ans, cur;

int main()
{
    //freopen("0.in", "r", stdin);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        l = 0; r = (long long) 1e15;
        for (i = 0; i < n; ++i) {
            cin >> a[i];
            if (l < a[i])
                l = a[i];
        }

        while (l <= r) {
            mid = (l + r) / 2;
            cur = 0;
            cnt = 0;
            for (i = 0; i < n; ++i) {
                if (cur + a[i] <= mid)
                    cur += a[i];
                else {
                    cnt++;
                    cur = a[i];
                }
            }

            if (cnt < m) {
                ans = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }

        for (i = 0; i < n; ++i) {
            cout << a[i];
            if (i < n - 1)
                cout << ' ';
            else
                cout << endl;
            cur = 0;
            cnt = 0;
            for (j = i + 1; j < n; ++j) {
                if (cur +a[j] <= ans)
                    cur += a[j];
                else 
                    cnt++, cur = a[j];
            }
            if (cnt + 1 <= m - 1)
                m--, cout << "/ ";
        }

    }

    return 0;

}