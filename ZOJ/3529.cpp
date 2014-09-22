/*
#Problem ID: 3529
#Submit Time: 2013-10-14 10:46:11
#Run Time: 3300
#Run Memory: 20120
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

const int N = 100005;
const int P = 5000005;
int p[P], prime[3000], pcnt, tc, n, c[N];

int factorCnt(int num) {
  int cnt = 0;
  for (int i = 0; i < pcnt && prime[i] * prime[i] <= num; i++) {
    while (num % prime[i] == 0) {
      cnt++;
      num /= prime[i];
    }
    if (num == 1)
      break;
  }
  if (num != 1)
    cnt++;
  return cnt;
}

void init() {
  p[0] = p[1] = 1;
  int sp = (int) sqrt(P);
  for (int i = 4; i <= sp; i += 2) p[i] = 1;
  for (int i = 3; i <= sp; i += 2) {
    if (!p[i]) {
      for (int j = i + i; j < sp; j += i)
        p[j] = 1;
    }
  }
  prime[pcnt++] = 2;
  for (int i = 3; i < sp; i += 2)
    if (!p[i])
      prime[pcnt++] = i;

}

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



int main() {
#ifndef ONLINE_JUDGE
  freopen("0.in", "r", stdin);
#endif
  init();
  //printf("%d\n", pcnt);
  while (~scanf(" %d ", &n)) {
    tc++;
    printf("Test #%d: ", tc);
    int x = 0, maxV = 0, maxI = 0;
    REP(i, n) {
      int num; num = read_int();
      //scanf("%d", &num);
      c[i] = factorCnt(num);
      //c[i] = fc[num];
      x ^= c[i];
    }

    if (x) {
      for (int i = 0; i < n; i++) {
        if ( (x ^ c[i]) < c[i]) {
          maxI = i + 1;
          break;
        }
      }
      printf("Alice %d\n", maxI);
    } else
      printf("Bob\n");
  }
  return 0;
}
