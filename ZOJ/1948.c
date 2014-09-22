/*
#Problem ID: 1948
#Submit Time: 2013-01-18 22:43:05
#Run Time: 60
#Run Memory: 8024
#ZOJ User: calvinxiao
*/

#include <stdio.h>
#include <memory.h>

int id[1000005];
int t[1005][1005];
int head, tail;
int i, j, k, n, tn, m, cnt[1005], cur[1005], next[1005];
char s[10];
int main() {
    int tc = 0;
    while(scanf(" %d", &n) && n != 0) {
        tc++;
        printf("Scenario #%d\n", tc);
        memset(id, 0, sizeof id);
        memset(cnt, 0, sizeof cnt);
        memset(cur, 0, sizeof cur);
        memset(next, 0, sizeof cur);
        for (i = 1; i <= n; ++i) {
            scanf(" %d", &tn);
            for (j = 0; j < tn; ++j) {
                scanf(" %d", &m);
                id[m] = i;
            }
        }

        head = 0;
        tail = 0;
        while (1) {
            scanf("%s", s);
            if (s[0] == 'S') {
                printf("\n");
                break;
            }
            if (s[0] == 'E') {
                scanf(" %d", &m);
                int idm = id[m];
                t[id[m]][cnt[idm]++] = m;
                if (head == 0) {
                    head = idm;
                    tail = idm;
                }
                if (cur[id[m]]+1 == cnt[idm]) {
                    next[tail] = idm;
                    tail = idm;
                }
            } else if (s[0] == 'D') {
                printf("%d\n", t[head][cur[head]++]);
                if (cur[head] == cnt[head]) {
                    head = next[head];
                }
            }
        }
    }
    return 0;
}
