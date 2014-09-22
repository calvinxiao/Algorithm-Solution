/*
#Problem ID: 2334
#Submit Time: 2013-03-22 20:20:11
#Run Time: 2320
#Run Memory: 6084
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <set>

using namespace std ;

#define REP(i, n) for (int i = 0; i < (n); ++i)

const int maxn = 100005;
multiset<int, greater<int> > s[maxn];
int f[maxn], n, m, a, b, c;

int main() {
    //freopen("0.in", "r", stdin);
    while (~scanf("%d", &n)) {
        REP(i, n) {
            f[i] = i;
            s[i].clear();
            scanf("%d", &c);
            s[i].insert(c);
        }
        scanf("%d", &m);
        REP(mm, m) {
            scanf("%d%d", &a, &b);
            a--; b--;
            while (f[f[a]] != f[a]) f[a] = f[f[a]];
            while (f[b] != f[f[b]]) f[b] = f[f[b]];
            if (f[a] == f[b]) {
                puts("-1");
            } else {
                if (s[f[a]].size() > s[f[b]].size()) {
                    s[f[a]].insert(s[f[b]].begin(), s[f[b]].end());
                    s[f[b]].clear();
                    f[f[b]] = f[a];
                } else {
                    s[f[b]].insert(s[f[a]].begin(), s[f[a]].end());
                    s[f[a]].clear();
                    f[f[a]] = f[b];
                }
                int t = *s[f[f[a]]].begin();
                printf("%d\n", t>>1);
                s[f[f[a]]].erase(s[f[f[a]]].begin());
                s[f[f[a]]].insert(t>>1);
            }

        }
    }
    return 0;
}
