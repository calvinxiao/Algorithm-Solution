/*
#Problem ID: 1905
#Submit Time: 2012-09-17 23:25:06
#Run Time: 850
#Run Memory: 1724
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string s;
int i, j, k, n, n2, step;
bool flag;
int main()
{
    while(cin >> s && s != ".") {
        flag = true;
        n = s.size();
        n2 = n/2;
        step = 1;
        step += (n % 2);
        for(i = 1; i <= n2 && flag; i += step) {
            flag = false;
            if(n % i == 0) {
                for(j = 1; j <= n / i - 1 && !flag; ++j) {
                    for(k = 0; k < i && !flag; ++k) {
                        if(s[k] != s[j * i + k]) {
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag) {
                    cout << n / i << endl;
                    //cout << n << ' ' << i << endl;
                    break;
                }
            }

            flag = true;
        }

        if(flag) cout << 1 << endl;
    }

    return 0;
}
