/*
#Problem ID: 2207
#Submit Time: 2013-06-30 21:03:35
#Run Time: 20
#Run Memory: 188
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

const int MAX = 100;

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("0.in", "r", stdin);
    #endif
    string s = "ABCDE";
    vector<string> ls;
    do {
        ls.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    int n;
    while (cin >> n && n) {
        vector<string> inp;
        REP(i, n) {
            string t;
            cin >> t;
            inp.push_back(t);
        }
        string ans;
        int ansv = (int)1e9;
        REP(i, ls.size()) {
            s = ls[i];
            int v = 0;
            REP(j, inp.size()) {
                string t = inp[j];
                REP(i, s.size()) {
                    for (int j = i + 1; j < s.size(); j++) {
                        int a, b;
                        REP(k, t.size()) {
                            if (t[k] == s[i])
                                a = k;
                            if (t[k] == s[j])
                                b = k;
                        }
                        if (a > b)
                            v++;
                    }
                }
            }
            if (v < ansv) {
                ansv = v;
                ans = s;
            }
        }
        printf("%s is the median ranking with value %d.\n", ans.c_str(), ansv);
    }
    return 0;
}
