/*
#Problem ID: 2132
#Submit Time: 2012-09-10 14:51:26
#Run Time: 1160
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include <iostream>
using namespace std;

int n, ans, count, i, x;

int main()
{
    ans = 0; count = 0;
    while(cin >> n) {
	for(i = 0; i < n ;++i) {
	    cin >> x;
	    if(i == 0) {ans = x; count = 1;}
	    else if(x == ans) {
		count += 1;
	    }
	    else {
		count -= 1;
		if(count == 0) count = 1, ans = x;
	    }
	}
    	cout << ans << endl;
    }
    return 0;
}