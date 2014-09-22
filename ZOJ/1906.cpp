/*
#Problem ID: 1906
#Submit Time: 2013-07-17 01:50:40
#Run Time: 10
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(__typeof(e.begin()) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

int n;

vector<int> p;

int prime(int a){
    int sa = (int)sqrt((double)a);
    for ( int i = 2; i <= sa; i += 2 ) {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    p.push_back(2);
    p.push_back(3);
    for (int i = 5; i < 31622; i++){
        if (prime(i))
            p.push_back(i);
    }

    while (scanf("%d", &n) && n) {
        if (n == 1) {
            puts("0");
            continue;
        }
        int nn = n, ans = n;
        for (int i = 0; i < p.size() && p[i] <= nn; i++) {
            if (nn % p[i] == 0) {
                ans /= p[i];
                ans *= p[i] - 1;
            }
            while (nn % p[i] == 0) {
                nn /= p[i];
            }
        }
        if (nn != 1) {
            ans /= nn;
            ans *= nn - 1;
        }

        printf("%d\n", ans);
    }
    return 0;
}
