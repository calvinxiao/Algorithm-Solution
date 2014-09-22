/*
#Problem ID: 2795
#Submit Time: 2013-08-19 23:52:11
#Run Time: 80
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
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

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

const int MAX = 100001;
int n;
int a[MAX];
int cnt, t;
int main()
{
    //freopen("0.in", "r", stdin);
    while(scanf(" %d ", &n) && n) {
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            //scanf("%d", &t);
            t = read_int();
            if (t == i) {
                ++cnt;
            }
            else if (t > i) {
                a[t] = i;
                a[i] = t;
            }
            else {
                if (a[t] == i)
                    cnt += 2;
            }
        }


        if (cnt == n)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
    }

    return 0;
}