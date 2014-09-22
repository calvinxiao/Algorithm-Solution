/*
#Problem ID: 2835
#Submit Time: 2012-09-09 23:17:52
#Run Time: 0
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
int n, constant, temp;
int g[10][10];
bool v[1001];
bool yes;
int main()
{
    while(1) {
        yes = true;
        memset(v, 0, sizeof v);
        cin >> n;
        if(!n) break;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> g[i][j];

                if(!v[g[i][j]])
                    v[g[i][j]] = 1;
                else
                    yes = false;
            }
        }

        constant = 0;
        for(int i = 0; i < n; ++i) {
            constant += g[i][0];
        }

        for(int i = 0; i < n; ++i) {
            temp = 0;
            for(int j = 0; j < n; ++j)
                temp += g[i][j];
            if(temp != constant) {
                yes = false;
                break;
            }
        }

        for(int i = 0; i < n; ++i) {
            temp = 0;
            for(int j = 0; j < n; ++j)
                temp += g[j][i];
            if(temp != constant) {
                yes = false;
                break;
            }
        }

        temp = 0;
        for(int i = 0; i < n; ++i) {
            temp += g[i][i];
        }
        if(temp != constant) yes = false;

        temp = 0;
        for(int i = n - 1; i >= 0; --i)
                temp += g[i][n - i - 1];
        if(temp != constant) yes = false;

        if(yes) cout << "Yes\n";
        else    cout << "No\n";

    }
    return 0;
}
