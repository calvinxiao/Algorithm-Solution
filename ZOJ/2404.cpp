/*
#Problem ID: 2404
#Submit Time: 2014-04-26 01:28:42
#Run Time: 20
#Run Memory: 668
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

const int N = 10010;
const int INF = 1000000009;

int abs(int v) {
  if (v < 0)
    v = -v;
  return v;
}

struct edge {int to, cap, cost, rev;};

struct MinCostFlow {
    vector<edge> g[N];
    int dist[N];
    int prevv[N], preve[N];
    
    void AddEdge(int from, int to, int flow, int cost) {
        g[from].push_back((edge){to, flow, cost, g[to].size()});
        g[to].push_back((edge){from, 0, -cost, g[from].size()-1});
    }

    int MinCostMaxFlow(int s, int t, int f) {
        int cost = 0;
        while (f > 0) {
            fill(dist, dist + N, INF);
            dist[s] = 0;
            bool update = true;
            while (update) {
                update = false;
                for (int v = 0; v <= t; v++) {
                    if (dist[v] == INF) continue;
                    for (int i = 0; i < g[v].size(); i++) {
                        edge &e = g[v][i];
                        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }
            
            if (dist[t] == INF)
                return -1;

            int d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, g[prevv[v]][preve[v]].cap);
            }
            f -= d;
            cost += dist[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = g[prevv[v]][preve[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }
        return cost;
    }
};

int main() {
  //freopen("0.in", "r", stdin);
  while(1) {
    int n, m;
    scanf(" %d %d ", &n, &m);
    if (n == 0 && m == 0)
      break;
    int cnt1 = 0, cnt2 = 0;
    int x1[111], y1[111], x2[111], y2[111];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        scanf(" %c ", &c);
        if (c == 'm')
          x1[cnt1] = i, y1[cnt1++] = j;
        else if (c == 'H')
          x2[cnt2] = i, y2[cnt2++] = j;
      }
    }

    int s = cnt1 + cnt2,  t = s + 1;
    int cnt = 0;

    MinCostFlow mcf;

    for (int i = 0; i < cnt1; i++) {
      for (int j = 0; j < cnt2; j++) {
        int dollor = abs(x1[i] - x2[j]) + abs(y1[i] - y2[j]);
        mcf.AddEdge(i, cnt1 + j, 1, dollor);
      }
    }
    for (int i = 0; i < cnt1; i++)
      mcf.AddEdge(s, i, 1, 0);
    for (int i = cnt1; i < cnt1 + cnt2; i++)
      mcf.AddEdge(i, t, 1, 0);
    int ans = mcf.MinCostMaxFlow(s, t, cnt1);
    printf("%d\n", ans);
  }
  return 0;
}
