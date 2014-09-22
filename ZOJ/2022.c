/*
#Problem ID: 2022
#Submit Time: 2013-06-16 00:04:29
#Run Time: 70
#Run Memory: 160
#ZOJ User: calvinxiao
*/

#include <stdio.h>
int tc, n, ans;
#define m 200000002
#define md 1000000009

int main()
{
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        ans = 0;
        while (n) {
            n -= n % 5;
            n = (long long)n * m % md;
            ans += n;
        }
        printf("%d\n", ans);
    }
    return 0;
}