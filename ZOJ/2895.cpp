/*
#Problem ID: 2895
#Submit Time: 2013-08-20 00:08:07
#Run Time: 190
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(__typeof(e.begin()) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

inline int read_int(){
    int A=0;
    int b=1,c=getchar();
    if(c=='-')b=-1;
    else A=c-48;
    while((c=getchar())!=' '&&c!='\n')
        A=A*10+c-48;
    A*=b;
    return A;
}

const int maxn = 1001;
int idx[maxn][2];
int n, a, ma;

int main()
{
    //freopen("0.in", "r", stdin);
    while (~scanf(" %d ", &n)) {
        ma = 0;
        REP(i, maxn) {
            idx[i][0] = 1000000000;
            idx[i][1] = -1;
        }
        REP(i, n) {
            //scanf("%d", &a);
            a = read_int();
            if (idx[a][0] > i)
                idx[a][0] = i;
            if (idx[a][1] < i)
                idx[a][1] = i;
        }
        ma++;
        if (n == 0)
            puts("0");
        else {
            REPN(ans, 1, maxn) {
                bool good = true;
                REP(i, maxn) 
                    if (good) {
                        if (idx[i][0] < idx[i][1]) {
                            int ci = i % ans;
                            int L = idx[i][0], R = idx[i][1];
                            for (int j = ci; j < maxn; j += ans) if (i != j) {
                                if (L < idx[j][0] && idx[j][0] < R)
                                    good = false;
                                if (L < idx[j][1] && idx[j][1] < R)
                                    good = false;
                                if (!good)
                                    break;
                            }
                        }
                    }
                    else {
                        break;
                    }

                if (good) {
                    printf("%d\n", ans);
                    break;
                }
            }
        }
    }

    return 0;
}