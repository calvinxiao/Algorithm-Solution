/*
#Problem ID: 1992
#Submit Time: 2013-07-19 01:10:08
#Run Time: 10
#Run Memory: 188
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

const int N = 205;
const int inf = (int)1e9;
int deg[N], n, s, a, b, c;

struct Edge {int to, cap, rev;};

struct FF {
    //int inf = 10000000009;
    vector<Edge> g[N+5];
    bool vis[N+5];
    void addEdge(int from, int to, int cap) {
        g[from].push_back((Edge){to, cap, g[to].size()});
        g[to].push_back((Edge){from, 0, g[from].size() - 1});
    }

    int dfs(int s, int t, int flow) {
        if (s == t)
            return flow;
        vis[s] = true;
        for (int i = 0; i < g[s].size(); i++) {
            Edge &e = g[s][i];
            if (!vis[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (1) {
            memset(vis, 0, sizeof vis);
            int d = dfs(s, t, inf);
            if (d > 0)
                flow += d;
            else
                break;
        }
        return flow;
    }
};

struct Dinic {
    vector<Edge> g[N+5];
    int lv[N+5], ptr[N+5];

    void addEdge(int from, int to, int cap) {
        g[from].push_back((Edge){to, cap, g[to].size()});
        g[to].push_back((Edge){from, 0, g[from].size() - 1});
    }

    int bfs(int s, int t) {
        queue<int> q;
        q.push(s);
        memset(lv, -1, sizeof lv);
        lv[s] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int i = 0; i < g[v].size(); i++) {
                Edge &e = g[v][i];
                if (lv[e.to] == -1 && e.cap > 0) {
                    lv[e.to] = lv[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return (lv[t] != -1);
    }

    int dfs(int s, int t, int flow) {
        if (s == t) return flow;
        for (int &i = ptr[s]; i < g[s].size(); i++) {
            Edge &e = g[s][i];
            if (e.cap > 0 && lv[s] < lv[e.to]) {
                int d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            memset(ptr, 0, sizeof ptr);
            while (int f = dfs(s, t, inf))
                flow += f;
        }
        return flow;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    int tc; scanf("%d", &tc);
    while (tc--) {
    	scanf("%d%d", &n, &s);
    	memset(deg, 0, sizeof deg);
    	//FF f;
        Dinic f;

    	REP(i, s) {
    		scanf("%d%d%d", &a, &b, &c);
    		a--; b--;
    		deg[a]++;
    		deg[b]--;
    		if (!c) {
                f.addEdge(a, b, 1);
    		}
    	}

    	int good = 1;
    	REP(i, n) {
            if (deg[i] > 0) {
                if (deg[i] & 1)
                    good = 0;
                f.addEdge(n, i, deg[i] >> 1);
            }
            if (deg[i] < 0) {
                deg[i] = -deg[i];
                if (deg[i] & 1) {
                    good = 0;
                }
                f.addEdge(i, n+1, deg[i] >> 1);
            }

            if (!good)
                break;
    	}

    	if (!good) {
            puts("impossible");
            continue;
    	}

    	int expected_flow = 0;
    	for (int i = 0; i < f.g[n].size(); i++)
            expected_flow += f.g[n][i].cap;

    	int flow = f.max_flow(n, n+1);
    	if (flow == expected_flow)
            good = 1;
        else
            good = 0;

    	if (good)
    		puts("possible");
    	else
    		puts("impossible");
    }
    return 0;
}
