/*
#Problem ID: 2425
#Submit Time: 2013-05-28 15:38:05
#Run Time: 500
#Run Memory: 1156
#ZOJ User: calvinxiao
*/

#include<cstdio>
#include<cstring>

using namespace std;

int n, m, b[50002], a[50002<<2];

void up(int rt) {
    a[rt] = a[rt<<1] + a[rt<<1|1];
}
void build(int l, int r, int rt) {
    if (l == r) {
        a[rt] = 1;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid+1, r, rt << 1 | 1);
    up(rt);
}
int get(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return a[rt];
    int mid = l + r >> 1;
    int ret = 0;
    if (L <= mid) ret += get(L, R, l, mid, rt << 1);
    if (mid < R)  ret += get(L, R, mid+1, r, rt << 1 | 1);
    return ret;
}
void update(int x, int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        a[rt] = x;
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid) update(x, L, R, l, mid, rt << 1);
    if (mid < R)  update(x, L, R, mid+1 ,r, rt << 1 | 1);
    up(rt);
}

int get(int k) {
    int l = 1, r = n, mid;
    while (l < r + 1) {
        mid = l + r >> 1;
        int cnt = get(1, mid, 1, n, 1);
        if (k < cnt) {
            r = mid - 1;
        } else if (k == cnt) {
            if (b[mid] != 0)
                return mid;
            else
                r = mid - 1;
        } else
            l = mid + 1;
    }
}

int main()
{
    //freopen("0.in", "r", stdin);

    while(1)
    {
        scanf("%d%d", &n, &m);
        if (n == -1 && m == -1)
            break;

        build(1, n, 1);
        for (int i = 1; i <= n; ++i) {
            b[i] = i;
            //update(1, i, i, 1, n, 1);
        }

        int k = (long long)n * (n-1) / 2;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            k -= n - i;
            //printf("%d %d %d\n", get(1, 1, 1, n, 1), get(2, 2, 1, n, 1), get(3, 3, 1, n, 1));
            if (m <= k) {
                ans = get(1);
            } else {
                int j = m - k;
                ans = get(j + 1);
                // mate, interval tree....
                m -= j;
            }
            //printf("%d\n", ans);
            printf("%d%c", ans, i == n ? '\n' : ' ');
            b[ans] = 0;
            update(0, ans, ans, 1, n, 1);
        }
    }

    return 0;
}
