/*
#Problem ID: 1484
#Submit Time: 2012-10-07 22:50:24
#Run Time: 230
#Run Memory: 208
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

int a[5555];

int main()
{
    int n;
    //printf("%d\n", EOF);
    while(~scanf("%d", &n)) {
        int sum = 0;
        set<int> s;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            s.insert(i);
        }
        set<int>::iterator lb;
        for(int i = 0; i < n; ++i) {
            lb = s.lower_bound(a[i]);
            sum += (int)distance(s.begin(), lb);
            s.erase(a[i]);
        }
        //s.clear();
        //cout << sum << endl;
        int ret = sum;
        for(int i = 0; i < n; ++i) {
            sum += -a[i] + (n - 1 - a[i]);
            ret = min(ret, sum);
        }
        printf("%d\n", ret);
    }
    return 0;
}