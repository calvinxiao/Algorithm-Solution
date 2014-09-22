/*
#Problem ID: 1366
#Submit Time: 2012-07-27 22:43:52
#Run Time: 50
#Run Memory: 576
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int f[100001];//数组下标用于说明包的容量，值说明该包在给定物品时能容纳的最大值

int s, num; //用于存放钞票面值及数量

int cash,n;

int main()

{
    //freopen("0.in", "r", stdin);

    int x,k;

    while(cin >>cash>>n)

    {
        memset(f, 0, sizeof f);
        
        for(int i=1; i<=n; i++)

        {

            cin >> num >> s;

            x=num;

            k=1;

            while(x)//将x张分成1.2.4.8...m张分别放（x=1+2+...+m,m不是2的幂），//这样更节省运行时间

            {
                int t;
                if(k > x)
                    k = x;

                t = s * k;
                x -= k;

                for(int j=cash; j>=t; j--)
                    if(f[j]<f[j-t]+t)
                        f[j]=f[j-t]+t;

                k*=2;

            }

        }

        cout << f[cash] << endl;//即为最大值

    }

    return 0;

}
