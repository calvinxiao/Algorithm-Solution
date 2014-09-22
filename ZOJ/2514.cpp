/*
#Problem ID: 2514
#Submit Time: 2012-08-22 02:09:04
#Run Time: 10
#Run Memory: 584
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<string>
#include<memory.h>
using namespace std;
int n;

int v[100000];
string s[1000][2];
int main()
{

    //cout<<dp[0][0]<<endl;
    while(1) {
        memset(v, 0, sizeof v);
        cin >> n;
        if(!n) break;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            cin >> s[i][0] >> s[i][1];
            for(int j = 0; j < s[i][1].size(); ++j) {
                if(s[i][1][j] == '1') s[i][1][j] = '@', v[i] = 1;
                else if(s[i][1][j] == '0') s[i][1][j] = '%', v[i] = 1;
                else if(s[i][1][j] == 'l') s[i][1][j] = 'L', v[i] = 1;
                else if(s[i][1][j] == 'O') s[i][1][j] = 'o', v[i] = 1;
            }
            if(v[i]) ans++;
        }

        if(ans > 0) {
            cout << ans << endl;
            for(int i = 0; i < n; ++i) {
                if(v[i]) {
                    cout << s[i][0] << ' ' << s[i][1] << endl;
                }
            }

        }
        else
            cout << "No account is modified." << endl;

    }
    return 0;
}
