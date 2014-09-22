/*
#Problem ID: 1914
#Submit Time: 2013-03-20 09:47:56
#Run Time: 110
#Run Memory: 3272
#ZOJ User: calvinxiao
*/

/**
Calvin's Code
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;

#define REP(i, n) for (int i = 0; i < (n); ++i)

struct edge {
    int a, b;
    double d;
};

bool cmp(edge a, edge b) {
    return a.d < b.d;
}

int tc, S, P, a[505], b[505], f[505], cnt;

double dist(int A, int B, int C, int D) {
    return sqrt(1.0 * (A-C)*(A-C) + (B-D)*(B-D));
}

int main() {
    //freopen("0.in", "r", stdin);
    scanf("%d", &tc);
    while(tc--) {
        //cout << tc << endl;
        scanf(" %d %d", &S, &P);
        REP(i, P) {
            scanf(" %d %d", &a[i], &b[i]);
        }

        vector<edge> e;
        e.clear();
        REP(i, P) REP(j, P) if (j > i) {
            edge ee;
            ee.a = i;
            ee.b = j;
            ee.d = dist(a[i], b[i], a[j], b[j]);
            e.push_back(ee);

        }

        cnt = 0;
        for (int i = 0; i <= P; ++i)
            f[i] = i;

        sort(e.begin(), e.end(), cmp);

        double ans = 0.0;
        for (int i = 0; i < e.size(); i++) {
            //cout << cnt << ' ' << S << ' ' << P << endl;
            if (cnt + S == P)
                break;
            int A = e[i].a, B = e[i].b;
            while (f[A] != f[f[A]]) f[A] = f[f[A]];
            while (f[B] != f[f[B]]) f[B] = f[f[B]];
            if (f[A] != f[B]) {
                //cout << A << ' ' << B << endl;
                f[f[A]] = f[B];
                ans = e[i].d;
                cnt++;
            }
        }

        printf("%.2f\n", ans);

    }
    return 0;
}
