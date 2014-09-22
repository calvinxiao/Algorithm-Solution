/*
#Problem ID: 3018
#Submit Time: 2013-05-26 22:33:42
#Run Time: 770
#Run Memory: 4404
#ZOJ User: calvinxiao
*/

#include<iostream>

#include<stdio.h>

#include<memory.h>

using namespace std;

#define MAXN 120000

#define N 20000



//2D segment tree ¾ØÐÎÊ÷

//Ë¼·Ö·½Ê½:

//2 1//

//0 3//



struct node

{
    int x1,x2,y1,y2;
    int sum;
    int ch[4];
};

node tree[MAXN];

int tol;

inline int makenode(int x1,int x2,int y1,int y2)
{
    int k = ++tol;
    tree[k].x1 = x1;
    tree[k].x2 = x2;
    tree[k].y1 = y1;
    tree[k].y2 = y2;
    tree[k].sum = 0;
    memset(tree[k].ch,0,sizeof(tree[k].ch));
    return k;
}

//ÒòÎªÊÇÖ»²åÈëÒ¶½áµã,Ôò±éÀúµÄÉî¶ÈÎªO(log2N)...ËùÒÔÊ±¼ä¸´ÔÓ¶ÈÎªO(log2N)

void insert(int x,int y,int val,int k)  //²åÈë/¸üÐÂ/Ò¶×Ó½áµã(x,x,y,y),Ö»²åÈëÒ¶×Ó½áµã,¶¯Ì¬½¨Ê÷,»ØËÜÊ±¸üÐÂ¸¸½áµãµÄsumÖµ,±ß²åÈë±ß½¨¾ØÐÎÊ÷½áµã....
{
    if(tree[k].x1 == tree[k].x2 && tree[k].y1 == tree[k].y2) //Ò¶×Ó½áµã(x,x,y,y)
    {
        tree[k].sum += val;
        return ;
    }
    int midx = (tree[k].x1+tree[k].x2)>>1;
    int midy = (tree[k].y1+tree[k].y2)>>1;
    if(x <= midx) //0  2
    {
        if(y <= midy) //0   ×óÏÂ
        {
            if(tree[k].ch[0] == 0)
                tree[k].ch[0] = makenode(tree[k].x1,midx,tree[k].y1,midy);
            insert(x,y,val,tree[k].ch[0]);
        }
        else //2     ×óÉÏ
        {
            if(tree[k].ch[2] == 0)
                tree[k].ch[2] = makenode(tree[k].x1,midx,midy+1,tree[k].y2);
            insert(x,y,val,tree[k].ch[2]);
        }
    }
    else  //1 3
    {
        if(y <= midy) //3   ÓÒÏÂ
        {
            if(tree[k].ch[3] == 0)
                tree[k].ch[3] = makenode(midx+1,tree[k].x2,tree[k].y1,midy);
            insert(x,y,val,tree[k].ch[3]);
        }
        else //1              ×óÏÂ
        {
            if(tree[k].ch[1] == 0)
                tree[k].ch[1] = makenode(midx+1,tree[k].x2,midy+1,tree[k].y2);
            insert(x,y,val,tree[k].ch[1]);
        }
    }

    tree[k].sum = 0;
    for(int i=0; i<4; i++)
        if(tree[k].ch[i])
            tree[k].sum += tree[tree[k].ch[i]].sum;    //»ØËÜÊ±¸üÐÂ¸¸½áµãµÄsumÖµ
}

inline bool cross(int x1,int x2,int y1,int y2,int k)   //ÅÐ¶Ï¾ØÐÎÓë¾ØÐÎkÊÇ·ñÏà½»
{
    if(x2 < tree[k].x1 || tree[k].x2 < x1    ||   y2 < tree[k].y1 || tree[k].y2 < y1)
        return false;
    return true;

}

//Õâ¸öQueryµÄ¸´ÔÓ¶È,ÓÐµãÄÑ·ÖÎö,×î»µµÄÇé¿öÏÂ,Òª·ÃÎÊµ½¶à¸ö×Ó¾ØÐÎ»òÒ¶½áµã,Ã¿²ã×î»µµÄÇé¿öÊÇ4¸ö×Ó¾ØÐÎµÄÖµ¶¼ÒªËã,¶ø×Ó¾ØÐÎÓÖÒªµ÷ÓÃ¶à¸ö×Ó¾ØÐÎµÄ..

int Query(int x1,int x2,int y1,int y2,int k)
{
    if(k==0)     //¾ØÐÎk²»´æÔÚ..¼´¸Ã¾ØÐÎÄÚÃ»ÓÐÊýÖµ...Ôò·µ»Ø0

        return 0;

    if(cross(x1,x2,y1,y2,k) == 0) //Èç¹ûºÍµ±Ç°¾ØÐÎ²»Ïà½»,Ôò·µ»Ø0

        return 0;

    if(x1 <= tree[k].x1 && tree[k].x2 <= x2    &&    y1 <= tree[k].y1 && tree[k].y2 <= y2)   //Èç¹ûÄÜÍêÈ«¸²¸Ç,ÔòÖ±½Ó·µ»ØÖµ

        return tree[k].sum;

    //²¿·Ö¸²¸Ç == ¸÷²¿·ÖµÄÖµµÄºÍ

    return Query(x1,x2,y1,y2,tree[k].ch[0]) + Query(x1,x2,y1,y2,tree[k].ch[1]) + Query(x1,x2,y1,y2,tree[k].ch[2]) + Query(x1,x2,y1,y2,tree[k].ch[3]);
}


inline int conver(char *s)
{
    int x = 0;
    int k = 1;
    while(*s)
    {
        x = x*10 + (*s - 48);
        s++;
    }
    return x;
}

int main()
{
    //freopen("0.in", "r", stdin);
    char s[10];
    char ch;
    makenode(1,N,1,N);
    int x,y,val;
    int x1,x2,y1,y2;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0] == 'I')
        {
            ch = 'I';
            continue;
        }
        if(s[0] == 'Q')
        {
            ch = 'Q';
            continue;
        }

        if(s[0] == 'E')
        {
            tol = 0;  //×¢Òâ³õÊ¼»¯,Íü¼ÇÁË³õÊ¼»¯..WAÁËÒ»´Î...ÏÂ´ÎÒª¼Ç×¡ÁË,ÆäÊµÎÒÌØÒâ²âÊÔÁË¶à×éÊý¾Ý,²»¹ýÊÇÏàÍ¬µÄ,ËùÒÔÃ»·¢ÏÖÕâµã..ÔÎ..
            makenode(1,N,1,N);
            continue;
        }

        if(ch == 'I')
        {
            x = conver(s);

            scanf("%d%d",&y,&val);

            insert(x,y,val,1);
        }
        else//Q
        {
            x1 = conver(s);
            scanf("%d%d%d",&x2,&y1,&y2);
            printf("%d\n",Query(x1,x2,y1,y2,1));
        }

    }
    return 0;
}
