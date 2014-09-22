/*
#Problem ID: 2744
#Submit Time: 2012-08-01 02:43:43
#Run Time: 60
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string S;
int doit() {
    int ans = S.size();
    int n = ans;
    for(int k = 0; k < n; ++k) {
        int i = k - 1, j = k + 1;
        while(i >= 0 && j < n && S[i] == S[j]) {
            ans += 1;
            i -= 1;
            j += 1;
        }
    }

    if(n > 1) {
        for(int k = 0; k < n - 1; ++k) {
            if(S[k] == S[k+1]) {
                ans += 1;
                int i = k - 1, j = k + 2;
                while(i >= 0 && j < n && S[i] == S[j]) {
                    ans += 1;
                    i -= 1;
                    j += 1;
                }
            }
        }
    }

    return ans;
}
int main()
{
    while(cin >> S) {
        cout << doit() << endl;
    }

    return 0;
}
