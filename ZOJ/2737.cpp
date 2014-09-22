/*
#Problem ID: 2737
#Submit Time: 2012-09-18 17:31:08
#Run Time: 10
#Run Memory: 284
#ZOJ User: calvinxiao
*/

/**
Calvin's Code
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ;

bool v[100005], hasans;
int n, m, ans;

int WordOccurrenceCount( std::string const & str, std::string const & word )
{
       int count(0);
       std::string::size_type word_pos( 0 );
       while ( word_pos!=std::string::npos )
       {
               word_pos = str.find(word, word_pos );
               if ( word_pos != std::string::npos )
               {
                       ++count;

         // start next search after this word
                       word_pos ++;
               }
       }

       return count;
}

int main() {
    string s, t;

    while(cin >> s >> t) {
        set<string> se;
        ans = 0;
        n = s.size();
        m = t.size();
        t += t;
        for(int i = 0; i < m; ++i) {
            string next = t.substr(i, m);
            if(se.count(next) == 0) {
                ans += WordOccurrenceCount(s, next);
                se.insert(next);
            }

        }
        cout << ans << endl;
    }
    return 0;
}
