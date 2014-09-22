/*
#Problem ID: 1276
#Submit Time: 2012-07-15 23:37:21
#Run Time: 100
#Run Memory: 160
#ZOJ User: calvinxiao
*/

/*
  1996 ACM North Central Regional Programming Contest
  Problem D -- Optimal Array Multiplication Sequence

  Ed Karrels, November 1996
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int rows, cols;
} Dims;

typedef struct Factor {
   struct Factor *left, *right;
   int me;
} Factor;

int case_no = 0;

void Print(int combine[], int n);

void BestMult(Dims dims[], int n, int lvl, long nmult, int best_combine[]) {
   static int *combine;
   static long best_nmult;
   Dims *my_dims;
   int i, j;
   long my_nmult;

   if (lvl == 0) {
      best_nmult = -1;
      combine = (int*)malloc(sizeof(int) * (n-1));
   }

   if (n == 1) {
	 /*
	   printf("%ld ", nmult);
	   Print(combine, lvl+1);
	   */

      if (best_nmult == -1 || nmult < best_nmult) {
	 for (i=0; i<lvl; i++) {
	    best_combine[i] = combine[i];
	 }
	 best_nmult = nmult;
      }
      return;
   }

   my_dims = (Dims*)malloc(sizeof(Dims) * (n-1));

      /*
	for (i=0; i<n; i++) {
	printf(" (%d %d) ", dims[i].rows, dims[i].cols);
	} putchar('\n');
	*/
    
   for (i=0; i<n-1; i++) {
      combine[lvl] = i;
      for (j=0; j<i; j++) {
	 my_dims[j] = dims[j];
      }

      my_dims[i].rows = dims[i].rows;
      my_dims[i].cols = dims[i+1].cols;
      my_nmult = dims[i].rows * dims[i].cols * dims[i+1].cols;
	 /* printf("%d:%d my_nmult = %ld\n", lvl, i, my_nmult); */
      for (j++; j<n-1; j++) {
	 my_dims[j] = dims[j+1];
      }
      BestMult(my_dims, n-1, lvl+1, nmult + my_nmult, best_combine);
   }

   free((char*)my_dims);

   if (lvl == 0) {
      free((char*)combine);
   }
}


void PrintFact(Factor *f) {
   if (f->left) {
      putchar('(');
      PrintFact(f->left);
      printf(" x ");
      PrintFact(f->right);
      putchar(')');
   } else {
      printf("A%d", f->me);
   }
}

void FreeFact(Factor *f) {
   if (f) {
      FreeFact(f->left);
      FreeFact(f->right);
      free((char*)f);
   }
}
	

void Print(int combine[], int n) {
   Factor **factors, *newf;
   int i, j;

   factors = (Factor**)malloc(sizeof(Factor*) * n);
   for (i=0; i<n; i++) {
      factors[i] = (Factor*)malloc(sizeof(Factor));
      factors[i]->left = factors[i]->right = 0;
      factors[i]->me = i+1;
   }

   for (i=0; i<n-1; i++) {
      newf = (Factor*)malloc(sizeof(Factor));
      newf->left = factors[combine[i]];
      newf->right =  factors[combine[i]+1];
      factors[combine[i]] = newf;
      for (j=combine[i]+1; j<n-1; j++)
	 factors[j] = factors[j+1];
   }

   printf("Case %d: ", ++case_no);
   PrintFact(factors[0]);
   putchar('\n');
   FreeFact(factors[0]);
}



int main() {
   int *combine, i, n;
   Dims *dims;

   while (scanf("%d", &n), n) {
      combine = (int*)malloc(sizeof(int) * (n-1));
      dims = (Dims*)malloc(sizeof(Dims) * n);

      for (i=0; i<n; i++) {
	 scanf("%d %d", &dims[i].rows, &dims[i].cols);
      }

      BestMult(dims, n, 0, 0, combine);
      Print(combine, n);
   }
}