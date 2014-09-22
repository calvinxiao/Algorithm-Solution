/*
#Problem ID: 3230
#Submit Time: 2012-12-07 14:48:02
#Run Time: 160
#Run Memory: 2388
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

const int MAX = 100;

int n, m, p;
//long long p;
int a[100050], b[100050];
int h[100050], e;

void insert(int x) {
    h[e++] = x;

}

void BitSort(int l, int r, int bit) {
    if(bit < 0) return;
    int i = l, j = r, temp;
    do {
        while(!(a[i] & (1<<bit))) i++;
        while(a[j] & (1<<bit)) j--;
        if(i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            i++;
            j--;
        }
    } while(i <= j);

    if(l < j) BitSort(l, j, bit - 1);
    if(i < r) BitSort(i, r, bit - 1);
}

void Sort(int l, int r) {
    int i = l, j = r, x = a[(l+r) >> 1], temp;
    do {
        while(a[i] < x) ++i;
        while(x < a[j]) --j;
        if(i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            ++i;
            --j;
        }
    } while(i <= j);

    while(l < j && a[j] == a[j-1]) --j;
    while(i < r && a[i] == a[i+1]) ++i;
    if(l < j) Sort(l, j);
    if(i < r) Sort(i, r);
}

int main() {
    //freopen("0.in", "r", stdin);
    while(~scanf("%d %d %d", &n, &m, &p)) {
        for(int i = 0; i < n; ++i)
            scanf("%d %d", a+i, b+i);
        //BitSort(0, n-1, 14);
        Sort(0, n-1);
        int i = 0;
        priority_queue<int, vector<int> > pq;
        while(m--) {
            while(a[i] <= p && i < n) {
                pq.push(b[i]);
                ++i;
            }
            if(!pq.empty()) {
                p += pq.top();
                pq.pop();
            } else {
                break;
            }
        }
        printf("%d\n", p);
    }
    return 0;
}
