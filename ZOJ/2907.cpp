/*
#Problem ID: 2907
#Submit Time: 2012-10-22 16:17:47
#Run Time: 2250
#Run Memory: 612
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))

using namespace std;

const int MAX = 100;

string s;
int n;

int main()
{
	if(0) {
		string a = "caaccccbb";
		cout << (a.find("abb") == string::npos) << endl;
		cout << a.substr(0, 1) << endl;
		cout << a.substr(1, 2) << endl;
	}
	set<string> ss;
	while(1) {
		ss.clear();
		cin >> n;
		if(!n) break;
		cin >> s;
		for(int len = 1; len <= s.size(); ++len) {
			for(int i = 0; i + len <= s.size(); ++i) {
				ss.insert(s.substr(i, len));
			}
		}
		n -= 1;
		REP(i, n) {
			cin >> s;
			vector<string> toremove;
			for(set<string>::iterator it = ss.begin(); it != ss.end(); ++it) {
				if(s.find(*it) == string::npos) {
					toremove.push_back(*it);
					//ss.erase(*it);
				}
			}
			REP(j, toremove.size())
				ss.erase(toremove[j]);
		}


		if(ss.size() > 0) {
			string ans = *ss.begin();
			for(set<string>::iterator it = ss.begin(); it != ss.end(); ++it) {
				if(ans.size() < (*it).size())
					ans = *it;
				else if( ans.size() == (*it).size() && ans + *it > *it + ans)
					ans = *it;
			}

			cout << ans << endl;
		}
		else
			cout << "IDENTITY LOST\n";
	}

	//cout << n << m << endl;
    return 0;
}
