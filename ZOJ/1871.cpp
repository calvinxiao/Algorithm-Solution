/*
#Problem ID: 1871
#Submit Time: 2012-09-06 17:10:39
#Run Time: 30
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<vector>
#include<string>
#include<memory.h>
#include<cmath>
using namespace std;
int n, a, b, step, ans, temp;
int main()
{
    while(cin >> a >> b) {
        n = b - a;
        step = 1;
        ans = 0;
        while(n >= step) {
            temp = step + step;
            if(n >= temp) {
                n -= temp;
                step += 1;
                ans += 2;
            }
            else {
                n -= step;
                step += 1;
                ans += 1;
            }
        }

        if(n != 0)
            ans += 1;
        cout << ans << endl;
    }
    return 0;
}
