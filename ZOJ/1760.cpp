/*
#Problem ID: 1760
#Submit Time: 2012-09-17 13:36:11
#Run Time: 0
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<algorithm>

using namespace std;
int n,i,j,k,a[20], ans;
int main() {
    while(1) {
        k = 0;
        ans = 0;
        while(1) {
            cin >> a[k];
            if(a[k] == -1) return 0;
            if(a[k] == 0) {break;}
            k += 1;
        }

        for( i = 0; i < k; ++i) {
            if(a[i] % 2 == 0) {
                for(j = 0; j < k; ++j) {
                    if(a[j] == a[i] / 2) ans += 1;
                }
            }
        }

        cout << ans << endl;
    }
}
