/*
#Problem ID: 1101
#Submit Time: 2012-09-16 02:20:36
#Run Time: 40
#Run Memory: 192
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<algorithm>

using namespace std;
int n,i,j,k;
bool sign;
int a[1000];
int main() {

    cin>>n;
    while(n) {
        sign=true;
        for(i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n);
        for(i=n-1; i>=0&&sign; i--) {
            for(j=0; j<n&&sign; j++) {
                for(k=j+1; k<n&&sign; k++) {
                    if (i != j && i != k) {

                        int value = a[i] - a[j] - a[k];
                        if (value != a[i] && value != a[j] && value != a[k] && binary_search(a, a + n, value)) {

                            cout << a[i] << endl;
                            sign=false;
                        }
                    }
                }
            }
        }
        if(sign) cout<<"no solution"<<endl;
        cin>>n;
    }
    return 0;
}
