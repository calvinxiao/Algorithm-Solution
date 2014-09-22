/*
#Problem ID: 2734
#Submit Time: 2012-08-22 01:16:23
#Run Time: 0
#Run Memory: 196
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<memory.h>
using namespace std;
int N, M;
int f[1002], ff[1002];
int main()
{

    int tc = 0;
    while(cin >> N >> M) {
        memset(f, 0, sizeof f);
        memset(ff, 0, sizeof ff);
        f[0] = 1;
        ff[0] = 1;
        for(int i = 0; i < M; ++i) {
            int val, num;
            cin >> val >> num;
            for(int j = 1; j <= num; ++j) {
                int k = j * val;
                if(k > N) break;
                for(int nn = N; nn - k >= 0; --nn) {
                    ff[nn] += f[nn - k];
                }
            }
            for(int j = 1; j <= N; ++j) f[j] += ff[j], ff[j] = 0;
        }

        if(tc != 0)
            cout << endl;
        tc += 1;
        cout << f[N] << endl;
    }
    return 0;
}
