/*
#Problem ID: 2705
#Submit Time: 2012-08-30 12:22:59
#Run Time: 0
#Run Memory: 160
#ZOJ User: calvinxiao
*/

#include<stdio.h>
long long m, n, ans, temp, a, b;
int main()
{
    while(scanf(" %lld %lld", &n, &m) != EOF) {
        ans = 0; temp = 0; a = b = 1;
        while(a + b <= m || a + b <= n) {
            temp += a;
            if( m % (a + b) == 0) {
                if(ans < temp * n * (m / (a + b)))
                    ans = temp * n * (m / (a + b));
            }
            if( n % (a + b) == 0) {
                if(ans < temp * m * (n / (a + b)))
                    ans = temp * m * (n / (a + b));
            }
            b = a + b;
            a = b - a;
        }
        printf("%lld\n\n", ans);
    }
    return 0;
}
