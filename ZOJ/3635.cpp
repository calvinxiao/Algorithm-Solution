/*
#Problem ID: 3635
#Submit Time: 2013-05-01 02:58:06
#Run Time: 740
#Run Memory: 832
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, x, a[55555], b[55555], v[55555];

int ask(int i) {
    int ret = 0;
    while (i > 0) {
        ret += a[i];
        i -= i & (-i);
    }
    return ret;
}

void set(int i, int z) {
    while (i <= n) {
        a[i] += z;
        i += i & (-i);
    }
}

int main()
{
    //freopen("0.in", "r", stdin);
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof a);
        memset(v, 0, sizeof v);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            int l = 1, r = n, mid, idx = 1;
            while (l < r + 1) {
                mid = l + r >> 1;
                int le = mid - ask(mid);
                if (le == x) {
                    if (!v[mid]) {
                        idx = mid;
                        break;
                    } else
                        r = mid - 1;

                } else if (le < x)
                    l = mid + 1;
                else if (le > x)
                    r = mid - 1;
                //printf("%d %d %d %d %d %d\n", le, x, mid, v[mid], l, r);
            }
            //printf(" %d\n", ask(1));
            v[idx] = 1;
            set(idx, 1);
            b[i] = idx;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
            scanf("%d", &x), printf("%d%c", b[x], i == m - 1 ? '\n':' ');

    }
    return 0;
}
