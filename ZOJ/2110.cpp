/*
#Problem ID: 2110
#Submit Time: 2012-08-07 22:51:40
#Run Time: 560
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<memory.h>
using namespace std;
int N, M, T;
char m[7][7];
bool v[7][7];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int tx, ty;
int abs(int a) {
    return -a;
}

bool dfs(int x, int y, int step) {
    int left = T - step - abs(tx - x) - abs(ty - y);
    if(left < 0 || left % 2 == 1) return false;
    if(step == T && m[x][y] == 'D') return true;
    if(step >= T) return false;
    if(m[x][y] == 'D') return false;
    for(int i = 0; i < 4; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || xx >= N || yy < 0 || yy >= M || v[xx][yy] || m[xx][yy] == 'X') continue;
        //if((int)fabs(xx - tx) + (int)fabs(yy - ty) < T - step) return false;
        v[xx][yy] = 1;
        if(dfs(xx, yy, step + 1)) return true;
        v[xx][yy] = 0;
    }
    return false;
}
int main()
{
    int x, y;
    while((cin >> N >> M >> T) && N) {
        memset(v, 0, sizeof v);
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                cin >> m[i][j];
                if(m[i][j] == 'S') x = i, y = j;
                if(m[i][j] == 'D') tx = i, ty = j;
            }
        }
        v[x][y] = 1;
        if(dfs(x, y, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
