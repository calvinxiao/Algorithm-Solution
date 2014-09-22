/*
#Problem ID: 2876
#Submit Time: 2013-02-26 13:16:21
#Run Time: 200
#Run Memory: 488
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 10005

int t, n;
char c[12];
string s[MAX];

int main()
{
    //freopen("in.in", "r", stdin);
	scanf("%d", &t);
	while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", c);
            s[i] = string(c);
        }

        sort(s, s + n);
        bool good = true;
        for (int i = 1; i < n; ++i) {
            if (s[i-1].size() < s[i].size()) {
                string ss = s[i].substr(0, s[i-1].size());
                if (s[i-1] == ss) {
                    good = false;
                    break;
                }
            }
        }

        if (good)
            puts("YES");
        else
            puts("NO");
	}
	return 0;
}
