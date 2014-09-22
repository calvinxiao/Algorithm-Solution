/*
#Problem ID: 1926
#Submit Time: 2012-09-18 16:32:43
#Run Time: 0
#Run Memory: 160
#ZOJ User: calvinxiao
*/

#include<stdio.h>
int main() {
    int n, a = 1, b = 10, t = 1;
    char c[10], d[10];
    while(1) {
        scanf(" %d", &n);
        if(!n) break;
        scanf(" %s %s", c, d);
        if(d[0] == 'h') {
            if(n > b) continue;
            b = n - 1;
            if(a > b) t = 0;
        }
        else if(d[0] == 'l') {
            if(n < a) continue;
            a = n + 1;
            if(a > b) t = 0;
        }
        else {
            if(n < a || n > b) t = 0;
            if(t) printf("Stan may be honest\n");
            else  printf("Stan is dishonest\n");
            a = 1; b = 10; t = 1;
        }
    }

    return 0;
}
