/*
#Problem ID: 1119
#Submit Time: 2012-11-22 23:51:07
#Run Time: 0
#Run Memory: 2616
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

using namespace std;

const int  MAX = 1111;
bool g[MAX][MAX], c[MAX][MAX], v[MAX];
vector<int> e[MAX];
bool first;
int node[MAX];
int nodeCnt;
set<int> nodeSet;
void dfs(int u) {
	v[u] = true;
	REP(i, e[u].size()) if(!v[e[u][i]]) dfs(e[u][i]);
}

void doit(int network){
	if(!first) puts("");
	else first = false;
	printf("Network #%d\n", network);

	int cnt = 0;
	REP(i, nodeCnt) {
		int ans = 0;
		memset(v, 0, sizeof v);
		v[node[i]] = true;
		REP(j, nodeCnt) {
			if (!v[node[j]]) {
				ans += 1;
				dfs(node[j]);
				//cout << endl;
			}
		}
		//cout << i << ' ' << ans << endl;
		if(ans > 1) {
			cnt += 1;
			printf("  SPF node %d leaves %d subnets\n", node[i], ans);
		}
	}

	if(0 == cnt) 
		printf("  No SPF nodes\n");
	
}

int main()
{
	//freopen("0.in", "r", stdin);
	//freopen("ans.out", "w", stdout);
	bool tc = true;
	int a, b;
	int network = 0;
	first = true;
	while (1) {
		
		cin >> a;
		if (a == 0 && tc) break;
		else if(a == 0 && !tc) {
			//cout << maxNode << endl;
			nodeCnt = nodeSet.size();
			int idx = 0;
			for(set<int>::iterator it = nodeSet.begin(); it != nodeSet.end(); ++it)
				node[idx++] = *it;
			doit(++network);
			REP(i, nodeCnt) e[node[i]].clear();
			nodeCnt = 0;
			nodeSet.clear();
			tc = true;
		}
		else if(a != 0){
			cin >> b;
			if (tc) {
				tc = false;
			}
			//g[a][b] = c[a][b] = true;
			e[a].push_back(b);
			e[b].push_back(a);
			nodeSet.insert(a);
			nodeSet.insert(b);
		}
	}
    return 0;
}
