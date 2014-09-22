/*
#Problem ID: 1514
#Submit Time: 2012-08-21 13:46:46
#Run Time: 0
#Run Memory: 208
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdio>
#include<memory.h>
using namespace std;
bool v[10001], c[10001];
int t, n, m, ans;
int main()
{
    while(1) {
        memset(v, 0, sizeof v);
        memset(c, 0, sizeof c);
        ans = 0;
        cin >> n >> m;
        if(!n) break;

        for(int i = 0; i < m; ++i) {
            cin >> t;
            if(v[t]) {
                if(!c[t])
                    ans++;
                c[t] = 1;
            }
            else v[t] = 1;
        }

        cout << ans << endl;
    }
    return 0;
}
