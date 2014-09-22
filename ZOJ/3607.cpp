/*
#Problem ID: 3607
#Submit Time: 2012-10-25 17:34:25
#Run Time: 10
#Run Memory: 188
#ZOJ User: calvinxiao
*/

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int pi[1001],ti[1001];
	double temp,Maxtime,Max,Time;
	int t,n,i,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&pi[i]);
		}
		ti[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&ti[i]); 
		}
		sum=0;
		Max=0;
		Maxtime=0;
		for(i=1;i<=n;i++)
		{
			sum+=pi[i];
			temp=(double)sum/(i);//当前的平均价格
			if(Maxtime<(ti[i]-ti[i-1]))
			{
				Maxtime=ti[i]-ti[i-1];
			}
			if(i==n)
			{
				if(temp>Max)
				{
					Max=temp;
					Time=Maxtime;
				}
				continue;
			}
			if(Maxtime<(ti[i+1]-ti[i])&&temp>Max)
			{
				Max=temp;
				Time=Maxtime;
			}
		}
		printf("%.6lf %.6lf\n",Time,Max);
	}
	return 0;
}