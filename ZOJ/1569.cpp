/*
#Problem ID: 1569
#Submit Time: 2013-08-19 23:49:59
#Run Time: 10
#Run Memory: 200
#ZOJ User: calvinxiao
*/

#include <cstdio>

using namespace std;

inline int read_int(){
    int a=0;
    int b=1,c=getchar();
    if(c=='-')b=-1;
    else a=c-48;
    while((c=getchar())!=' '&&c!='\n')
        a=a*10+c-48;
    a*=b;
    return a;
}

int s[5005], n, t, sum, ans, m, i;
int main()
{
    while (~scanf(" %d %d ", &n, &m)) {
        for (i = 0; i < m; ++i)
            s[i] = 0;
        sum = ans = 0;
        for (i = 0; i < n; ++i) {
            //scanf("%d", &t);
            t = read_int();
            sum += t;
            if (sum >= m)
                sum %= m;
            if (!sum)
                ++ans;
            ++s[sum];
        }
        sum = 0;
        for (int i = 0; i < m; ++i) {
            ans += (s[i] * (s[i] - 1)) >> 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}