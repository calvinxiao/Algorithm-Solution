/*
#Problem ID: 1457
#Submit Time: 2012-08-20 11:35:56
#Run Time: 1730
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<memory.h>
using namespace std;

int n, a[22], isprime[50], v[22], next[22][22], cnt[22];

void rec(int step) {
    if(step == n) {
        if (isprime[a[n-1] + 1]) {
            for(int i = 0; i < n; ++i) {
                if (i == 0) cout << 1;
                else cout << ' ' << a[i];
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i < cnt[a[step - 1]]; ++i) {
            if(!v[next[a[step - 1]][i]] && next[a[step - 1]][i] <= n) {
                v[a[step - 1]] = 1;
                a[step] = next[a[step - 1]][i];
                rec(step + 1);
                v[a[step - 1]] = 0;
            }
        }
    }
}

int main() {
    isprime[2] = 1;
    isprime[3] = 1;
    isprime[5] = 1;
    isprime[7] = 1;
    isprime[11] = 1;
    isprime[13] = 1;
    isprime[17] = 1;
    isprime[19] = 1;
    isprime[23] = 1;
    isprime[29] = 1;
    isprime[31] = 1;
    isprime[37] = 1;
    isprime[39] = 1;

    for(int i = 1; i < 21; ++i) {
        for(int j = 2; j < 21; ++j) {
            if(i != j && isprime[i + j]) {
                next[i][cnt[i]++] = j;
            }
        }
    }

    int tc = 0;
    while(cin >> n) {
        tc += 1;
        a[0] = 1;

        memset(v, 0, sizeof v);
        cout << "Case " << tc << ":" << endl;
        if (n % 2 == 1)
            //cout << endl;
            ;
        else
            rec(1);
        cout << endl;
    }

    return 0;
}
