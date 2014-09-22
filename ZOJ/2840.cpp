/*
#Problem ID: 2840
#Submit Time: 2013-06-19 11:43:37
#Run Time: 30
#Run Memory: 296
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
#define BIG 1000000009;
using namespace std;
int dp[166][166];
int main()
{
    //freopen("0.in", "r", stdin);
    int n, m, tc = 0;
    while (~scanf("%d", &n)) {
        if (tc)
            cout << endl;
        tc++;
        vector<string> v1, v2;
        REP(i, n) {
            string s; cin >> s;
            v1.push_back(s);
        }
        scanf("%d", &m);
        REP(i, m) {
            string s; cin >> s;
            v2.push_back(s);
        }
        REP(j, m) {
            vector<string> ans;
            string t = v2[j];
            size_t starIdx = t.find('*');

            REP(i, n) {
                if (starIdx == string::npos && v1[i] == t) {
                    ans.push_back(v1[i]);
                    continue;
                }
                string tt = t;
                string s = v1[i];
                int ls = s.size();
                int lt = tt.size();
                if (lt <= ls) {
                    int cnt = ls - lt;
                    while (cnt--)
                        tt.insert(starIdx, "*");
                } else if (lt == ls + 1) {
                    tt.erase(starIdx, 1);
                } else
                    continue;
                //cout << s << endl;
                //cout << tt << endl;
                int good = 1;

                for (int ii = 0; ii < ls; ++ii) {
                    if (s[ii] != tt[ii] && tt[ii] != '*') {
                        good = 0;
                        break;
                    }
                }

                if (good)
                    ans.push_back(s);

//                string s = v1[i];
//                memset(dp, 0, sizeof dp);
//                int ls = s.size(), lt = t.size();
//                if (s[0] == t[0])
//                    dp[0][0] = 1;
//                if (t[0] == '*') {
//                    REP(ii, ls)
//                        dp[ii][0] = 1;
//                }
//                //cout << s << ' ' << t << ' ' << dp[0][0] << endl;
//                if (dp[0][0]) {
//                    for (int ii = 1; ii < ls; ++ii) {
//                        for (int jj = 1; jj < lt; ++jj) {
//                            if (dp[ii][jj])
//                                continue;
//                            if (s[ii] == t[jj] || t[jj] == '*') {
//                                dp[ii][jj] = dp[ii-1][jj-1];
//                                if (t[jj-1] == '*' && dp[ii][jj-1])
//                                    dp[ii][jj] = 1;
//                            }
//                            if (t[jj] == '*')
//                                if (dp[ii-1][jj])
//                                    dp[ii][jj] = 1;
//                            //printf("%c %c %d\n", s[ii], t[jj], dp[ii][jj]);
//                        }
//                    }
//                }
//                if (dp[ls-1][lt-1])
//                    ans.push_back(s);
            }
            if (ans.empty()) {
                cout << "FILE NOT FOUND\n";
            } else {
                cout << ans[0];
                for (int i = 1; i < ans.size(); ++i)
                    cout << ", " + ans[i];
                cout << endl;
            }
        }
    }
    return 0;
}
