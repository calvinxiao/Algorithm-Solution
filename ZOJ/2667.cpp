/*
#Problem ID: 2667
#Submit Time: 2012-08-22 01:54:04
#Run Time: 60
#Run Memory: 216
#ZOJ User: calvinxiao
*/

#include <algorithm>
#include <memory.h>
#include <stdio.h>

#define for(what) if (0) ; else for(what)

using namespace std;

struct Turtle {
    int a, b, l, r, len, data, no, prev;
    bool valid;

    bool operator<(const Turtle& t) const {
        return (l<t.l)||((l==t.l)&&(r<t.r));
    }
};

int n;
Turtle tu[1000];
bool mark[1000];

int main() {

    while(scanf("%d",&n) != EOF) {

        memset(mark, 0, sizeof mark);

        for (int i=0; i<n; i++) {
            scanf("%d%d",&(tu[i].a),&(tu[i].b));
            tu[i].l = tu[i].a;
            tu[i].r = n-1-tu[i].b;
            tu[i].len = tu[i].r-tu[i].l+1;
            tu[i].data = 0;
            tu[i].no = i+1;
            tu[i].valid = (tu[i].l<n)&&(tu[i].r>=0)&&(tu[i].l<=tu[i].r);
        }

        sort(tu,tu+n);
        for (int i=0; i<n; i++)
            tu[i].valid = tu[i].valid&&((i<tu[i].len)||(tu[i-tu[i].len]<tu[i]));
        for (int i=0; i<n; i++)
            if (tu[i].valid) {
                tu[i].prev = -1;
                for (int j=0; j<i; j++)
                    if (tu[j].valid&&(!(tu[j]<tu[i])||tu[j].r<tu[i].l)&&(tu[i].data<tu[j].data)) {
                        tu[i].prev = j;
                        tu[i].data = tu[j].data;
                    }
                tu[i].data++;
            }

        int best = -1;
        for (int i=0; i<n; i++)
            if (tu[i].valid&&(best==-1||tu[i].data>tu[best].data))
                best = i;
        if (best==-1)
            printf("%d",n);
        else
            printf("%d",n-tu[best].data);
        while (best!=-1) {
            mark[best] = true;
            best = tu[best].prev;
        }
        for (int i=0; i<n; i++)
            if (!mark[i])
                printf(" %d",tu[i].no);
        printf("\n");
    }
    return 0;
}
