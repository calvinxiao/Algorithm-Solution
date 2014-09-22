/*
#Problem ID: 2421
#Submit Time: 2012-08-19 22:11:06
#Run Time: 0
#Run Memory: 5088
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<memory.h>
using namespace std;

int main()
{
    //set<int> s;
    int *a = new int[500001];
    bool *b = new bool[3012501];
    memset(b, 0, sizeof b);
    b[0] = true;
    int k = 500001;
    //s.insert(0);
    int pre = 0, next;
    for(int i = 1; i < k; ++i) {
        next = pre - i;
        if(next > 0 && !b[next]) {
            ;
        }
        else {
            next = pre + i;
        }
        a[i] = next;
        b[next] = true;
        //s.insert(next);
        pre = next;
    }

    int n;
    while(1)  {
        cin >> n;
        if (n == -1) break;
        cout << a[n]<<endl;
    }
    delete a;
    delete b;
    return 0;
}
