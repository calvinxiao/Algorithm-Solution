/*
#Problem ID: 2423
#Submit Time: 2012-09-20 14:05:35
#Run Time: 10
#Run Memory: 680
#ZOJ User: calvinxiao
*/

#include <stdio.h>
#include <memory.h>

char g[730][730];

void print(int x, int y, int len) {
    if(len == 1) g[x][y] = 1;
    else {
        print(x, y, len/3);
        print(x, y + 2*len/3, len/3);
        print(x + len/3, y + len/3, len/3);
        print(x + 2*len/3, y, len/3);
        print(x + 2*len/3, y + 2*len/3, len/3);
    }
}

int main() {
    int a[8] = {0, 1, 3, 9, 27, 81, 243, 729};
    int n, i, j, k, wb;
    while(scanf("%d", &n) && n != -1) {
        memset(g, 0, sizeof g);
        print(0, 0, a[n]);
        n = a[n];
        for(i = 0; i < n; ++i) {
            wb = 0;
            for(j = 0; j < n; ++j)
                if(g[i][j]) {
                    for(k = 0; k < wb; ++k)
                        printf(" ");
                    printf("X");
                    wb = 0;
                }
                else {
                    wb += 1;
                }
            printf("\n");
        }
        printf("-\n");
    }

    return 0;
}
