/*
#Problem ID: 2540
#Submit Time: 2012-08-22 02:34:32
#Run Time: 0
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
  int x, y;
  bool operator <(const node &b) const{
    if(x < b.x) return 1;
    else if(x == b.x) return y < b.y;
    else
        return false;
  }
};
node a[4];
int main()
{
    int tc, T;
    cin >> T;
    for(tc = 1; tc <= T; ++tc) {
        for(int i = 0; i < 4; ++i) {
            cin >> a[i].x >> a[i].y;
        }
        sort(a, a + 4);
        bool ans = false;
        int b, c, d, e;
        b = (a[1].y - a[0].y) * (a[3].y - a[1].y) + ((a[1].x - a[0].x) * (a[3].x - a[1].x));
        c = (a[3].y - a[1].y) * (a[2].y - a[3].y) + ((a[3].x - a[1].x) * (a[2].x - a[3].x));
        d = (a[2].y - a[3].y) * (a[0].y - a[2].y) + ((a[2].x - a[3].x) * (a[0].x - a[2].x));
        e = (a[0].y - a[2].y) * (a[1].y - a[0].y) + ((a[0].x - a[2].x) * (a[1].x - a[0].x));

        ans = ( !b && !c && !d && !e);

        if(tc != 1) cout << endl;
        cout << "Case " << tc << ":\n";
        if(ans) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}
