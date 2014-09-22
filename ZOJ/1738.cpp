/*
#Problem ID: 1738
#Submit Time: 2013-03-09 18:52:34
#Run Time: 40
#Run Memory: 820
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPN(i, a, n) for(int (i) = (int)(a); (i) <= (n); ++(i))
#define FORE(itr, e) for(typeof(e.begin) itr = e.begin(); itr != e.end(); itr++)

using namespace std;

const int MAX = 1<<15;

int n;
int a[MAX][5];

int main()
{
	//freopen("0.in", "r", stdin);
	a[0][0] = 1;
    vector<int> sq;
    int root = 0;
    while (++root) {
        if (root *root > MAX)
            break;
        sq.push_back((root*root));
    }
    for (int k = 0; k < sq.size(); ++k) {
        for (int i = 0; i < min(sq[k] * 3 + 1, MAX - sq[k]); ++i) {
            for (int j = 0; j < 4; ++j) if (a[i][j]) {
                a[i+sq[k]][j+1] += a[i][j];
            }
        }
    }
	while (~scanf("%d", &n) && n) {
		int ans = 0;
		for (int i = 1; i < 5; ++i)
            ans += a[n][i];
        printf("%d\n", ans);
	}
    return 0;
}
