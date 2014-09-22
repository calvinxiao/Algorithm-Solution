/*
#Problem ID: 2886
#Submit Time: 2012-09-09 23:03:16
#Run Time: 170
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
string s;
int tc;
int main()
{
    cin >> tc;
    while(tc --) {
        cin >> s;
        char pre = s[0];
        int cnt = 1;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == pre) cnt += 1;
            else {
                cout << cnt << pre;
                cnt = 1;
                pre = s[i];
            }
        }
        cout << cnt << pre;
        cout << endl;
    }
    return 0;
}
