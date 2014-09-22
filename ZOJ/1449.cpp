/*
#Problem ID: 1449
#Submit Time: 2012-08-17 22:32:53
#Run Time: 0
#Run Memory: 180
#ZOJ User: calvinxiao
*/

#include<stdio.h>

int main(void) {
    long cube[31][31][31];
    long a[31];
    long f[31];
    long max;
    long maxsum;
    long i;
    long j;
    long x1;
    long x2;
    long k;
    long y1;
    long y2;
    long n;
    long temp;

    scanf("%ld", &n);

    while (n != 0) {
        for (i=0; i<=n; ++i) {
            for (j=0; j<=n; ++j) {
                for (k=0; k<=n; ++k) {
                    cube[i][j][k] = 0;
                }
            }
        }

        for (i=1; i<=n; ++i) {
            for (j=1; j<=n; ++j) {
                for (k=1; k<=n; ++k) {
                    scanf("%ld", &temp);

                    cube[i][j][k] = cube[i][j][k-1] + cube[i][j-1][k] - cube[i][j-1][k-1] + temp;
                }
            }
        }

        maxsum = cube[1][1][1];

        for (x1=1; x1<=n; ++x1) {
            for (y1=1; y1<=n; ++y1) {
                for (x2=x1; x2<=n; ++x2) {
                    for (y2=y1; y2<=n; ++y2) {
                        for (i=1; i<=n; ++i) {
                            a[i] = cube[i][x2][y2] + cube[i][x1-1][y1-1] - cube[i][x1-1][y2] - cube[i][x2][y1-1];
                        }

                        max = a[1];
                        f[1] = a[1];

                        for (i=2; i<=n; ++i) {
                            if (f[i-1] < 0) {
                                f[i] = a[i];
                            } else {
                                f[i] = f[i-1] + a[i];
                            }

                            if (max < f[i]) {
                                max = f[i];
                            }
                        }

                        if (maxsum < max) {
                            maxsum = max;
                        }
                    }
                }
            }
        }

        printf("%ld\n", maxsum);

        scanf("%ld", &n);
    }

    return 0;
}
