/*
#Problem ID: 1001
#Submit Time: 2012-11-21 09:47:36
#Run Time: 0
#Run Memory: 35344
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

using namespace std;

const int MAX = 3000;

int a[MAX][MAX];

int main()
{
	//freopen("0.in", "r", stdin);
	while(cin >> a[0][0] >> a[0][1])
		cout << a[0][0] + a[0][1] << endl;
    return 0;
}
