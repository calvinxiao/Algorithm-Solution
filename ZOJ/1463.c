/*
#Problem ID: 1463
#Submit Time: 2012-08-18 14:13:25
#Run Time: 0
#Run Memory: 336
#ZOJ User: calvinxiao
*/

#include<stdio.h>
#include<string.h>
int a[150][150],f[150][150],b[150];
void dfs(int x,int y)
{
    if(a[x][y]==-1)
    {
    b[x]=1;b[y]=1;
    dfs(x+1,y-1);
    }
    else if(a[x][y]>=0)
    {
    dfs(x,a[x][y]);
    dfs(a[x][y]+1,y);
    }
    else
        return;
}
int main()
{
    int n,i,j,k,t,max,kk,l;
    char str[150];
    scanf("%d",&n);
    getchar();
    for(t=0;t<n;t++)
    {
        getchar();
        gets(str);
        memset(f,0,sizeof(f));
        for(i=0;i<150;i++)
            for(j=0;j<150;j++)
                a[i][j]=-2;
            memset(b,0,sizeof(b));
            i=0;j=0;k=0;
            while(k<strlen(str))
            {
                if(i==j)
                    f[i][j]=0;
                else if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']'))
                {
                    max=f[i][j];
                    for(kk=i;kk<j;kk++)
                    {
                        if(f[i][kk]+f[kk+1][j]>max)
                        {
                            max=f[i][kk]+f[kk+1][j];
                            a[i][j]=kk;
                        }
                    }
                    if(max<(f[i+1][j-1]+1))
                    {
                        a[i][j]=-1;
                        f[i][j]=f[i+1][j-1]+1;
                    }
                    else
                        f[i][j]=max;
                }
                else
                {
                    for(kk=i;kk<j;kk++)
                    {
                        if(f[i][kk]+f[kk+1][j]>f[i][j])
                        {
                            f[i][j]=f[i][kk]+f[kk+1][j];
                            a[i][j]=kk;
                        }
                    }
                }
                i++;
                j++;
                if(j==strlen(str))
                {
                    k++;
                    i=0;
                    j=k;
                }
            }
            dfs(0,strlen(str)-1);
            for(i=0;i<strlen(str);i++)
            {
                if(b[i])
                    printf("%c",str[i]);
                else
                {
                    if(str[i]=='('||str[i]==')')
                        printf("()");
                    else
                        printf("[]");
                }
            }
            printf("\n");
            if(t<n-1)
                printf("\n");
    }
    return 0;
}
