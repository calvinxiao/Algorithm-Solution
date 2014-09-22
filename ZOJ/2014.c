/*
#Problem ID: 2014
#Submit Time: 2012-09-21 12:04:47
#Run Time: 70
#Run Memory: 236
#ZOJ User: calvinxiao
*/

#include<stdio.h>

#define BIG 1000000007

int T, n, i, j, k, t, E, F, G, P, W, *p;
int a[10005];
int b[10005];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &E, &F, &n);
        G = F - E;
        for(i = 0; i <= G; ++i) {
            a[i] = BIG;
            b[i] = BIG;
        }

        a[0] = 0;

        while(n--) {
            scanf("%d %d", &P, &W);
            if(W <= G && b[W] > P) {
                b[W] = P;
                for(i = 0; i + W <= G; ++i) {
                    t = a[i] + P;
                    p = &a[i+W];
                    if(*p > t) {
                        *p = t;
                    }
                }
            }
        }

        if(a[G] != BIG) {
            printf("The minimum amount of money in the piggy-bank is %d.\n", a[G]);
        }
        else
            printf("This is impossible.\n");

    }

    return 0;
}
