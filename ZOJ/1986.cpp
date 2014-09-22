/*
#Problem ID: 1986
#Submit Time: 2012-08-08 01:31:46
#Run Time: 50
#Run Memory: 500
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
using namespace std;
int a[40000],D[40000];
int binarySearch(int x,int len) {
    if(a[x] < D[1])return 1;
    int low = 1,top = len,mid;
    while(low != top - 1) {
        mid = (low + top) >> 1;
        if(D[mid] < a[x])low = mid;
        else top = mid;
    }
    return top;
}
int main() {
    int n,p,k;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&p);
        for(int i = 0; i < p; i++)
            scanf("%d",&a[i]);
        D[k = 1] = a[0];
        for(int i = 1; i < p; i++) {
            if(a[i] > D[k])D[++k] = a[i];
            else D[binarySearch(i,k)] = a[i];
        }
        printf("%d\n",k);
    }
//system("pause");
    return 0;
}
