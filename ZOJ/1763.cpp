/*
#Problem ID: 1763
#Submit Time: 2012-09-17 13:42:09
#Run Time: 0
#Run Memory: 180
#ZOJ User: calvinxiao
*/

#include<cstdio>
#include<algorithm>

using namespace std;
double pre, cur;
int main() {
    scanf("%lf", &pre);
    while(1) {
        scanf("%lf", &cur);
        if(cur == 999.0) break;
        printf("%.2f\n", cur - pre);
        pre = cur;
    }

    printf("End of Output\n");
}
