/*
#Problem ID: 3785
#Submit Time: 2014-05-14 16:50:15
#Run Time: 0
#Run Memory: 172
#ZOJ User: calvinxiao
*/

#include <stdio.h>

int gao[] = {0,1,5,4,1,4,5,5,6,0,4,6,0,6,6,0,2,0,1,6,0,0,1,5,6,3,0,6,6,0,1,4,6,5,6,6,0,2,4,5,0,6,6,0,4,3,0,3,4,4,5,6,3,5,6,5,5,6,1,6,0,5,6,6,0,4,5,2,6,5,5,6,0,3,5,4,5,5,6,1,3,4,6,5,5,6,3,2,6,2,3,3,4,5,2,4,5,4,4,5,0,5,6,4,5,5,6,3,4,1,5,4,4,5,6,2,4,3,4,4,5,0,2,3,5,4,4,5,2,1,5,1,2,2,3,4,1,3,4,3,3,4,6,4,5,3,4,4,5,2,3,0,4,3,3,4,5,1,3,2,3,3,4,6,1,2,4,3,3,4,1,0,4,0,1,1,2,3,0,2,3,2,2,3,5,3,4,2,3,3,4,1,2,6,3,2,2,3,4,0,2,1,2,2,3,5,0,1,3,2,2,3,0,6,3,6,0,0,1,2,6,1,2,1,1,2,4,2,3,1,2,2,3,0,1,5,2,1,1,2,3,6,1,0,1,1,2,4,6,0,2,1,1,2,6,5,2,5,6,6,0,1,5,0,1,0,0,1,3,1,2,0,1,1,2,6,0,4,1,0,0,1,2,5,0,6,0,0,1,3,5,6,1,0,0};
char *s[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return x;
}

int main()
{
  int tc; tc = get();
  while (tc--) {
    int n = get();
    printf("%s\n", s[gao[n%294]]);
  }
  return 0;
}
