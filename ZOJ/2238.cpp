/*
#Problem ID: 2238
#Submit Time: 2013-02-20 10:05:29
#Run Time: 280
#Run Memory: 11984
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

const int MAX = 100;

int n;
int a[1000100];
int state[1000100];
bool found;
int end;

int dfs(int u) {
	//cout << end << endl;
	//cout << u << endl;
	if (found) return 1;
	if (u == end) {
		REP(i, end)
			printf("%d", a[i]);
		printf("\n");
		found = 1;
		return 1;
	}
	int t = 0;
	for (int i = n-2; i >= 0; --i) {
		t += a[u-i-1];
		t *= 10;
	}
	REP(i, 10) {
		if (!state[t+i]) {
			a[u] = i;
			state[t+i] = 1;
			if (dfs(u+1))
				return 1;
			state[t+i] = 0;
		}
	}
	return 0;
}

int main()
{
	//freopen("0.in", "r", stdin);
	while (1) {
		memset(state, -1, sizeof state);
		cin >> n;
		if (!n)
			break;
		end = 1;
		REP(i, n) end *= 10;
		end += n-1;
		REP(i, end) a[i] = -1;
		found = 0;
		int s = 0;
		while (s < n-1)
			a[s++] = 0;
        stack<int> st;
        st.push(s);
        while (!st.empty()) {
            int u = st.top();
            //8cout << u << ' ' << a[u-1] << endl;
            if (a[u] == 10) {
                st.pop();
                a[u] = -1;
                continue;
            }
            if (found) {
                st.pop();
                continue;
            }
            int t = 0;
            for (int i = n-1; i > 0; --i) {
                t += a[u-i];
                t *= 10;
            }
            //cout << t << endl;
            while(1) {
                //cout << u << ' ' << a[u-1] << endl;
                if (a[u] != -1) {
                    if (state[t+a[u]] == u)
                        state[t+a[u]] = -1;
                }
                a[u]++;
                if (a[u] == 10) break;
                //printf("%d %d %d\n", u, a[u], state[t+a[u]]);
                if (state[t+a[u]] == -1) {
                    state[t+a[u]] = u;
                    st.push(u+1);
                    if (u == end-1) {
                        REP(i, end)
                            printf("%d", a[i]);
                        printf("\n");
                        found = 1;
                    }
                    break;
                }
            }
        }

	}
    return 0;
}
