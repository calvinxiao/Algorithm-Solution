/*
#Problem ID: 2682
#Submit Time: 2013-03-05 20:17:34
#Run Time: 20
#Run Memory: 636
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <queue>
#include <cstring>


#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin()) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 10002;
int n, m, num, vote[MAX][4], liked[MAX];
bool ans[MAX];
vector<int> fans[MAX];

int main()
{
	//freopen("0.in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		memset(ans, 0, sizeof ans);
		memset(vote, 0, sizeof vote);
		memset(liked, 0, sizeof liked);
		scanf("%d%d", &n, &m);
		REPN(i, 1, n) fans[i].clear();
		queue<int> q;
		REP(i, m) {
			scanf("%d", &num);
			scanf("%d", &vote[num][0]);
			REPN(j, 1, vote[num][0]) {
				scanf("%d", &vote[num][j]);
				liked[vote[num][j]]++;
				fans[vote[num][j]].push_back(num);
			}
				
		}
		
		REPN(i, 1, n) if (vote[i][0] == 0 || liked[i] == 0) {
			ans[i] = 1;
			q.push(i);
		}

		while (!q.empty()) {
			int top = q.front(); q.pop();
			REPN(i, 1, vote[top][0]) {
				if (!ans[liked[vote[top][i]]] && liked[vote[top][i]] > 0) {
					liked[vote[top][i]]--;
					if (liked[vote[top][i]] == 0) {
						ans[vote[top][i]] = 1;
						q.push(vote[top][i]);
					}
				}
			}
			REP(i, fans[top].size()) if (!ans[fans[top][i]]) {
				ans[fans[top][i]] = 1;
				q.push(fans[top][i]);
			}
		}

		int left = 0;
		REPN(i, 1, n) if (!ans[i]) left++;
		printf("%d\n", left);

	}
    return 0;
}
