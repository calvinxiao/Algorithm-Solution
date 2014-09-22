/*
#Problem ID: 3471
#Submit Time: 2013-12-30 00:37:53
#Run Time: 20
#Run Memory: 284
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

int n, g[11][11], s[1<<11];
bool inq[1<<11];

inline int read_int(){
    int a=0;
    int b=1,c=getchar();
    if(c=='-')b=-1;
    else a=c-48;
    while((c=getchar())!=' '&&c!='\n')
        a=a*10+c-48;
    a*=b;
    return a;
}

int main()
{
  #ifndef ONLINE_JUDGE
		freopen("0.in", "r", stdin);
  #endif
  while (1) {
    n = read_int();
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        g[i][j] = read_int();
    memset(s, 0, sizeof s);
    memset(inq, 0, sizeof inq);
    int first = (1<<n) - 1;
    queue<int> q;
    q.push(first);
    inq[first] = 1;
    while (!q.empty()) {
      int top = q.front(); q.pop(); inq[top] = false;
      for (int i = 0; i < n; i++) {
        if ((1<<i) & top) {
          for (int j = i + 1; j < n; j++) {
            if ((1<<j) & top) {
              int next1 = top ^ (1 << i);
              int next2 = top ^ (1 << j);
              if (s[next1] < s[top] + g[j][i]) {
                s[next1] = s[top] + g[j][i];
                if (!inq[next1]) {
                  q.push(next1);
                  inq[next1] = 1;
                }
              }
              if (s[next2] < s[top] + g[i][j]) {
                s[next2] = s[top] + g[i][j];
                if (!inq[next2]) {
                  q.push(next2);
                  inq[next2] = 1;
                }
              }
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (ans < s[1<<i])
        ans = s[1<<i];
    printf("%d\n", ans);
  }
	return 0;
}
