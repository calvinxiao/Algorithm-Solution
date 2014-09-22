/*
#Problem ID: 1204
#Submit Time: 2013-11-11 23:21:26
#Run Time: 40
#Run Memory: 172
#ZOJ User: calvinxiao
*/


int tc, n, a[33], used[33], ans;

void dfs(int idx, int sum, int cnt, int left) {
  if (sum > a[n-1])
    return;
  if (cnt == left) {
    int i;
    for (i = idx; i < n; i++) if (a[i] == sum) {
      int first = 1, j;
      for (j = 0; j < idx; j++) {
        if (used[j]) {
          if (first)
            printf("%d", a[j]), first = 0;
          else
            printf("+%d", a[j]);
        }
      }
      printf("=%d\n", sum);
      ans++;
      break;
    }
    return;
  }


  if (cnt + n - idx - 1 < left)
    return;

  if (idx  == n - 1 )
    return;
  if (sum + a[idx] > a[n-1])
    return;
  used[idx] = 1;
  dfs(idx + 1, sum + a[idx], cnt+1, left);
  used[idx] = 0;
  dfs(idx + 1, sum, cnt, left);
  /*
  int i;
  for (i = idx; i < n - 1; i++) {
    if (sum + a[i] > a[n-1])
      break;
    if (0) {
      printf(" 1 %d %d %d %d\n", i + 1, sum + a[i], cnt + 1, left);
    }
    used[i] = 1; dfs(i+1, sum + a[i], cnt + 1, left);
    if (0) {
      printf(" 2 %d %d %d %d\n", i + 1, sum, cnt, left);
    }
    used[i] = 0; dfs(i+1, sum, cnt, left);
  }
  */
}

int main()
{
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++) scanf("%d", a + i), used[i] = 0;
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        if (a[i] > a[j]) {
          a[i] = a[i] + a[j];
          a[j] = a[i] - a[j];
          a[i] = a[i] - a[j];
        }
      }
    }

    int left;
    ans = 0;
    for (left = 2; left < n; left++) {
      used[0] = 1;
      dfs(1, a[0], 1, left);
      used[0] = 0;
      dfs(1, 0, 0, left);
    }
    if (ans > 0)
      printf("\n");
    else
      printf("Can't find any equations.\n\n");
  }
	return 0;
}
