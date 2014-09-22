/*
#Problem ID: 2349
#Submit Time: 2013-07-22 20:36:06
#Run Time: 920
#Run Memory: 2104
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<string, string> ms;
map<string, int> mi;

int rec(string s) {
   sort(s.begin(), s.end());
   if (mi.find(s) != mi.end())
       return mi[s];
   string t;
   int &ret = mi[s];
   ret = 1;
   for (int i = 0; i < s.size(); i++) {
       t = s.substr(0, i) + s.substr(i+1, s.size() - i - 1);
       if (ms.find(t) != ms.end()) {
           int temp = rec(t);
           if (ret < temp + 1)
               ret = temp + 1;
       }
   }
   return ret;
}

void P(string s, int ans) {
    if (ans == 1) {
        cout << ms[s] << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        string t = s.substr(0, i) + s.substr(i+1, s.size() - i - 1);
        if (ms.find(t) != ms.end() && mi[t] == ans - 1) {
            P(t, ans - 1);
            break;
        }
    }
    cout << ms[s] << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
	int tc; cin >> tc;
    string s;
    getchar();
    getline(cin, s);
	for (int qq = 0; qq < tc; qq++) {
        if (qq)
            cout << endl;
		vector<string> v;
        while(1) {
            getline(cin, s);
            if (s.size() == 0)
                break;
            v.push_back(s);
        }
        ms.clear();
        mi.clear();
        for (int i = 0; i < v.size(); i++) {
            s = v[i];
            sort(s.begin(), s.end());
            ms[s] = v[i];
        }
        int ans = 0;
        string anss = "";
        for (int i = 0; i < v.size(); i++) {
            s = v[i];
            int temp = rec(s);
            if (ans < temp) {
                ans = temp;
                sort(s.begin(), s.end());
                anss = s;
            }
        }
        P(anss, ans);
        //P("carbons", 6);
	}
	return 0;
}
