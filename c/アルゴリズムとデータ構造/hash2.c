#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define B 15000
#define N 12000
#define empty 0
#define occupied 1
#define deleted 2
#define HASH_1 0
#define HASH_2 1

typedef struct _point {
  int x;
  int y;
} POINT;

typedef struct h_array {
  POINT data;
  int status;
} HARRAY;

typedef struct hsearch {
  int con;    //0:未登録 1:登録済み
  int n;
  int v;
} RESULT;

HARRAY H[B];

void init_hash() {
  int i;
  for (i = 0; i < B; i++)
    H[i].status = empty;
}
#if HASH_1
int h(POINT p, int count){
  int b;
  int init_b;
  init_b = abs(p.x);
  b = init_b;
  if(count != 0)
    b = (init_b + count) % B;
  return b;

}
#endif
#if HASH_2
int h(POINT p, int count){
  int b;
  int init_b;
  init_b = (abs(p.x)*B/100);
  if(init_b == B)
    init_b--;
  b = init_b;
  if(count != 0)
    b = (init_b + count) % B;
  return b;

}
#endif

int search_hash2(POINT p){
  int count = 0;
  int b;
  int init_b;
  b = h(p, count);//ハッシュ
  init_b = b;
  do{
    if(H[b].status == occupied){
      if(H[b].data.x == p.x && H[b].data.y == p.y)
	return b;//同じやつあった
    }
    else if (H[b].status == empty)//空のやつあった
      return -1;
    /*なんか入ってた*/
    count = count+1;
    b = h(p, count);//リハッシュ
  }while (b != init_b);//一周したら終わり
  return -1;
}

int insert_hash(POINT p){
  int b;
  int init_b;
  int count; //衝突回数
  if(search_hash2(p) != -1)//同じやつあった
    return -1;
  /*同じやつなかった*/
  count = 0;
  b = h(p,count);
  init_b = b;
  do{
    if(H[b].status == empty || H[b].status == deleted){ //中身ない
      H[b].data = p;
      H[b].status = occupied;
      return count;
    }
    /*なんか入ってた*/
    count = count + 1;
    b = h(p, count);
  }while(b !=init_b);//オーバーフロウ
  return -2;
}

int search_hash(POINT p){
  int count = 0;
  int b;
  int init_b;
  b = h(p, count);
  init_b = b;
  do{
    if(H[b].status == occupied){
      if(H[b].data.x == p.x && H[b].data.y == p.y)
	return count+1;
    }
    else if (H[b].status == empty)
      return -(count+1);
    count = count+1;
    b = h(p, count);
  }while (b != init_b);
  return -count;
}

int search_h(int n){
  POINT p;
  int a = 0;
  int x;
  int y;
  x = rand()%200 - 100;
  y = rand()%200 - 100;
  if(x*x + y*y >=50*50 && x*x + y*y <= 100*100){
    p.x = x;
    p.y = y;
    a = search_hash(p);
  }
  return a;
  
}

int main(void){
  unsigned int now = (unsigned int)time(0);
  srand(now);
  int x;
  int y;
  POINT p;
  int c[N];
  int v[N];
  int n = 0;
  double a = 0;
  int k;
  double al;
  int sum = 0;
  int sum2 = 0;
  int sum3 = 0;
  init_hash();
  while(1){
    x = rand()%200 - 100;
    y = rand()%200 - 100;
    if(x*x + y*y >=50*50 && x*x + y*y <= 100*100){
      p.x = x;
      p.y = y;
      k = insert_hash(p);
      if(k >= 0){
	c[n] = k;
	v[n] = search_h(n);	
	n++;
      }
    }
    if(n == N){
      break;
    }
  }
  
  /*計測*/
  for(n = 0; n <N; n++){
    if(H[n].status == occupied)
     a = a+1;
  }

  
  for(n = 0; n < N; n++){
     printf("(n, c) = (%d, %d)\n",n+1,c[n]);
    sum = sum + c[n];
  }
  printf("\n登録済み\n");
  for(n = 0; n < N; n++)
    if(v[n] > 0){
           printf("(n, v) = (%d, %d)\n",n,v[n]);
      sum2 =v[n];
    }
  
  printf("\n未登録\n");
  for(n = 0; n < N; n++)
    if(v[n] < 0){
      printf("(n, v) = (%d, %d)\n",n,-v[n]);
      sum3 =v[n]*(-1);  
    }

  al = a/B;
  printf("占有率 α = %f\n",al);
  printf("衝突回数 %d\n",c[N-1]);
  printf("訪問回数\n");
  printf("登録済み     %d\n",sum2);
  printf("未登録       %d\n",sum3);

  return 0;
}
