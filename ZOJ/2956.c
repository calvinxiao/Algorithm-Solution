/*
#Problem ID: 2956
#Submit Time: 2013-05-24 16:47:34
#Run Time: 10
#Run Memory: 176
#ZOJ User: calvinxiao
*/

#include <stdio.h>

int tc, n, c, ans, ri;
short A[4001], B[4001];

void Sort(short* p, int l, int r) {
    int i = l, j = r, x = p[l+r>>1];
    do {
        while (p[i] < x) i++;
        while (x < p[j]) j--;
        if (i <= j) {
            int t = p[i]; p[i] = p[j]; p[j] = t;
            i++; j--;
        }
    } while (i <= j);
    if (l < j) Sort(p, l, j);
    if (i < r) Sort(p, i, r);
}

int main()
{
	scanf("%d", &tc);
	while(tc--) {
        int i, j;
        scanf("%d", &n);
        ri = 0;
        for (i = 0; i < n; i++) {
            scanf("%d%d%d", &c, &A[i], &B[i]);
            if (ri < B[i])
                ri = B[i];
            B[i]++;
        }
        c = 0;
        ans = 0;
        Sort(A, 0, n-1);
        Sort(B, 0, n-1);
        j = 0;
        for (i = 0; i < n; i++) {
            c++;
            while (j < n && B[j] <= A[i]) {
                j++; c--;
            }
            if (ans < c)
                ans = c;
        }
        printf("%d\n", ans);
	}

    return 0;
}
