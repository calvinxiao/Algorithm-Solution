/*
#Problem ID: 1549
#Submit Time: 2013-07-02 09:01:23
#Run Time: 10
#Run Memory: 188
#ZOJ User: calvinxiao
*/

/**
Calvin Xiao
calvin.xiao at scaurugby.com
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std ;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPN(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define REPI(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

long long func(long long n, long long num, vector<long long> &ln) {
	int nLength = ln.size();
	long long ret = 0, ten = 10;
	while (num * ten <= n) {
		long long nt = num * ten;
		long long L = 0, R = ten - 1;
		long long toadd = -1;
		if (nt + ten - 1 <= n)
            toadd = ten - 1;
        else
            while (L <= R) {
                long long mid = L + R >> 1;
                if (num * ten + mid <= n) {
                    toadd = mid;
                    L = mid + 1;
                } else
                    R = mid - 1;
            }
		ret += toadd + 1;
		ten *= 10LL;
	}
	return ret + 1;
}

long long get(long long n, long long k, vector<long long> &ln, vector<long long> &lk) {
	long long ret = 0;
	int kLength = lk.size();
	long long num = 0;
	for (int i = 0; i < kLength; ++i) {
		num *= 10;
		int start = 0;
		if (i == 0)
			start = 1;
		for (long long j = start; j < lk[i]; ++j) {
			ret += func(n, num+j, ln);
		}
		num += lk[i];
	}
	return ret + kLength;
}


int main()
{
    //freopen("amusing.in", "r", stdin);
    //freopen("amusing.out", "w", stdout);
    long long K, M;
    while (~scanf("%lld%lld", &K, &M)) {
    	vector<long long> lk;
    	long long kk = K;
    	while (kk != 0)
    		lk.push_back(kk % 10LL), kk /= 10LL;
    	reverse(lk.begin(), lk.end());
    	long long L = K, R = (long long)1e18;
    	long long ans = 0;
    	while (L <= R) {
    		long long mid = L + R >> 1;
    		vector<long long> ln;
    		long long nn = mid;
    		while (nn != 0)
    			ln.push_back(nn % 10LL), nn /= 10LL;
    		long long ret = get(mid, K, ln, lk);
    		if (ret >= M) {
    			R = mid - 1;
    			if (ret == M)
    				ans = mid;
    		} else
    			L = mid + 1;
    	}
    	printf("%lld\n", ans);
    }
    return 0;
}
