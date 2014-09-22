/*
#Problem ID: 3279
#Submit Time: 2013-08-19 15:07:40
#Run Time: 200
#Run Memory: 620
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

int n, k, a[111111], x, y;
char c;

int lb(int num) {
    return num & (-num);
}

int ask(int num) {
    int ret = 0;
    while (num) {
        ret += a[num];
        num -= lb(num);
    }
    return ret;
}

int update(int num, int v) {
    while (num <= n) {
        a[num] += v;
        num += lb(num);
    }
}


int main()
{
    //freopen("0.in", "r", stdin);
    while (~scanf(" %d ", &n)) {
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; ++i) {
            int v; v = read_int(); //scanf(" %d", &v);
            update(i, v);
        }
        scanf(" %d ", &k);
        for (int i = 0; i < k; ++i) {
            scanf(" %c ", &c);
            if (c == 'p') {
                //scanf("%d%d", &x, &y);
                x = read_int(); y = read_int();
                int xx = ask(x) - ask(x-1);
                update(x, -xx); update(x, y);
            }
            else {
                x = read_int(); //scanf("%d", &x);
                int ans = 1, l = 1, r = n, m;
                while (l < r + 1) {
                    m = l + r >> 1;
                    int cnt = ask(m);
                    if (cnt < x) {
                        l = m + 1;
                        ans = m + 1;
                    } else if (cnt >= x) {
                        r = m - 1;
                    }
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}