#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

#define SIZE 100
#define SIZE2 134217728

char *A[SIZE];
int Q[SIZE2][20000];
int front[SIZE2] = {0};
int rear[SIZE2] = {0};
int len[SIZE2] = {0};

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

/*整列してたら負の値。逆順やったら正の値*/
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

int partition(char *a[], int pivot, int left, int right){
  char *temp;
  int l;
  int r;
  temp = a[right];
  a[right] = a[pivot];
  a[pivot] = temp;
  l = left;
  r = right - 1;
  while(1){
    while(cmp_word(a[l], a[right]) < 0)
      l++;
    while(l <= r && cmp_word(a[r], a[right]) >= 0)
      r--;
    if(l < r){
      temp = a[l];
      a[l] = a[r];
      a[r] = temp;
    }
    else break;
  }
  temp = a[l];
  a[l] = a[right];
  a[right] = temp;
  return l;
}

void quick_sort(char *a[], int left, int right){
  int p;
  int pivot;
  if(left < right){
    pivot = right;
    p = partition(a, pivot, left, right);
    quick_sort(a, left, p-1);
    quick_sort(a, p+1, right);
  }
}

int conv_int(char *w){
  int i,length;
  int sum =0;
  length = strlen(w);
  for(i = 1; i <= length; i++){
    sum += (w[length-i] - 'a' + 1) * pow(8, i-1);
  }
  len[sum] = length;
  return sum;
}
void inconv_int(int d, int k){
  char w[9];
  while(1){
    w[len[d]-1] = (d % 8) + 'a';
    len[d]--;
    d = d /8;
    
    if(d == 0){
      break;
    }
  }
  strcpy(A[k], w);
}

void enqueue(int d){
  Q[d][rear[d]] = d;
  rear[d]++;
}

int dequeue(int d){
  front[d]++;
  return Q[d][front[d]];
}

void bucket_sort(char *a[]){
  int i,j;
  for(i = 0; i < SIZE; i = i+1)
    enqueue(conv_int(a[i]));
  for(i = 0, j = 0; j < SIZE2; j++){
    while (front[j] != rear[j]){
      inconv_int(dequeue(j), i);
      i++;
    }
  }
}
void shell_sort(char *a[]){
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
	A[j+G[k]] = A[j];
	j = j - G[k];
      }
      A[j+G[k]] = in;
    }
  }
}

int main(void){
  int i;
  int lmin = 4;
  int lmax = 8;
  
  srand((unsigned)time(NULL));
  for(i = 0; i < SIZE; i++){
    A[i] = random_word(lmin, lmax);
  }

  //  quick_sort(A, 0, SIZE-1);
  bucket_sort(A);

 for(i = 0; i < SIZE; i++){
   printf("%s\n",A[i]);
  }



  return 0;
}
