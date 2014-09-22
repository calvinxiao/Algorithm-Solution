/*
#Problem ID: 3516
#Submit Time: 2012-09-20 03:12:22
#Run Time: 200
#Run Memory: 416
#ZOJ User: calvinxiao
*/

/**
Calvin's Code
*/
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;

int n, m, p[10100], v[10100][3], stk[10100], top, parent, sp, t, next[10010];



int main() {
    while(scanf("%d", &n) != EOF) {
        memset(next, 0, sizeof next);
        vector<int> c[11000];
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < 3; ++j)
        v[i][j] = -1;

        scanf("%d", &v[0][0]);
        sp = -1;
        for(int i = 1; i < n; ++i) {
            scanf("%d%d", &t, &v[i][0]);
            //cin >> t >> v[i][0];
            c[t].push_back(i);
        }

        stk[++sp] = 0;
        while(sp != -1) {
            top = stk[sp];
            if(next[top] < c[top].size()) {
                stk[++sp] = c[top][next[top]++];
            }
            else {
                //get out then update parent
                if(top != 0) {
                    sp--;
                    parent = stk[sp];
                    for(int i = 0; i < 3; ++i) {
                        if(v[top][i] > v[parent][2]) {
                            v[parent][2] = v[top][i];
                            //sort(v[parent], v[parent] + 3, greater<int>());
                            if(v[parent][2] > v[parent][1]) {
                                t = v[parent][2];
                                v[parent][2] = v[parent][1];
                                v[parent][1] = t;

                                if(v[parent][1] > v[parent][0]) {
                                    t = v[parent][1];
                                    v[parent][1] = v[parent][0];
                                    v[parent][0] = t;

                                }
                            }
                        }
                    }

                }
                else
                    break;
            }
        }

        scanf("%d", &m);
        //cin >> m;
        for(int i = 0; i < m; ++i) {
            scanf("%d", &t);
            //cin >> t;
            if(v[t][2] == -1) puts("-1");
            else printf("%d %d %d\n", v[t][0], v[t][1], v[t][2]);
        }


    }
    return 0;
}
