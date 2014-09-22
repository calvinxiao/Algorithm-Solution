/*
#Problem ID: 2286
#Submit Time: 2012-08-21 01:59:19
#Run Time: 460
#Run Memory: 4092
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
int a[MAX], n, l, r, mid, ans;
int main()
{
    a[0] = 0;
    a[1] = 1;
    for(int num = 2; num < MAX; ++num) {
        a[num] += 1;
        for (int next = num + num; next < MAX; next += num)
            a[next] += num;
    }
    sort(a, a + MAX);
    //for(int i = 0; i < MAX; ++i) cout << a[i] << ' ';
    //cout << endl;
    //cout << a[80000] <<' '<< a[1000000] <<' '<< a[999999] <<' '<< a[999998] <<' '<< a[5] <<' '<< a[6] <<' '<< a[7] <<' '<< a[8] <<endl;
    while(cin >> n) {
        if(n == 0) {
            cout << 0 << endl;
            continue;
        }
        l = 0; r = MAX - 1;
        while(l <= r) {
            mid = (l + r) / 2;
            if(a[mid] <= n) l = mid + 1;
            else r = mid - 1;
        }
        cout << l - 1 << endl;
    }
    return 0;
}
