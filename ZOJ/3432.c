/*
#Problem ID: 3432
#Submit Time: 2012-08-21 00:44:20
#Run Time: 40
#Run Memory: 16028
#ZOJ User: calvinxiao
*/

#include<stdio.h>

int i, j, k, n, cnt, cntc;
char ans[8];
char a[16250001];
int main()
{
    int read = fread(a, sizeof(char), 16250001 , stdin);
    for(i = 0; i < read; i++) {
        for(j = 0; j < 7; ++j) ans[j] = 0;
        n = 0;
        while(a[i] != 10) n *= 10, n += a[i++] - '0';
        i += 1;
        cnt = 2 * n - 1;
        cntc = cnt * 8 + i;
        k = 0;
        for (j = i; j < cntc; j++, k++) {
            ans[k&7] ^= a[j];
        }
        i = j-1;
        for(j = 0; j < 7; j++) putchar(ans[j]);
        putchar('\n');
    }
    return 0;
}
