/*
#Problem ID: 2656
#Submit Time: 2012-08-31 12:48:58
#Run Time: 2650
#Run Memory: 236
#ZOJ User: calvinxiao
*/

#include<stdio.h>
int a[10005], s[10005], sum, i, j, n, o, d;

void solve() {
    if(sum < 0) {
        printf("impossible\n");
        return;
    }
    else {
        for(i = 0; i < n; i++) {
            sum = 0;
            if(a[i] >= 0) {
                if(s[n-1] - s[i] + a[i] < 0) continue;
                j = i + 1;
                j %= n;
                sum += a[i];

                while (j != i) {
                    sum += a[j];
                    if(sum < 0) break;
                    j += 1;
                    j %= n;
                }

                if(j == i) {
                    printf("%d\n", i);
                    return;
                }
            }

        }
        printf("impossible\n");
        return;
    }
}

int main()
{
    while(scanf(" %d", &n) != EOF) {
        sum = 0;
        for(i = 0; i < n; i++) {
            scanf(" %d %d", &o, &d);
            a[i] = o - d;
            sum += o - d;
            s[i] = sum;
        }
        solve();
    }

    return 0;
}
