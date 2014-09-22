/*
#Problem ID: 1823
#Submit Time: 2012-09-07 00:13:25
#Run Time: 90
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cmath>
typedef long long ll;

using namespace std;

void factor(ll n) {
    ll d = 2LL;
    ll top = sqrt((double)n);
    while (d <= top && d <= n) {
        if (n%d) {
            if (d == 2)
                d += 1;
            else
                d += 2;
        } else {
            cout << d << endl;
            n = n / d;
            top = sqrt((double)n);
        }
    }
    if (n>1)
        cout << n << endl;
    cout << endl;
}

main() {
    ll n;
    for(;;) {
        cin >> n;
        if (n<0) break;
        factor(n);

    }
    return 0;
}
