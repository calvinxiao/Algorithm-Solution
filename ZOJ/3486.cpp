/*
#Problem ID: 3486
#Submit Time: 2013-03-21 22:36:47
#Run Time: 0
#Run Memory: 572
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>

using namespace std ;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int tc, n, a[100000], id,  mid, ma;

int main() {
    //freopen("0.in", "r", stdin);
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        mid = ma = 0;
        memset(a, 0, sizeof a);
        REP(i, n) {
            scanf("%d", &id);
            a[id] ++;
            if (a[id] > ma || (id > mid && a[id] == ma)) {
                ma = a[id];
                mid = id;
            } 
        }
        printf("%d\n", mid);
    }
    return 0;
}
