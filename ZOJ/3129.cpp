/*
#Problem ID: 3129
#Submit Time: 2013-04-26 17:49:36
#Run Time: 220
#Run Memory: 2316
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int tc, TC, n, m, k, a, b;
//long long tr[4242;
int cur[1007];
long long sum[1007];
long long ans;
vector<int> g[1007];

int main() {
    //freopen("0.in", "r", stdin);
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        scanf("%d%d%d", &n, &m, &k);
        ans = 0;
        memset(cur, 0, sizeof cur);
        for (int i = 1; i <= k; ++i) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
        }
        for (int i = 1; i <= n; ++i) {
            memset(sum, 0, sizeof sum);
            for (int j = m; j >= 1; --j)
                sum[j] = cur[j] + sum[j+1];
            vector<int> &gg = g[i];
            //for (int j = 0; j < gg.size(); ++j) {
            for (vector<int>::iterator it = gg.begin(); it != gg.end(); ++it) {
                int v = *it;
                ans += sum[v] - cur[v];
            }
            for (vector<int>::iterator it = gg.begin(); it != gg.end(); ++it)
                ++cur[*it];
            gg.clear();
        }
        printf("Test case %d: %lld\n", tc, ans);
    }
    return 0;
}
