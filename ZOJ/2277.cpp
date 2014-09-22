/*
#Problem ID: 2277
#Submit Time: 2012-08-20 01:33:19
#Run Time: 1370
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cmath>
#include<memory.h>
using namespace std;

double todo(double num, int power) {
    double c;
    if(power == 1)
        c = num;
    else if(power == 2)
        c = num * num;
    else {
        double a = todo(num, power / 2);
        double b = a;
        if (power % 2 == 1)
            b *= num;
        c = a * b;
    }

    while(c > 10.0)
        c /= 10.0;
    return c;
}

int main()
{
    long long n, m, x;
    while(cin >> n) {
        m = (long long)(n * log10((double)n));
        double t = n * log10((double)n) - m;
        x = pow(10.0, t);
        cout << (long long)x << endl;
    }
//    int n;
//    while(cin >> n) {
//        double nn = 1.0 * n;
//        while(nn > 10.0)
//            nn /= 10.0;
//        cout << (int)todo(nn, n) << endl;
//    }
    return 0;
}
