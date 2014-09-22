/*
#Problem ID: 1331
#Submit Time: 2013-02-27 07:44:44
#Run Time: 70
#Run Memory: 31908
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

#define REP(i, n) for(int (i) = 0; (i) < (int)(n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int BIG = (int)1e9 + 7;

const int MAX = 201*201*201;
int cube[201], a, b, c, d, p, product[MAX];
pair<int, vector<int> > pa[256];

int main()
{
	//freopen("0.in", "r", stdin);
	for (a = 2; a <= 200; ++a) {
        cube[a] = a*a*a;
        product[cube[a]] = a;
    }
        
    int cnt = 0;
    for (int i = 2; i <= 200; ++i) {
        for (int j = i+1; j <= 200; ++j) {
            for (int k = j+1; k <= 200; ++k) {
                p = cube[i] + cube[j] + cube[k];
                if (p > MAX)
                    continue;
                if (product[p]) {
                    vector<int> v; v.push_back(i); v.push_back(j); v.push_back(k);
                    pa[cnt++] = make_pair(product[p], v);
                }
            }
        }
    }
    sort(pa, pa + cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("Cube = %d, Triple = (%d,%d,%d)\n", pa[i].first, pa[i].second[0], pa[i].second[1], pa[i].second[2]);
    }

}
