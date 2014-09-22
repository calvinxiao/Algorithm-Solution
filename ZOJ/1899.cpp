/*
#Problem ID: 1899
#Submit Time: 2013-06-29 20:30:30
#Run Time: 660
#Run Memory: 22448
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

char ch[33];
int t[95][30000], p[95][30000], idx, total;
char q[100];
int cnt, inq[200];

void put() {
    int len = strlen(ch);
    for (int i = 0; i < len; ++i) {
        if (!inq[ch[i]]) {
            inq[ch[i]] = 1;
            q[cnt++] = ch[i];
        }
    }
    int cur = 0;
    for (int i = 0; i < len; ++i) {
        char c = ch[i]-' ';
        if (!p[c][cur])
            p[c][cur] = ++idx;
        if (i == len-1) {
            t[c][cur]++;
        }
        cur = p[c][cur];
    }
}

int get(int root, int len) {
    for (int i = 0; i < cnt; ++i) {
        int c = q[i] - ' ';
        if (p[c][root] != 0) {
            ch[len] = q[i];
            if (t[c][root] != 0) {
                for (int j = 0; j <= len; ++j)
                    printf("%c", ch[j]);
                printf(" %.4lf\n", (double)t[c][root]/total*100);
            }
            get(p[c][root], len+1);
        }
    }
}

int main()
{
    //printf("%d\n", ' ');
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
        //freopen("ans.out", "w", stdout);
	#endif
	int tc = 0;
	while (gets(ch)) {
        memset(t, 0, sizeof t);
        memset(p, 0, sizeof p);
        cnt = 0;
        memset(q, 0, sizeof q);
        memset(inq, 0, sizeof inq);
        idx = 0;
        total = 0;
        put();
        total++;
        while (gets(ch) && strlen(ch)) {
            //printf("%s %d\n", ch, len);
            total++;
            put();
        }
        if (tc)
            puts("");
        tc++;
        sort(q, q+cnt);
        get(0, 0);
	}
    return 0;
}
