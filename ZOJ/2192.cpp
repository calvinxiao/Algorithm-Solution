/*
#Problem ID: 2192
#Submit Time: 2013-05-04 01:27:36
#Run Time: 0
#Run Memory: 180
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char cmd[15], c1, c2;
int n, vis[22], cnt, t;
pair<int, int> p[22];
int sz[333], inv[5];

int main()
{
    sz['S'] = 0;
    sz['M'] = 1;
    sz['L'] = 2;
    sz['X'] = 3;
    sz['T'] = 4;

    //freopen("in.txt", "r", stdin);
    while (scanf("%s", cmd) && cmd[0] == 'S') {
        scanf("%d", &n);
        cnt = n;
        for (int i = 0; i < n; ++i) {
            scanf(" %c %c", &c1, &c2);
            p[i].first = sz[c2];
            p[i].second = sz[c1];
        }
        sort(p, p+n);
        for (int i = 0; i < 5; ++i) {
            scanf("%d", &t);
            inv[i] = t;
        }
        memset(vis, 0, sizeof vis);
        for (int j = 0; j < 5; ++j) {
            while (inv[j]--) {
                for (int i = 0; i < n; ++i) {
                    if (!vis[i] && p[i].second <= j && j <= p[i].first) {
                        cnt--; vis[i] = 1; break;
                    }
                }
            }
        }
        scanf("%s", cmd);

        if (cnt == 0)
            printf("T-shirts rock!\n");
        else
            printf("I'd rather not wear a shirt anyway...\n");
    }
    return 0;
}
