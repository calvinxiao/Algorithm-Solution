/*
#Problem ID: 3175
#Submit Time: 2013-07-21 21:45:33
#Run Time: 130
#Run Memory: 160
#ZOJ User: calvinxiao
*/

#include<stdio.h>
#include<math.h>

int f(int n, int m) {
    return n / m - 1;
}

long long doit(int n) {
    if (n == 1)
        return 0;
    int sn = (int)(sqrt(1.0 * n));
    long long ans = 0;
    int pre = n / 2, ne;
    int i;
    for (i = 3; i < sn; i++) {
        ne = n / i;
        ans += (long long)(pre - ne) * (i -2);
        pre = ne;
    }
    for (i = 1; i <= pre; i++) {
        ans += f(n, i);
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    int tc; scanf("%d", &tc);
    while (tc--) {
        int n; scanf("%d", &n);
        printf("%lld\n", doit(n));
    }
    return 0;
}
