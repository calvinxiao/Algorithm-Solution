/*
#Problem ID: 2202
#Submit Time: 2012-08-27 01:03:41
#Run Time: 0
#Run Memory: 276
#ZOJ User: calvinxiao
*/

#include<stdio.h>

int i, j;
char c;
int a[10001];
long long f[10001];
int main()
{
    while(1) {
        scanf("%c", &c);
        if(c !='\n') {a[i++] = c - '0'; if(i == 1 && a[0] == 0) break;}
        else {
            if(i == 1 && a[0] == 0) break;

            f[0] = 1LL;
            if(a[1] != 0 && i > 1 && a[0] * 10 + a[1] < 27) f[1] = 2LL;
            else f[1] = 1LL;
            for(j = 2; j < i; j++) {
                f[j] = 0;
                if(a[j] != 0)
                    f[j] += f[j-1];
                if(a[j-1] != 0 && a[j-1] * 10 + a[j] < 27)
                    f[j] += f[j-2];
            }
            printf("%lld\n", f[i-1]);
            i = 0;
        }
    }

    return 0;
}
