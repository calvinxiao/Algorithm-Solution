/*
#Problem ID: 2883
#Submit Time: 2012-10-08 17:12:15
#Run Time: 80
#Run Memory: 264
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
int a[20005];

int main()
{

	int tc, n, sum;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &n);
		sum = 0;
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n, greater<int>());
		for(int i = 2; i < n; i += 3) sum += a[i];
		printf("%d\n", sum);
	}
	return 0;
}
