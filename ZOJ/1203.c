/*
#Problem ID: 1203
#Submit Time: 2012-08-31 01:30:24
#Run Time: 10
#Run Memory: 240
#ZOJ User: calvinxiao
*/

#include<stdio.h>
#include<math.h>
int tc, n, f[101], i, j, ii, jj, mi, mj, k;
double p[101][2], ans, temp, MAX, BIG = 10000000.0, eps = 1e-8;
double d[101][101];
double Distance(double x1, double x2, double y1, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    while(1) {
        tc += 1;
        scanf(" %d", &n);
        if(!n) break;
        for(i = 0; i < n; ++i) {
            f[i] = i;
            scanf(" %lf %lf", &p[i][0], &p[i][1]);
        }

        for(i = 0; i < n; ++i)
            for(j = i + 1; j < n; ++j)
                d[i][j] = Distance(p[i][0], p[j][0], p[i][1], p[j][1]);

        ans = 0.0;
        for(; 1;) {
            MAX = BIG;
            for(i = 0; i < n; ++i) {
                for(j = i + 1; j < n; ++j) {
                    ii = i;
                    jj = j;
                    while(f[ii] != ii) ii = f[ii];
                    while(f[jj] != jj) jj = f[jj];
                    f[i] = ii;
                    f[j] = jj;
                    if(f[i] != f[j]) {
                        temp = d[i][j];
                        if(temp - MAX < eps) {
                            MAX = temp;
                            mi = i;
                            mj = j;
                        }
                    }
                }
            }

            if(MAX - BIG < eps && MAX - BIG > -eps) break;
            f[f[mj]] = f[mi];
            ans += MAX;
        }

        if(tc != 1) printf("\n");
        printf("Case #%d:\nThe minimal distance is: %.2f\n", tc, ans);
    }

    return 0;
}
