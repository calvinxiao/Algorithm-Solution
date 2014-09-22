/*
#Problem ID: 3713
#Submit Time: 2014-04-10 14:45:37
#Run Time: 220
#Run Memory: 3204
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[3000005];

int main()
{
    //freopen("0.in", "r", stdin);
    int tc; scanf("%d", &tc);
    getchar();
    while (tc--) {
        gets(s);
        int n = strlen(s);
        int nn = n;
        if (nn == 0) printf("00");
        while (nn) {
          int t = nn % 128;
          nn /= 128;
          if (nn) t += 128;
          printf("%02X", t);
        }
        for (int i = 0; i < n; ++i)
        {
            printf("%02X", s[i]);
        }
        printf("\n");
    }
    return 0;
}
