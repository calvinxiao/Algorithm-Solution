/*
#Problem ID: 2397
#Submit Time: 2013-03-22 21:26:31
#Run Time: 60
#Run Memory: 196
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std ;

#define REP(i, n) for (int i = 0; i < (n); ++i)

const int maxn = 1001;
int a[maxn], b[maxn], va[maxn], vb[maxn], n, m, cnt, even, loose;

int main() {
    //freopen("0.in", "r", stdin);
    while (~scanf("%d", &n) && n) {
        REP(i, n) scanf("%d", &a[i]);
        REP(i, n) scanf("%d", &b[i]);
        REP(i, n) va[i] = vb[i] = 0;
        sort(a, a + n);
        //reverse(a, a + n);
        sort(b, b + n);
        reverse(b, b + n);

        cnt = even = loose = 0;
        REP(i, n) {
            REP(j, n) if (!vb[j] && a[i] > b[j]) {
                cnt++;
                va[i] = vb[j] = 1;
                break;
            }
        }
        REP(i, n) if (!va[i]) {
            REP(j, n) if (!vb[j] && a[i] == b[j]) {
                va[i] = vb[j] = 1;
                even++;
                break;
            }
            if (!va[i]) {
                REP(j, n) if (!vb[j] && a[i] < b[j]) {
                    va[i] = vb[j] = 1;
                    loose++;
                    break;
                }
            }
        }
        //printf("%d %d\n", cnt, loose);
        printf("%d\n", (cnt - loose) * 200);
    }
    return 0;
}
