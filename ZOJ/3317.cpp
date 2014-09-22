/*
#Problem ID: 3317
#Submit Time: 2014-05-19 10:37:39
#Run Time: 0
#Run Memory: 288
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

int n, m, ans[1024];
pair<pair<int, int>, int> p[1024];
set<int> roomsEmpty;
set<pair<int, int> > roomsOccupied;


int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  while (~scanf("%d%d", &n, &m)) {
    roomsEmpty.clear();
    roomsOccupied.clear();
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= m; i++)
      roomsEmpty.insert(i);
    for (int i = 0; i < n; i++) {
      int IN, OUT; scanf("%d%d", &IN, &OUT);
      p[i].first.first = IN;
      p[i].first.second = OUT;
      p[i].second = i;
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
      int IN = p[i].first.first, OUT = p[i].first.second;
      while (!roomsOccupied.empty()) {
        int o = (*roomsOccupied.begin()).first;
        if (o <= IN) {
          roomsEmpty.insert((*roomsOccupied.begin()).second);
          roomsOccupied.erase(roomsOccupied.begin());
        }
        else
          break;
      }
      if (!roomsEmpty.empty()) {
        int roomID = *roomsEmpty.begin();
        roomsEmpty.erase(roomsEmpty.begin());
        int outTime = p[i].first.second;
        int renderID = p[i].second;
        ans[renderID] = roomID;
        roomsOccupied.insert(make_pair(outTime, roomID));
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
  }
	return 0;
}
