/*
#Problem ID: 2239
#Submit Time: 2012-08-21 02:55:28
#Run Time: 10
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <string>

using namespace std;

string s;
int main()
{
    while(cin >> s) {
        int a, b, c, n;
        a = s[0] - '0', b = s[1] - '0', c = s[3] - '0';
        n = a * 10 + b;
        if(n == 0) break;
        for(int i = 0; i < c; ++i) n *= 10;
        int k = 1;
        int two = 1;
        for(int i = 0; i < 10000; ++i) {
            if(k > n) break;
            two *= 2;
            k += two;
        }
        //cout << k << endl;
        int remain = n - k + two;
        if(remain == 0) remain = n / 2;
        else remain -= 1;
        cout << remain * 2  + 1 << endl;
    }
    return 0;
}
