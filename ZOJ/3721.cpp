/*
#Problem ID: 3721
#Submit Time: 2013-08-19 14:40:45
#Run Time: 620
#Run Memory: 5884
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

#define N 100005

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

struct C {
    int s, t, num;
};

int cmp(C a, C b) {
    if (a.s < b.s)
        return 1;
    if (a.s == b.s && a.t < b.t)
        return 1;
    return 0;
}

vector<int> ans[N];
int cnt;
struct C p[N];
int n, s, t, i, j;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    while (~scanf(" %d ", &n)) {
        for (i = 0; i < n; i++){
            int a, b;
            //scanf("%d%d",&p[i].s, &p[i].t);
            p[i].s = read_int();
            p[i].t = read_int();
            p[i].num = i + 1;
        }
        sort(p, p+n, cmp);
        i = 0, j = 0, cnt = 0;
        while (i < n){
            if (!ans[cnt].empty())
                ans[cnt].clear();
            ans[cnt].push_back(p[i].num);
            j = i + 1;
            int s = p[i].s, t = p[i].t;
            while (j < n && p[j].s < t) {
                s = p[j].s;
                if (t > p[j].t)
                    t = p[j].t;
                ans[cnt].push_back(p[j].num);
                j++;
            }
            i = j;
            cnt++;
        }
        printf("%d\n", cnt);
        for (i = 0; i < cnt; i++) {
            int m = ans[i].size();
            for (j = 0; j < m; j++) {
                printf("%d%c", ans[i][j], j == (m - 1)? '\n':' ');
            }
        }
        puts("");
    }
    return 0;
}
