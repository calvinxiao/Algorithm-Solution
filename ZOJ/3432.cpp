/*
#Problem ID: 3432
#Submit Time: 2012-08-20 16:07:37
#Run Time: 910
#Run Memory: 204
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<memory.h>
#include<string>
#include<algorithm>
using namespace std;
string S;
int n, cnt;
char a[8];
int ans[7][600];
int main()
{
    //a[7] = '\0';
    while( cin >> n) {
        //cout << n << endl;
        memset(ans, 0, sizeof ans);
        getchar();
        cnt = 2 * n - 1;
        for(int i = 0; i < cnt; ++i) {
            char c;
            for(int j = 0; j < 7; ++j) scanf("%c", &c), ans[j][c] += 1;
            getchar();
        }
        for(int i = 0; i < 7; ++i)
            for(int j = 0; j < 600; ++j) {
                if(ans[i][j] % 2 == 1) {
                    printf("%c", (char)j);
                    break;
                }
            }
        cout << endl;
    }

    return 0;
}
