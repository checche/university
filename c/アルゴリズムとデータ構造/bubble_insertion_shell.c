#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE 10000

char *A[SIZE];
int *cnt_co;
int *cnt_ch;


char *random_word(int lmin, int lmax){
  int len;
  len = rand() % (lmax + 1 - lmin) + lmin;
  int i;
  char *p;
  p = (char *)malloc(sizeof(char) * (len +1));
  for (i = 0; i < len; i++)
    p[i] =rand()%8 + 'a';
  p[i] = '\0';
  return p;
}

int cmp_word(char *w1, char *w2){
  int sa;
  sa = strlen(w1) - strlen(w2);
  if(sa < 0)
    return sa;
  else if(sa > 0)
    return sa;
  else if(sa == 0)
   return strcmp(w1, w2);
  return 0;
}

void b_sort(char *a[], int *x, int *y){
  int i,j;
  char *temp;
  for(i = 0; i < SIZE-1; i = i+1)
    for(j = SIZE-1; j > i; j = j-1){
      *x = *x + 1;
      if(cmp_word(a[j-1],a[j]) > 0){
	*y = *y + 1;
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
      }
    }
}

void insertion_sort(char *a[], int *x, int *y){
  char *in;
  int i,j;
  for(i = 1; i < SIZE; i++){
    in = a[i];
    j = i-1;
    while(j >= 0 && cmp_word(in, a[j]) < 0){
      *x = *x + 1;
      a[j+1] = a[j];
      j = j-1;
      *y = *y + 1;
    }
    *x = *x + 1;
    a[j+1] = in;
    *y = *y + 1;
  }
}

void shell_sort(char *a[],int *x, int *y){
  int G[4];
  int k;
  char *in;
  int i,j;
  G[2] = 4;
  G[1] = 2;
  G[0] = 1;
  for (k = 2; k >= 0; k = k-1){
    for(i = G[k]; i < SIZE; i = i+1){
      in = a[i];
      j = i - G[k];
      while(j >= 0 && cmp_word(in, a[j]) < 0){
	*x = *x + 1;
	A[j+G[k]] = A[j];
	j = j - G[k];
	*y = *y + 1;
      }
      *x = *x + 1;
      A[j+G[k]] = in;
      *y = *y + 1;
    }
  }
}

int main(void){
  int i;
  int lmin=4;
  int lmax=8;
  clock_t start1, start2, start3, end1, end2, end3;
  int a = 0;
  int b = 0;
  srand((unsigned)time(NULL));
  printf("要素数%dの時\n\n",SIZE);
  for(i = 0; i < SIZE; i++){
    A[i] =  random_word(lmin,lmax);
  }
  start1 = clock();  
  b_sort(A, &a, &b);
  end1 = clock();
  printf("バブルソート\n");
  printf("%f sec\n",(double)(end1-start1)/CLOCKS_PER_SEC);
  printf("比較回数%d\n", a);
  printf("交換回数%d\n\n", b);

  a = 0;
  b = 0;  

  for(i = 0; i < SIZE; i++){
    A[i] =  random_word(lmin,lmax);
  }  
  
  start2 = clock();  
  insertion_sort(A, &a, &b);
  end2 = clock();

  printf("挿入ソート\n");  
  printf("%f sec\n",(double)(end2-start2)/CLOCKS_PER_SEC);
  printf("比較回数%d\n", a);
  printf("交換回数%d\n\n", b);

  a = 0;
  b = 0;

  for(i = 0; i < SIZE; i++){
    A[i] =  random_word(lmin,lmax);
    printf("%s\n", A[i]);
  }  
  
  start3 = clock();  
  shell_sort(A, &a, &b);
  end3 = clock();
  
  printf("シェルソート\n");
  printf("%f sec\n",(double)(end3-start3)/CLOCKS_PER_SEC);
  printf("比較回数%d\n", a);
  printf("交換回数%d\n", b);




  return 0;
}
