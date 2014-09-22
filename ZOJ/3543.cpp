/*
#Problem ID: 3543
#Submit Time: 2013-04-25 23:12:55
#Run Time: 400
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>

char s[1006];
int n, i, j, d1[1006], d2[1006];
const int md = 1000000007;
int *dp1, *dp2;

int main()
{
    while (~scanf("%s", s+2)) {
        n = strlen(s+2) + 1;
        dp1 = d1, dp2 = d2;
        dp1[1] = 1;
        for (i = 2; i <= n; ++i) {
            for (j = 1; j <= i; ++j) {
                if (s[i] == 'I') {
                    dp2[j] = dp1[j-1];
                } else if (s[i] == 'D') {
                    dp2[j] = dp1[i-1] - dp1[j-1];
                    if (dp2[j] < 0)
                        dp2[j] += md;
                } else {
                    dp2[j] = dp1[i-1];
                }

                dp2[j] += dp2[j-1];
                if (dp2[j] >= md)
                    dp2[j] -= md;
            }
            //memcpy(dp1, dp2, sizeof dp1);
            int *temp = dp1; dp1 = dp2; dp2 = temp;
        }
        printf("%d\n", dp1[n]);
    }
    return 0;
}
