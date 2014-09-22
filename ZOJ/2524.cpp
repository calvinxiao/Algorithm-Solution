/*
#Problem ID: 2524
#Submit Time: 2013-03-30 21:10:30
#Run Time: 420
#Run Memory: 1860
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

const int BIG = (int)1e9 + 7;
const int MAX = 10006;

int n, idx, s1[MAX], s2[MAX], d[MAX], p[MAX], cnt, c[MAX], ww[MAX], dd[MAX], ll[MAX];
string nl[MAX];
map<string, int> name;

int getIdx(string nm) {
    if (name.find(nm) != name.end())
        return name[nm];
    name[nm] = cnt++;
    return cnt-1;
}

bool cmp(int i, int j) {
    if (p[i] > p[j])
        return true;
    else if (p[i] == p[j]) {
        if (d[i] > d[j])
            return true;
        else if (d[i] == d[j]) {
            if (nl[i] < nl[j])
                return true;
        }
    }
    return false;
}

int main() {
    //freopen("0.in", "r", stdin);

    while(cin >> n) {
        name.clear();
        REP(i, MAX) {
            s1[i] = 0;
            s2[i] = 0;
            d[i] = 0;
            p[i] = 0;
            ww[i] = dd[i] = ll[i] = 0;
        }
        cnt = 0;
        REP(i, n) {
            string n1, n2;
            int t1, t2;
            char t3;
            cin >> n1 >> t1 >> t3 >> t2 >> n2;
            int id1 = getIdx(n1);
            int id2 = getIdx(n2);
            nl[id1] = n1; nl[id2] = n2;
            if (t1 < t2) {
                p[id2] += 3;
                ww[id2] += 1;
                ll[id1] += 1;
            } else if (t1 > t2) {
                p[id1] += 3;
                ww[id1] += 1;
                ll[id2] += 1;
            } else {
                p[id1] += 1;
                p[id2] += 1;
                dd[id1] += 1;
                dd[id2] += 1;
            }
            s1[id1] += t1;
            s2[id1] += t2;
            d[id1] = s1[id1] - s2[id1];

            s1[id2] += t2;
            s2[id2] += t1;
            d[id2] = s1[id2] - s2[id2];
        }

        REP(i, cnt+1)
            c[i] = i;
        sort(c, c + cnt, cmp);

        if (idx) {
            cout << endl;
        }
        idx++;

        REP(i, cnt) {
            printf("%d %s %d %d %d %d %d\n", i + 1, nl[c[i]].c_str(), ww[c[i]], dd[c[i]], ll[c[i]], p[c[i]], d[c[i]]);
        }

    }
    
    return 0;
}
