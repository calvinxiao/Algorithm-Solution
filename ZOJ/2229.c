/*
#Problem ID: 2229
#Submit Time: 2012-08-27 00:17:06
#Run Time: 0
#Run Memory: 160
#ZOJ User: calvinxiao
*/

#include<stdio.h>

int i, j, n, vi, ti, Tmin;
const int Length = 45 * 360;

int min(int a, int b) {
    return a < b?a:b;
}

int time(int v, int t) {
    int TIME = Length / v;
    if (Length % v != 0)
        TIME += 1;
    return TIME + t;
}

int main()
{
    while(1) {
        Tmin = 100000000;
        scanf(" %d", &n);
        if(!n) break;
        for(i = 0; i < n; i++) {
            scanf(" %d %d", &vi, &ti);
            if(ti < 0) continue;
            Tmin = min(Tmin, time(vi, ti));
        }
        printf("%d\n", Tmin);
    }

    return 0;
}
