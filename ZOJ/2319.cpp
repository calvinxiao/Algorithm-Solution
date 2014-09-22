/*
#Problem ID: 2319
#Submit Time: 2013-05-01 01:49:41
#Run Time: 1670
#Run Memory: 6732
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, n;
struct TA{
    int fi, se, idx;
} p[100005];
int a, b[100005];
int tree[100005*4], dp[100005], ans;

bool cmp(struct TA pa, struct TA pb) {
    if (pa.fi < pb.fi)
        return true;
    if (pa.fi == pb.fi && pa.se < pb.se)
        return true;
    return false;
}

void set(int x, int lr, int l, int r, int rt) {
    if (lr <= l && r <= lr) {
        if (tree[rt] < x)
            tree[rt] = x;
        return;
    }
    int mid = l + r >> 1;
    //printf("%d %d %d %d %d %d\n", x, lr, l, mid, r, rt);
    if (lr <= mid) set(x, lr, l, mid, rt << 1);
    if (mid <  lr) set(x, lr, mid+1, r, rt << 1 | 1);
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

int ask(int ll, int rr, int l, int r, int rt) {
    if (ll <= l && r <= rr) {
        return tree[rt];
    }
    int mid = l + r >> 1;
    int ret = 0;
    if (ll <= mid) {
        int le = ask(ll, rr, l, mid, rt << 1);
        if (ret < le)
            ret = le;
    }
    if (mid < rr) {
        int ri = ask(ll, rr, mid + 1, r, rt << 1 | 1);
        if (ret < ri)
            ret = ri;
    }
    return ret;
}

int main()
{
    //freopen("0.in", "r", stdin);
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a, &b[i]);
            p[i].fi = a;
            p[i].se = b[i];
            p[i].idx = i + 1;
        }

        sort(b, b+n);
        map<int, int> mm;
        int idx = 1;
        for (int i = 0; i < n; ++i) {
            if (mm.find(b[i]) == mm.end()) {
                mm[b[i]] = idx++;
            }
        }
        for (int i = 0; i < n; ++i)
            p[i].se = mm[p[i].se];
        sort(p, p + n, cmp);
        //puts("sdf");
        ans = 0;
        memset(dp, 0, sizeof dp);
        memset(tree, 0, sizeof tree);

        int st = n - 1, en = n - 1, nn = idx + 1;
        while (st >= 0) {
            while (st >= 0 && p[st].fi == p[en].fi)
                st--;
            //puts("sdf");
            st++;
            int i = st;
            while (i <= en) {
                int ri = ask(p[i].se+1, nn, 1, nn, 1);
                if (dp[i] <= ri) {
                    dp[i] = ri + 1;
                    set(dp[i], p[i].se, 1, nn, 1);
                    if (ans < dp[i])
                        ans = dp[i];
                }
                i++;
            }
            en = st - 1; st = en;
            //printf("%d %d\n", st, en);
        }

        printf("%d\n", ans); int pre = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == ans) {
                if (pre == -1 || (p[i].fi > p[pre].fi && p[i].se > p[pre].se)) {
                    if (i > 0)
                        printf(" ");
                    printf("%d", p[i].idx);
                    pre = i;
                    ans--;
                }
            } else if (ans < 0)
                break;
        }
        printf("\n");

        if (tc)
            printf("\n");
    }

    return 0;
}
