/*
#Problem ID: 2150
#Submit Time: 2013-08-19 23:47:04
#Run Time: 70
#Run Memory: 180
#ZOJ User: calvinxiao
*/

#include <cstdio>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(__typeof(e.begin()) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

inline int read_int(){
    int a=0;
    int b=1,c=getchar();
    if(c=='-')b=-1;
    else a=c-48;
    while((c=getchar())!=' '&&c!='\n')
        a=a*10+c-48;
    a*=b;
    return a;
}

const int maxn = 1000001;

int tc, n, md, a, b;
long long ans;

int pow(int A, int B, int M) {
    if (B == 0) return 1;
    if (B == 1) return A;
    long long ret = pow(A, B>>1, M);
    ret = ret * ret % M;
    if (B&1)
        ret = ret * A % M;
    return (int)ret;
}

int main()
{
    //freopen("0.in", "r", stdin);
    scanf(" %d ", &tc);
    while (tc--) {
        scanf(" %d %d ", &md, &n);
        ans = 0;
        for (int i = 0; i < n; ++i) {
            //scanf("%d%d", &a, &b);
            a = read_int(); b = read_int();
            if (a == 0) continue;
            //ans += pow(a, b, md);
            long long ret = 1, aa = a;
            while (b) {
                if (b&1)
                    ret = ret * aa % md;
                aa = aa * aa % md;
                b >>= 1;
            }
            ans += (int)ret;
            ans %= md;
        }
        printf("%d\n", ans);
    }
    return 0;
}