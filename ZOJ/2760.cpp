/*
#Problem ID: 2760
#Submit Time: 2013-07-19 01:58:24
#Run Time: 50
#Run Memory: 612
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

const int BIG = (int)1e9 + 7;
const int MAX = 101;

int n, g[MAX][MAX], d[MAX][MAX], c[MAX][MAX], s, t, mf, a[MAX], p[MAX], f[MAX][MAX];

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
    while (~scanf("%d", &n)) {
        REP(i, n) REP(j, n) {
            d[i][j] = BIG;
        }
        REP(i, n) REP(j, n) {
            scanf("%d", &g[i][j]);
            if (i == j) g[i][j] = 0;
            if (g[i][j] >= 0)
                d[i][j] = g[i][j];
        }
        scanf("%d%d", &s, &t);

        if (s == t) {
            printf("inf\n");
            continue;
        }

        REP(k, n) REP(i, n) REP(j, n) {
            if (d[i][j] > d[i][k] + d[k][j]) {
                d[i][j] = d[i][k] + d[k][j];
            }
        }


        Dinic f;
        memset(c, 0, sizeof c);
        REP(i, n)
                REP(j, n)
                        if (g[i][j] > -1 && d[s][i] + d[j][t] + g[i][j] == d[s][t]) {
                            c[i][j] = 1;
                            f.addEdge(i, j, 1);
                        }

        printf("%d\n", f.max_flow(s, t));
    }
    return 0;
}
