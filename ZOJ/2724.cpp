/*
#Problem ID: 2724
#Submit Time: 2012-10-10 22:52:21
#Run Time: 1440
#Run Memory: 1388
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

struct msg{
	string s;
	int parm;
	int priority;
	int idx;
};

struct cmp {
	bool operator()(const msg &a, const msg &b) {
		if(a.priority > b.priority) return 1;
		if(a.priority == b.priority && a.idx > b.idx) return 1;
		return 0;
	}
};

int main()
{
	priority_queue<msg, vector<msg>, cmp> pq;
	string cmd;
	int idx = 0;
	while(cin >> cmd) {
		if(cmd[0] == 'G') {
			if(!pq.size())
				cout << "EMPTY QUEUE!\n";
			else {
				cout << pq.top().s << ' ' << pq.top().parm << endl;
				pq.pop();
			}
		}
		else {
			msg temp;
			cin >> temp.s >> temp.parm >> temp.priority;
			temp.idx = idx++;
			pq.push(temp);
		}
	}
    return 0;
}
