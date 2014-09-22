/*
#Problem ID: 2136
#Submit Time: 2012-08-14 18:21:03
#Run Time: 0
#Run Memory: 196
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 1001;
int a[MAX];
int b[MAX];
int N;

int main() {
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; ++c) {
        int ans = 1;
        cin >> N;
        for(int i = 0; i < N; ++i) {
            cin >> a[i];
            b[i] = 1;
        }
        for(int i = 0; i < N; ++i) {
            for(int j = i + 1; j < N; ++j) {
                if(a[i] < a[j]) {
                    b[j] = max(b[j], b[i] + 1);
                    ans = max(ans, b[j]);
                }
            }
        }

        if(c != 0) cout << endl;
        cout << ans << endl;
    }

    return 0;
}
