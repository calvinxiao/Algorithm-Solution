/*
#Problem ID: 3230
#Submit Time: 2012-12-07 16:20:40
#Run Time: 150
#Run Memory: 1332
#ZOJ User: calvinxiao
*/

#include <stdio.h>
int n, m, p;
int a[100050], b[100050];
int h[100050], e;

void insert(int x) {
    int temp, cur, parent;
    h[++e] = x;
    cur = e;
    parent = cur >> 1;
    while(1 < cur && h[parent] < h[cur]) {
        temp = h[cur]; h[cur] = h[parent]; h[parent] = temp;
        cur = parent;
        parent = cur>>1;
    }
}

void heapify(int idxx, int size) {
    int l, r, largest = idxx, idx = idxx;
    do {
        idx = largest;
        l = idx << 1;
        r = idx << 1 | 1;

        if (l < size && h[idx] < h[l])
            largest = l;

        if(r < size && h[largest] < h[r])
            largest = r;

        if(largest != idx) {
            int temp = h[largest];
            h[largest] = h[idx];
            h[idx] = temp;
        }
    } while(largest != idx);
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
    /*freopen("0.in", "r", stdin);*/
    int i;
    while(~scanf(" %d %d %d", &n, &m, &p)) {
        for(i = 0; i < n; ++i)
            scanf(" %d %d", a+i, b+i);
        Sort(0, n-1);
        i = 0;
        e = 0;
        ++m;
        while(--m) {
            while(a[i] <= p && i < n) {
                int temp, cur, parent;
                h[++e] = b[i];
                cur = e;
                parent = cur >> 1;
                while(1 < cur && h[parent] < h[cur]) {
                    temp = h[cur]; h[cur] = h[parent]; h[parent] = temp;
                    cur = parent;
                    parent = cur>>1;
                }
                ++i;
            }
            if(e > 0) {
                p += h[1];
                h[1] = h[e];
                --e;
                int l, r, largest = 1, idx = 1;
                do {
                    idx = largest;
                    l = idx << 1;
                    r = idx << 1 | 1;

                    if (l < e+1 && h[idx] < h[l])
                        largest = l;

                    if(r < e+1 && h[largest] < h[r])
                        largest = r;

                    if(largest != idx) {
                        int temp = h[largest];
                        h[largest] = h[idx];
                        h[idx] = temp;
                    }
                } while(largest != idx);
            } else {
                break;
            }
        }
        printf("%d\n", p);
    }
    return 0;
}
