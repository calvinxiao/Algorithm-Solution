/*
#Problem ID: 3114
#Submit Time: 2013-04-19 00:55:41
#Run Time: 230
#Run Memory: 2696
#ZOJ User: calvinxiao
*/

/**
Calvin's Code
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;


int a, b;

int main() {
    //freopen("0.in", "r", stdin);
    int cmd;
    set<int> s1;
    set<int, greater<int> > s2;
    map<int, int> k;
    while (~scanf("%d",&cmd)) {
        //cout << cmd << endl;
        if (cmd == 0) {
            s1.clear();
            s2.clear();
        } else if (cmd == 1) {
            scanf("%d%d", &a, &b);
            k[b] = a;
            s1.insert(b);
            s2.insert(b);
        } else if (cmd == 2) {
            // highest
            if (s1.size() == 0) {
                printf("0\n");
            }
            else {
                b = *(s2.begin());
                printf("%d\n", k[b]);
                s1.erase(s1.find(b));
                s2.erase(s2.begin());
            }
        } else if (cmd == 3) {
            if (s1.size() == 0) {
                printf("0\n");
            }
            else {
                b = *(s1.begin());
                printf("%d\n", k[b]);
                s2.erase(s2.find(b));
                s1.erase(s1.begin());
            }
        }
    }
    return 0;
}
