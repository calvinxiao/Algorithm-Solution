/*
#Problem ID: 3301
#Submit Time: 2012-11-27 16:19:24
#Run Time: 30
#Run Memory: 272
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

#define PARENT_CNT 300205
#define MAX 20000005

int n, a[11111], id[11111];

void Sort(int l, int r) {
	int i = l, j = r, x = a[(l + r) >> 1], t;
	do {
		while(a[i] < x) i++;
		while(x < a[j]) j--;
		if(i <= j) {
			t = a[i]; a[i] = a[j]; a[j] = t;
			t = id[i]; id[i] = id[j]; id[j] = t;
			i++;
			j--;
		}
	} while(i <= j);
	if(l < j) Sort(l, j);
	if(i < r) Sort(i, r);
}

int main()
{

	//freopen("0.in", "r", stdin);
	bool first = true;
	while(~scanf("%d", &n)) {
		if(first)
			first = false;
		else
			puts("");

		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			id[i] = i;
		}
		Sort(1, n);
		for(int i = 1; i < n; i += 2)
			printf("%d %d\n", id[i], id[i+1]);
	}
	
    return 0;
}
