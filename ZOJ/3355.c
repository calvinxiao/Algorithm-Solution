/*
#Problem ID: 3355
#Submit Time: 2013-11-11 21:41:12
#Run Time: 0
#Run Memory: 168
#ZOJ User: calvinxiao
*/

double x, s;
int n;
const double eps = 1e-13;

int main()
{
  scanf("%d", &n);
  while (n--) {
    s = 0.0;
    scanf("%lf", &x); s += 1.0 / x;
    scanf("%lf", &x); s += 1.0 / x;
    scanf("%lf", &x); s += 1.0 / x;
    if (s + eps < 1.0)
      printf("Aha\n");
    else
      printf("No way\n");
  }
	return 0;
}
