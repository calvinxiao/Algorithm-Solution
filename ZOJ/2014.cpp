/*
#Problem ID: 2014
#Submit Time: 2012-09-21 11:59:46
#Run Time: 50
#Run Memory: 256
#ZOJ User: calvinxiao
*/

#include<cstdio>
#include<memory.h>

#define BIG 1000000007
using namespace std;
int T, n,i,j,k, t, E, F, G, P, W;
int a[10005];
int b[10005];

int main() {

    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &E, &F);
        G = F - E;
        for(i = 0; i <= G; ++i) {
            a[i] = BIG;
            b[i] = BIG;
        }

        a[0] = 0;
        scanf("%d", &n);
        while(n--) {
            scanf("%d %d", &P, &W);
            if(W <= G && b[W] > P) {
                b[W] = P;
                for(i = 0; i + W <= G; ++i) {
                    t = a[i] + P;
                    if(a[i + W] > t) {
                        a[i + W] = t;
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
