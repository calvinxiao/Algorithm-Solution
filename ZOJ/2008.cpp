/*
#Problem ID: 2008
#Submit Time: 2013-09-28 21:26:21
#Run Time: 180
#Run Memory: 36756
#ZOJ User: calvinxiao
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define INF 1010000000
using namespace std;
const int maxn = 1001000;

inline int read_int(){
    int a=0;
    int b=1,c=getchar();
    if(c=='-')b=-1;
    else a=c-48;
    while((c=getchar())!=' '&&c!='\n')
        a=a*10+c-48;
    a*=b;
    return a;
}

struct node{
    int id,w;
    node(){}
    node(int _id,int _w){
        id = _id;   w = _w;
    }
    bool operator<(const node &p)const{
         return w > p.w; // basic coding
    }
};
vector<node>V[maxn];
int n,m;
int x[maxn],y[maxn],z[maxn],dis[maxn];
bool vis[maxn];

int spfa(){
    int i;
    int T;
    queue<int>Q;

    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    vis[1] = 1;
    Q.push(1);

    while(!Q.empty()){
         T = Q.front();   Q.pop();
         vis[T] = 0;
         int Size = (int)V[T].size();
         for(i=0; i<Size; i++){
            int id = V[T][i].id;
            int w = V[T][i].w;
            if(dis[T]+w < dis[id]){
                dis[id] = dis[T] + w;
                if(!vis[id]){
                   Q.push(id);  vis[id] = 1;
                }
            }
         }
    }
    int ret = 0;
    for(i=1; i<=n; i++) ret += dis[i];
    return ret;
}

int main()
{
    int cas;
    scanf(" %d ",&cas);
    while(cas--){
        int i;
        scanf(" %d %d ",&n,&m);
        for(i=0; i<m; i++) {
            x[i] = read_int();
            y[i] = read_int();
            z[i] = read_int();
        }
        for(i=1; i<=n; i++) V[i].clear();
        for(i=0; i<m; i++) V[x[i]].push_back(node(y[i],z[i]));
        int ans1 = spfa();

        for(i=1; i<=n; i++) V[i].clear();
        for(i=0; i<m; i++) V[y[i]].push_back(node(x[i],z[i]));
        int ans2 = spfa();

        printf("%d\n",ans1+ans2);
    }
    return 0;
}
