/*
#Problem ID: 2868
#Submit Time: 2013-04-10 10:53:45
#Run Time: 800
#Run Memory: 8892
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 36;
int n, a[maxn], cur, ans, half, sum[maxn], mq[maxn];

void init() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    //random_shuffle(a + 1, a + n + 1);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = a[i] + sum[i-1];
    }
    mq[n] = mq[n+1] = a[n];
    for (int i = n; i >= 1; --i) {
        mq[i] = a[i];
        if (mq[i] > mq[i+1])
            mq[i] = mq[i+1];
    }
    half = sum[n] >> 1;
    half++;
}

void go(int s) {
    if (ans < cur)
        ans = cur;
    if (s > n) return;
    if (cur + sum[n] - sum[s-1] <= ans) return;
    if (cur + mq[s] >= half) return;
    cur += a[s];
    if (cur < half) {
        go(s + 1);
    }
    cur -= a[s];
    go(s + 1);
}

int main()
{
    //freopen("0.in", "r", stdin);
    int tc; scanf("%d", &tc);
    while (tc--) {
        init();
        //printf("%d\n", half);
        cur = 0, ans = 0;
        if (n < 30)
            go(1);
        else {
            set<int> s1, s11;
            set<int, greater<int> > s2, s22;
            s1.insert(0);
            for (int i = 1; i <= n/2; ++i) {
                s11.clear();
                for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
                    s11.insert(*it);
                    if (*it + a[i] < half)
                        s11.insert(*it + a[i]);
                }
                s1 = s11;
            }

            s2.insert(0);
            for (int i = n/2 + 1; i <= n; ++i) {
                s22.clear();
                for (set<int, greater<int> >::iterator it = s2.begin(); it != s2.end(); it++) {
                    s22.insert(*it);
                    if (*it + a[i] < half)
                        s22.insert(*it + a[i]);
                }
                s2 = s22;
            }

            for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
                int right = half - *it;
                set<int, greater<int> >::iterator it2 = s2.upper_bound(right);
                if (it2 != s2.end()) {
                    //printf("%d %d\n", right, *it2);
                    if (ans < *it + *it2)
                        ans = *it + * it2;
                }
            }
        }

        printf("%d\n", sum[n] - ans - ans);
    }

    return 0;

}
