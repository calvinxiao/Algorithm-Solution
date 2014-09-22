/*
#Problem ID: 2281
#Submit Time: 2012-08-21 03:27:12
#Run Time: 1340
#Run Memory: 12440
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
int N, M, X, Y;
const int MAX = 1000000 + 1;

bool inQ[MAX];
long long W[MAX];

struct node{
    int y; long long v;
};
int main()
{
    while(cin >> N >> M) {
        vector<struct node> a[N + 1];

        for(int i = 0; i < M; ++i) {
            int x, y, v;
            struct node tnode;
            cin >> x >> y >> v;
            tnode.y = y;
            tnode.v = v;
            a[x].push_back(tnode);
            tnode.y = x;
            a[y].push_back(tnode);
        }
        cin >> X >> Y;
        memset(W, 0, sizeof W);
        memset(inQ, 0, sizeof inQ);
        W[X] = 100000000000000000LL;
        queue<int> Q;
        Q.push(X);
        inQ[X] = 1;
        while(!Q.empty()) {
            int top = Q.front(); Q.pop(); inQ[top] = 0;
            for(int i = 0; i < a[top].size(); ++i) {
                int y = a[top][i].y;
                long long v = a[top][i].v;
                long long minV = min(W[top], v);
                if(minV > W[y]) {
                    W[y] = minV;
                    if(!inQ[y]) Q.push(y), inQ[y] = 1;
                }
            }
        }
        cout << W[Y] << endl;
    }
    return 0;
}
