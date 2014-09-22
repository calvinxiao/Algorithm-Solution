/*
#Problem ID: 3167
#Submit Time: 2013-04-24 09:55:54
#Run Time: 50
#Run Memory: 184
#ZOJ User: calvinxiao
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int num[1000];
int main()
{
	int k,m,n,len,i;
	while( scanf("%d%d",&k,&m) != EOF )
	{
		memset(num,0,sizeof(num));
		num[0] = 1; len = 1;
		for(n=1; n<=100; n++)
		{
			for(i=0; i<len; i++)
				num[i] *= m;
			for(i=0; i<len; i++)
				if( num[i] >= 10 )
				{
					num[i+1] += num[i]/10;
					num[i] %= 10;
				}
			while( num[i] >= 10 )
			{
				num[i+1] += num[i]/10;
				num[i] %= 10;
				i++;
			}
			while( num[i] != 0 )
				i++;
			len = i;
			if( num[k-1] == 7 )
			{
				printf("%d\n",n);
				break;
			}
		}	
	}
return 0;
}
