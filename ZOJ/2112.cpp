/*
#Problem ID: 2112
#Submit Time: 2012-10-25 12:40:45
#Run Time: 8330
#Run Memory: 572
#ZOJ User: calvinxiao
*/

 #include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <cstdlib>
 
 #define lson l, m, rt << 1
 #define rson m + 1, r, rt << 1 | 1
 #define root 0, mx - 1, 1
 
 using namespace std;
 
 #define debug 0
 
 int min2(int _a, int _b){return _a < _b ? _a : _b;}
 int max2(int _a, int _b){return _a > _b ? _a : _b;}
 
 const int maxn = 50001;
 int tmp[maxn], s[maxn];
 
 int k_elem(int n, int *a, int k){//二分搜索第k大数
     int t, key;
     int i, j, l = 0, r = n - 1;
     while (l < r){
         for (key = a[((i = l - 1) + (j = r + 1)) >> 1]; i < j; ){
             for (j--; key < a[j]; j--);
             for (i++; a[i] < key; i++);
             if (i < j) t = a[i], a[i] = a[j], a[j] = t;
         }
         if (k > j) l = j + 1;
         else r = j;
     }
     return a[k];
 }
 
 int main(){
     int T, n, m;
     int l, r, k;
     char in[3];
 
     scanf("%d", &T);
     while (T--){
         scanf("%d%d", &n, &m);
         for (int i = 1; i <= n; i++){
             scanf("%d", &s[i]);
         }
         while (m-- && scanf("%s", in)){
             if (in[0] == 'Q'){
                 scanf("%d%d%d", &l, &r, &k);
                 for (int i = l; i <= r; i++){
                     tmp[i - l] = s[i];
                 }
                 printf("%d\n", k_elem(r - l + 1, tmp, k - 1));
             }
             else{
                 scanf("%d%d", &l, &k);
                 s[l] = k;
             }
         }
     }
 
     return 0;
 }