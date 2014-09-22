/*
#Problem ID: 1152
#Submit Time: 2012-09-16 01:21:50
#Run Time: 150
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#define FOR(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;


int main() {
    int TC, tc, subtc, a, b, n, m, cnt;
    cin >> TC;
    for(tc = 0; tc < TC; ++tc) {
        if(tc) cout << endl;

        subtc = 0;
        while (1) {
            subtc += 1;
            cin >> n >> m;
            if(!n && !m) break;
            cnt = 0;
            for(a = 1; a < n; ++a)
            for(int b = a + 1; b < n; ++b) {
                if((a * a + b * b + m) % (a * b) == 0)
                    cnt += 1;
            }
            printf("Case %d: %d\n", subtc, cnt);
        }
    }
    return 0;
}
