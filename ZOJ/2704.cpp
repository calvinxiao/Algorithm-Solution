/*
#Problem ID: 2704
#Submit Time: 2012-09-18 17:09:54
#Run Time: 190
#Run Memory: 536
#ZOJ User: calvinxiao
*/

/**
Calvin's Code
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;

bool v[100005], hasans;
int n, temp;
int main() {
    string s;
    while(cin >> s) {
        //cout << s << endl;
        hasans = false;
        n = s.size();
        memset(v, 0, sizeof v);
        int prei = 0, prej = -1, tempi = 1, tempj = 0, tempans = 0, ans = 0;

        for(int i = 0; i < n - 1; ++i) {
            if(!v[i] && !v[i+1] && ( (s[i] == '[' && s[i+1] == ']') || (s[i] == '(' && s[i+1] == ')'))) {
                v[i] = 1;
                v[i+1] = 1;
                hasans = true;
            }
        }

        bool flag = true;
        while(flag) {
            flag = false;
            for(int i = 0; i < n; ++i) {
                if(v[i]) {
                    int l = i + 1;
                    while(l < n && v[l]) {
                        l++;
                    }
                    temp = l - 1;
                    l = i - 1;
                    int r = temp + 1;
                    while(l >= 0 && r < n) {
                        if(!v[l] && !v[r] && (s[l] == '[' && s[r] == ']') || (s[l] == '(' && s[r] == ')')) {
                            flag = true;
                            v[l] = 1;
                            v[r] = 1;
                            l--;
                            r++;
                        } else
                            break;
                    }
                    i = r - 1;
                }
            }
        }

        if(hasans) {
            temp = 0;
            ans = 0;
            for(int i = 0; i < n; ++i) {
                if(!v[i]) {
                    if(ans < temp) {
                        ans = temp;
                        prei = tempi;
                        prej = tempj;
                    }
                    tempi = 1;
                    tempj = 0;
                    temp = 0;
                }
                else {
                    if(tempi > tempj) {
                        tempi = i;
                        tempj = i;
                        temp += 1;
                    }
                    else {
                        tempj = i;
                        temp += 1;
                    }
                }
            }

            if(ans < temp) {
                ans = temp;
                prei = tempi;
                prej = tempj;
            }
            //cout << prei << ' ' << prej << endl;
            for(int i = prei; i <= prej; ++i) {
                cout << s[i];
            }
            cout << endl << endl;
        }
        else
            cout << endl << endl;
    }
    return 0;
}
