/*
#Problem ID: 2734
#Submit Time: 2012-08-22 01:27:14
#Run Time: 0
#Run Memory: 168
#ZOJ User: calvinxiao
*/

#include<stdio.h>
short N, M, i, j, nn;
int val, num, tc;
int f[1000], ff[1000];
int main()
{
    while(scanf(" %d %d", &N, &M) != EOF) {
        for(i = 0; i < N; ++i) f[i] = 0, ff[i] = 0;
        for(i = 0; i < M; ++i) {
            scanf(" %d %d", &val, &num);
            for(j = 1; j <= num; ++j) {
                if(j * val > N) break;
                for(nn = N - 1; nn - j * val >= -1; --nn) {
                    if(nn - j * val == -1) ff[nn] += 1;
                    else ff[nn] += f[nn - j * val];
                }
            }
            for(j = 0; j < N; ++j) f[j] += ff[j], ff[j] = 0;
        }

        if(tc != 0)
            printf("\n");
        tc += 1;
        printf("%d\n", f[N-1]);
    }
    return 0;
}
