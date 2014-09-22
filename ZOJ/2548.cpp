/*
#Problem ID: 2548
#Submit Time: 2012-05-30 00:51:56
#Run Time: 170
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
#include<sstream>
#include<string.h>
using namespace std;
#define local 1
int main()
{
    int couse[101];
    int catalog[101];
    bool choose[10001];


    int k, m, c, r;

    while(1)
    {
        cin >> k;
        if(k != 0)
        {
            bool fail = false;

            memset(choose, 0, sizeof choose);
            cin >> m;
            int temp;
            for(int i = 0; i < k; ++i)
            {
                cin >> temp;
                choose[temp] = true;
            }


            for(int i = 0; i < m; ++i)
            {
                cin >> c;
                cin >> r;
                int count = 0;
                for(int j = 0; j < c; ++j)
                {
                    cin >> couse[j];
                    if(choose[couse[j]]) count++;
                }

                if(count < r)
                {
                    //cout<<"no"<<endl;
                    //goto casefinish;
                    fail = true;
                }

            }

            if(fail) cout<<"no"<<endl;
            else   cout<<"yes"<<endl;


        }
        else break;
    }

    //printf("%d",' ');
    return 0;
}
