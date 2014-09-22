/*
#Problem ID: 1978
#Submit Time: 2012-10-10 11:10:36
#Run Time: 140
#Run Memory: 188
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

#define FOR(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

const int MAX = 34000;

int main()
{
	bool b[MAX];
	int next[MAX], pre[MAX], ans[3000];
	int cnt = 0;
	for(int i = 0; i < MAX; ++i) {
		b[i] = true;
		next[i] = i + 1;
		pre[i] = i - 1;
	}

	for(int i = 2; i < MAX; ++i) {
		if(b[i]) {
			cnt = 0;
			int j = i;
			while(next[j] < MAX && next[next[j]] < MAX) {
				j = next[j];
				cnt += 1;
				if(cnt % i == 0) {
					cnt = 0;
					b[j] = false;
					int x = next[j], y = pre[j];
					next[y] = x;
					pre[x] = y;
				}
			}
		}
	}

	cnt = 0;
	for(int i = 2; i < MAX; ++i) {
		if(b[i]) {
			ans[cnt++] = i;
			if(cnt == 3000)
				break;
		}
	}

	while(1) {
		int num;
		cin >> num;
		if(!num) break;
		cout << ans[num-1] << endl;
	}

    return 0;
}
