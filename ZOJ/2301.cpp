/*
#Problem ID: 2301
#Submit Time: 2013-03-06 11:34:30
#Run Time: 0
#Run Memory: 436
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
using namespace std;

const int M = 2005;
int n, state[M << 2], a[M], b[M], c[M], ansA, ansB, ansLen;
int discrete[M<<2], all[M<<2], cnt;
char color;


int main() {
    //freopen("0.in", "r", stdin);
    while(scanf(" %d", &n) != EOF) {
        memset(state, 0, sizeof state);
        set<int> s;
        map<int, int> ma;
        for(int i = 0; i < n; ++i) {
            scanf(" %d %d %c", &a[i], &b[i], &color);
            if (color == 'w')
                c[i] = 1;
            else
                c[i] = 0;
            s.insert(a[i]); s.insert(b[i]);
            s.insert(a[i]-1); s.insert(b[i]+1);
        }

        cnt = 0;
        for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
            discrete[cnt] = *it;
            ma[*it] = cnt++;
        }

        for (int i = 0; i < n; ++i) {
            int start = ma[a[i]], end = ma[b[i]];
            //cout << start << ' ' << end << endl;
            for (int j = start; j <= end; ++j)
                state[j] = c[i];
        }

        ansA = ansB = ansLen = 0;

        for (int i = 0; i < cnt; ++i) {
            if (state[i]) {
                int j = i + 1;
                while (state[j])
                    j++;
                int newLen = discrete[j] - discrete[i];
                if (newLen > ansLen) {
                    ansLen = newLen;
                    ansA = discrete[i];
                    ansB = discrete[j]-1;
                }
                //cout << discrete[i] << ' ' << discrete[j] << endl;
                i = j;
            }
        }
        if(ansLen != 0) {
            cout << ansA << ' ' << ansB << endl;
        } else
            cout << "Oh, my god\n";
    }
    //cout << 0 << endl;
    return 0;
}
