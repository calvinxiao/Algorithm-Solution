/*
#Problem ID: 2725
#Submit Time: 2013-03-28 21:57:10
#Run Time: 390
#Run Memory: 27532
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

const int BIG = (int)1e9 + 7;
const int MAX = 16;

int dp[7][1000000];
int ten[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int len;
int toInt(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

int main() {
    //freopen("0.in", "r", stdin);
    //dp
    for (len = 1; len < 7; ++len) {
        for (int i = 0; i < ten[len]; ++i) {
            if (i < ten[len-1]) {
                dp[len][i] = 1;
                continue;
            }
            int &r = dp[len][i];
            for (int j = 0; !r && j < len; ++j) {
                int t = i / ten[j] % 10;
                for (int k = 1; k <= t; ++k) {
                    if (!dp[len][i - ten[j] * k]) {
                        r = 1;
                        break;
                    }
                }
            }

            if (!r) {
                for (int j = len - 2; j >= 0; --j) {
                    int t = i / ten[j] % 10;   
                    if (t == 0) {
                        int newT = i / ten[j+1];
                        int newLen = len - j - 1;
                        if (!dp[newLen][newT]) {
                            dp[len][i] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }


    //
    string s;
    while(cin >> s) {
        len = s.size();
        printf("%s\n", dp[len][toInt(s)]?"Yes":"No");
    }
    
    return 0;
}
