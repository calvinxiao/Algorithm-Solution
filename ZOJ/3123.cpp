/*
#Problem ID: 3123
#Submit Time: 2013-08-19 23:30:05
#Run Time: 20
#Run Memory: 576
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
#define FORE(itr, e) for(__typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

typedef long long LL;

using namespace std;

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


const int MAX = 100002;
int tc, n, s, a[MAX], ans;

int main()
{
    //freopen("0.in", "r", stdin);
    scanf(" %d ", &tc);
    while (tc--) {
        scanf(" %d %d ", &n, &s);
        ans = 0;
        REP(i, n) {
            //scanf("%d", &a[i]);
            a[i] = read_int();
            ans += a[i];
            //a[i] += a[i-1];
        }

        if (ans < s)
            ans = 0;
        else {
            ans = n;
            int i = 0, j = 0, sum = 0;
            while (j < n) {
                while (sum < s && j < n) {
                    sum += a[j]; j++;
                }
                while (sum >= s) {
                    if (ans > j - i)
                        ans = j - i;
                    sum -= a[i];
                    i++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}