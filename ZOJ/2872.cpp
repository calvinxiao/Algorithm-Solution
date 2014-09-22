/*
#Problem ID: 2872
#Submit Time: 2013-04-09 23:34:05
#Run Time: 250
#Run Memory: 7992
#ZOJ User: calvinxiao
*/

#include <cstdio>
using namespace std;

const int maxn = 2000005;
const int md = 1000000;
int n, a[maxn];

int main()
{
    //freopen("0.in", "r", stdin);
    a[0] = 1;
    for (int i = 1; i < maxn; i <<= 1) {
        for (int j = 0; j + i < maxn; ++j) {
            a[i+j] += a[j];
            if (a[i+j] >= md)
                a[i+j] -= md;
        }
    }
    int tc; scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }

    return 0;

}