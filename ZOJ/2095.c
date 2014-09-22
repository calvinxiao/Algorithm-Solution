/*
#Problem ID: 2095
#Submit Time: 2012-12-06 11:13:38
#Run Time: 2840
#Run Memory: 160
#ZOJ User: calvinxiao
*/

#include <stdio.h>
#include <math.h>

int main() 
{

    int tc, n, i, j, k, sum;
    int sq;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        if(n == 1) 
            sum = 0;
        else if(n < 4)
            sum = 1;
        else {
            sum = 0;
            sq = (int)sqrt((double)n);
            int add = 1;
            if(n&1) add = 2;
            for(i = 1; i <= sq; i += add) {
                if(n%i == 0) {
                    sum += i;
                    k = n / i;
                    sum += k;
                }
            }

            if(sq * sq == n) sum -= sq;
            sum -= n;
        }
        printf("%d\n", sum);
    }
    

    return 0;
}