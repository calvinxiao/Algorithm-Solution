/*
#Problem ID: 3410
#Submit Time: 2013-03-06 23:44:16
#Run Time: 240
#Run Memory: 632
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 100;

int t[25001], d[25001], n, k, kk, tt;

void Sort(int l, int r) {
    int i = l, j = r, x = d[(l+r)>>1];
    do {
        while (d[i] < x) ++i;
        while (x < d[j]) --j;
        if (i <= j) {
            int temp = d[i]; d[i] = d[j]; d[j] = temp;
            temp = t[i]; t[i] = t[j]; t[j] = temp;
            ++i; --j;
        }
    } while (i <= j);
    if (l < j) Sort(l, j);
    if (i < r) Sort(i, r);
}

int main()
{
	//freopen("0.in", "r", stdin);
	while(~scanf("%d%d", &n, &k)) {
        REP(i, n) {
            scanf("%d%d", &t[i], &d[i]);
        }
        Sort(0, n-1);
        //multiset<int, greater<int> > s;
        priority_queue<int, vector<int> > q;
        kk = k;
        tt = 0;
        REP(i, n) {
            if (t[i]) {
                //s.insert(t[i]);
                q.push(t[i]);
                tt += t[i];
            }
            while (tt > d[i]) {
                if (q.empty()) {
                    kk = 0;
                    break;
                }
                int top = q.top();
                kk--;
                if (kk == 0)
                    break;
                tt -= top;
                //s.erase(s.begin());
                q.pop();
                //cout << top << endl;
            }
            //printf("%d %d %d\n", i, tt, kk);
            if (!kk)
                break;
        }
        //cout << "kk: " << kk;
        if (kk)
            printf("%d\n", k - kk);
        else
            puts("-1");
	}
    return 0;
}
