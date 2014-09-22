/*
#Problem ID: 2445
#Submit Time: 2012-08-14 01:20:34
#Run Time: 1160
#Run Memory: 6268
#ZOJ User: calvinxiao
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int num;
    int x;
    int y;
} Point;

int n;
char s[250001];
Point *list;
int ans_len,ans_b,ans_e;
char ans_d;

int cmp_x(const void *a, const void *b)
{
    Point *p1,*p2;
    p1 = (Point*)a;
    p2 = (Point*)b;
    if(p1->x != p2->x) return p1->x - p2->x;
    else return p1->y - p2->y;
}

void findShortcut(char d1, char d2)
{
    int len,b,e,s,t;
    char d;

    s=0;
    t=1;
    while(s<=n)
    {
        while(t<=n && list[t].x==list[s].x) t++;
        if(t-s > 1)
        {
            while(s<t-1)
            {

                if(abs(list[s].num-list[s+1].num) > 1)
                {
                    len=abs(list[s].y-list[s+1].y);
                    if(list[s].num < list[s+1].num)
                    {
                        b=list[s].num;
                        e=list[s+1].num;
                        if(list[s].y < list[s+1].y) d=d1;
                        else d=d2;
                    }
                    else
                    {
                        b=list[s+1].num;
                        e=list[s].num;
                        if(list[s].y < list[s+1].y) d=d2;
                        else d=d1;
                    }

                    if(len < ans_len || (len==ans_len&&b<ans_b) || (len==ans_len&&b==ans_b&&e>ans_e))
                    {
                        ans_len=len;
                        ans_b=b;
                        ans_e=e;
                        ans_d=d;
                    }
                }
                s++;
            }
        }
        s=t;
        t++;
    }
}

int main()
{

    int i,x,y,temp;
    while(scanf("%d", &n) != EOF)
    {

        scanf("%s", s);

        list = (Point*)malloc(sizeof(Point)*(n+1));

        list[0].num=0;
        list[0].x=0;
        list[0].y=0;
        x=y=0;

        for(i=0; i<n; i++)
        {
            list[i+1].num = i+1;
            switch(s[i])
            {
            case 'N':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'S':
                y--;
                break;
            case 'W':
                x--;
                break;
            }
            list[i+1].x=x;
            list[i+1].y=y;
        }

        ans_len=250000;

        qsort(list, n+1, sizeof(Point), cmp_x);
        findShortcut('N', 'S');

        for(i=0; i<=n; i++)
        {
            temp=list[i].x;
            list[i].x = list[i].y;
            list[i].y = temp;
        }

        qsort(list, n+1, sizeof(Point), cmp_x);
        findShortcut('E', 'W');

        printf("%d %d %d %c\n", ans_len, ans_b, ans_e, ans_d);
        free(list);
    }
    return 0;
}
