/*
#Problem ID: 3656
#Submit Time: 2013-11-07 12:22:36
#Run Time: 180
#Run Memory: 1152
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>

using namespace std ;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int a[501], b[501][501], n, _j, _k;

int checkgood() {
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j)
            if (b[i][j] != b[j][i])
                return 0;
        if (b[i][i])
            return 0;
    }
    return 1;
}

int check(int k, int sign) {
    memset(a, 0, sizeof a);
    _k = 1 << k;

    if (sign)
        a[0] = _k;

    for (int i = 1; i < n; i += 2)
        a[i] = a[0] ^ (b[0][i] & _k);

    for (int i = 2; i < n; i += 2)
        a[i] = a[1] ^ (b[i][1] & _k);

    REP(i, n) for (int j = i + 1; j < n; ++j) {
        if ((i&1) && (j&1)) _j = a[i] | a[j];
        else if (!(i&1) && !(j&1)) _j = a[i] & a[j];
        else _j = a[i] ^ a[j];
        if (_j != (b[i][j] & _k))
            return 0;
    }
    return 1;
}

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

int main() {
    //freopen("0.in", "r", stdin);
    while (~scanf(" %d ", &n)) {
        int high = 0;
        bool good = true;
        REP(i, n) REP(j, n) {
            //scanf("%d", &b[i][j]);
			b[i][j] = read_int();
            high |= b[i][j];
        }

        if (n == 1) {
            if (b[0][0] != 0)
                good = false;
        }
        else {
            good = checkgood();
            if (good)
            REP(i, 31) if ((high & (1<<i)) && !check(i, 1) && !check(i, 0)) {
                good = false;
                break;
            }
        }
        if (good) puts("YES");
        else puts("NO");
    }
    return 0;
}