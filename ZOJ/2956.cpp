/*
#Problem ID: 2956
#Submit Time: 2013-05-24 16:36:45
#Run Time: 0
#Run Memory: 196
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

//const int MAX = 10002;

//short t[MAX];

int tc, n, m, a, b, c, ans, ri;
short A[4001], B[4001];

int main()
{
	//freopen("0.in", "r", stdin);
	scanf("%d", &tc);
	while(tc--) {
        //memset(t, 0, sizeof t);
        scanf("%d", &n);
        ri = 0;
        REP(i, n) {
            scanf("%d%d%d", &a, &b, &c);
            if (ri < c)
                ri = c;
            //t[b]++; t[c+1]--;
            A[i] = b; B[i] = c+1;
        }
        c = 0;
        ans = 0;
//        REP(i, ri+1) {
//            t[i] += c;
//            c = t[i];
//            if (ans < c)
//                ans = c;
//        }
        sort(A, A+n);
        sort(B, B+n);
        int j = 0;
        REP(i, n) {
            c++;
            while (j < n && B[j] <= A[i]) {
                j++; c--;
            }
            if (ans < c)
                ans = c;
        }
        printf("%d\n", ans);
	}

    return 0;
}
