/*
#Problem ID: 1540
#Submit Time: 2012-08-19 01:26:35
#Run Time: 100
#Run Memory: 324
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<queue>
#define uchar unsigned char
#define N 55
using namespace std;
struct node1 {
    int son[55],fail;
    bool w;
} point[202];
int n,m,p,v[2][202][N+2],g[606];
char s[105];
bool used[202];
queue<int> myqueue;
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,l,a[N+2],num,h,k;
    while(scanf("%d%d%d\n",&n,&m,&p) != EOF) {
        gets(s);
        l=strlen(s);
        memset(g,0,sizeof(g));
        for (i=0; i<l; i++) g[s[i]+128]=i;
        memset(point,0,sizeof(point));
        num=0;
        while (p--) {
            gets(s);
            l=strlen(s);
            h=0;
            for (i=0; i<l; i++) {
                k=g[s[i]+128];
                if (!point[h].son[k]) {
                    num++;
                    point[h].son[k]=num;
                }
                h=point[h].son[k];
                if (point[h].w) break;
            }
            point[h].w=true;
        }
        while (!myqueue.empty()) myqueue.pop();
        memset(v,0,sizeof(v));
        for (i=0; i<n; i++)
            if (point[0].son[i]) {
                myqueue.push(point[0].son[i]);
                if (!point[point[0].son[i]].w)
                    v[0][point[0].son[i]][0]++;
            } else v[0][0][0]++;
        while (!myqueue.empty()) {
            h=myqueue.front();
            myqueue.pop();
            if (point[point[h].fail].w) point[h].w=true;
            if (point[h].w) continue;
            for (i=0; i<n; i++) {
                k=point[h].fail;
                while (k && !point[k].son[i]) k=point[k].fail;
                point[point[h].son[i]].fail=point[k].son[i];
                if (!point[h].son[i])
                    point[h].son[i]=point[k].son[i];
                else
                    myqueue.push(point[h].son[i]);
            }
        }
        k=0;
        m--;
        while (m--) {
            k=1-k;
            memset(v[k],0,sizeof(v[k]));
            memset(used,false,sizeof(used));
            used[0]=true;
            myqueue.push(0);
            while (!myqueue.empty()) {
                h=myqueue.front();
                myqueue.pop();
                if (point[h].w) continue;
                for (i=0; i<n; i++)
                    if (!point[point[h].son[i]].w) {
                        if (!used[point[h].son[i]]) {
                            myqueue.push(point[h].son[i]);
                            used[point[h].son[i]]=true;
                        }
                        for (p=0; p<N; p++) {
                            v[k][point[h].son[i]][p]+=v[1-k][h][p];
                            if (v[k][point[h].son[i]][p]>99999999) {
                                v[k][point[h].son[i]][p+1]+=v[k][point[h].son[i]][p]/100000000;
                                v[k][point[h].son[i]][p]%=100000000;
                            }
                        }
                    }
            }
        }
        memset(a,0,sizeof(a));
        for (i=0; i<=num; i++)
            for (p=0; p<N; p++) {
                a[p]+=v[k][i][p];
                if (a[p]>99999999) {
                    a[p+1]+=a[p]/100000000;
                    a[p]%=100000000;
                }
            }
        for (p=N; p>=0; p--)
            if (a[p]) break;
        if (p==-1) p=0;
        printf("%d",a[p]);
        p--;
        for (; p>=0; p--) {
            if (a[p]<10000000 ) printf("0");
            if (a[p]<1000000  ) printf("0");
            if (a[p]<100000   ) printf("0");
            if (a[p]<10000    ) printf("0");
            if (a[p]<1000     ) printf("0");
            if (a[p]<100      ) printf("0");
            if (a[p]<10       ) printf("0");
            printf("%d",a[p]);
        }
        printf("\n");
    }
    return 0;
}
