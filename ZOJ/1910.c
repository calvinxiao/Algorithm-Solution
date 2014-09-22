/*
#Problem ID: 1910
#Submit Time: 2012-09-18 16:06:27
#Run Time: 0
#Run Memory: 160
#ZOJ User: calvinxiao
*/

#include<stdio.h>
int main() {
    int tc, n, a, b, c, temp, t, ans;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        if(n == 1) ans = 6;
        else ans = 1000000000;
        for(a = 1; a < n; a++)
        for(b = 1, temp = n / a; b <= temp; ++b) {
            if(n % (a * b) == 0) {
                c = n / a / b;
                t = (a*b + b*c + a*c) * 2;
                if(ans > t)
                    ans = t;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
