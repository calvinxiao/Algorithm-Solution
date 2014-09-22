/*
#Problem ID: 2859
#Submit Time: 2013-03-18 17:51:33
#Run Time: 720
#Run Memory: 2264
#ZOJ User: calvinxiao
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN 300

struct minval{
    int r,c,v;
}minvals[MAXN*MAXN+10];

int cmp(const void *m1,const void *m2){
    struct minval *mm1=(struct minval *)m1,*mm2=(struct minval *)m2;
    return mm1->v-mm2->v;
}

int main(int argc, char *argv[]){
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n,q,i,j,temp,many=0;
        
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&temp);
                minvals[many].r=i;
                minvals[many].c=j;
                minvals[many].v=temp;
                many++;
            }
        }
        
        qsort(minvals,many,sizeof(struct minval),cmp);
        
        int r1,c1,r2,c2;
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            r1--,c1--,r2--,c2--;
            for(i=0;i<many;i++){
                if(minvals[i].r>=r1&&
                   minvals[i].r<=r2&&
                   minvals[i].c>=c1&&
                   minvals[i].c<=c2){
                       printf("%d\n",minvals[i].v);
                       break;
                   }
            }
        }
    }
    return 0;
}