/*
#Problem ID: 2273
#Submit Time: 2012-12-06 12:01:32
#Run Time: 30
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==1||n==2)printf("1\n");
        else if(n>2&&n<10)printf("3\n");
        else if((n>9&&n<26)||(n>89&&n<264)||(n>3007&&n<37174))printf("0\n");
        else if((n>25&&n<90)||(n>263&&n<947))printf("6\n");
        else if(n>946&&n<3008)printf("9\n");
        else printf("7\n");
     }
    return 0;
}