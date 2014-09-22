/*
#Problem ID: 2954
#Submit Time: 2012-10-19 10:15:04
#Run Time: 70
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

using namespace std;

const int MAX = 100;

int main()
{
	int tc, n, m, a, b;
	cin >> tc;
	while(tc--) {
		cin >> n >> m;
		stack<int> stk[4];
		for(int i = 0; i < n; ++i) stk[1].push(i);
		int status = 0;
		// 0 normal, status > 0 is move that complete, status < 0 is the move that is invalid.
		for(int move = 1; move <= m; ++move) {
			cin >> a >> b;

			if(status == 0) {
				if(stk[a].size()) {

					int top = stk[a].top(); stk[a].pop();

					if(stk[b].empty() || stk[b].top() < top) {

						stk[b].push(top);
						if(stk[3].size() == n)
							status = move;
					}
					else
						status = -move;
				}
				else {
					status = -move;
				}
			}
		}

		cout << status << endl;
	}
    return 0;
}
