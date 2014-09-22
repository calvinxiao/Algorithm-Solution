/*
#Problem ID: 3198
#Submit Time: 2012-09-13 16:50:10
#Run Time: 160
#Run Memory: 548
#ZOJ User: calvinxiao
*/

#include<stdio.h>

int TC, tc, c1, c2, i, n, idx, ans, s1[100000];

int main() {
    scanf("%d", &TC);
    while(tc < TC) {
        tc += 1;
        scanf("%d", &c1);
        for(i = 0; i < c1; ++i)
            scanf("%d", &s1[i]);
        scanf("%d", &c2);
        idx = 0; ans = 0;
        for(i = 0; i < c2; ++i) {
            scanf("%d", &n);
            while(idx < c1 && s1[idx] < n) idx++;
            if(idx < c1) {
                if(s1[idx] > n) continue;
                if(s1[idx] == n) {
                    ans++;
                    idx++;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
