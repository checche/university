#include<stdio.h>
#define B 10000 //パケット数=ハッシュ表のサイズ
#define N 1000000  //生成する座標の数
#define M 1000000//サーチ回数
#include<math.h>
#include<stdlib.h>
#include<time.h>


/* 二次元平面上の1点を表現する。*/
typedef struct _point {
  int x;
  int y;
} POINT;

/*連結リストのセルのデータ構造*/
typedef struct h_cell{
  POINT data;
  struct h_cell *next;
} CELL;

/*ハッシュ表=セルへのポインタを格納する配列*/
CELL *H[B];

/*ハッシュ表を初期化する関数*/
void init_hash(){
  int i;
  for(i = 0; i < B; i++)
    H[i] = NULL;

}

/*指定したハッシュの先頭に座標を追加*/
void insert_cell_top(POINT d,int b){
  CELL *p;
  p = (CELL*)malloc(sizeof(CELL));
  p->data = d;
  p->next = H[b];
  H[b] = p;
}
/*ハッシュを探索して入力した座標があればその座標を返す*/
CELL *search_cell(CELL *p,POINT d){
  POINT pd;
  while(p != NULL){
    pd = p->data;
    if(pd.x == d.x && pd.y == d.y)
      return p;
    p = p->next;
  }
  return NULL;
}

/*ハッシュ関数*/
#if 1
int h(POINT p){
  int b;
  b = abs(p.x);
  if(b ==10000)
    b=b-1;
  return b;
}
#endif

#if 0
int h(POINT p){
  double a;
  int b;
  a = p.x*p.x + p.y*p.y; 
  a = sqrt(a);
  a = a*B/5000;
  b = a-B;
  return b;

}
#endif

/*座標をハッシュ表に登録*/
int insert_hash(POINT p){
  int b = h(p);
  if(search_cell(H[b], p) == NULL){
    insert_cell_top(p, b);
    return (1);
  }
  else return (0);
  
}

/*座標がハッシュ表に含まれていれば1を返す関数*/
int search_hash(POINT p){
  int b;
  int x = 0;
for(b = 0; b < B; b++)
  if (search_cell(H[b], p) != NULL)
    x = 1;
  return x;
}

/*ハッシュの最大値等を表示する関数*/
void hash_status(){
  int b;
  int n[B];//H[b]の要素数
  int max;
  int min;
  int sum = 0;
  double avr = 0;
  double m = 0;

  for(b = 0; b < B; b++)
    for(n[b] = 0; H[b] != NULL; n[b]++)
      H[b] = H[b]->next;

  max = n[0];
  min = n[0];

  for(b = 0; b < B; b++){
    if(max < n[b])
      max = n[b];

    if(min > n[b])
      min = n[b];

    sum = sum + n[b];

  } 
  avr = sum / B;

  for(b = 0; b < B; b++)
    m = m + (n[b] - avr) * (n[b] - avr)/B;

  printf("最大値 = %d\n",max);
  printf("最小値 = %d\n",min);
  printf("分散 = %f\n",m);
}



int main(void){
 
  POINT p;
  long int n = 0;
int m = 0;
  int x;
  int y;
   unsigned int now = (unsigned int)time(0);
  srand(now);
 clock_t start,end;
  

 printf("B=%d\nN=%d\nM=%dの時\n",B,N,M);

  init_hash();
  while(1){
    x = rand()%19999 - 10000;
    y = rand()%19999 - 10000;

    if(x*x + y*y >=5000*5000 && x*x + y*y <= 10000*10000){
      p.x = x;
      p.y = y;
      if(insert_hash(p) == 1)
	n++;
    }
    if(n == N){
      break;
    }
  }

  hash_status();

  start = clock();
  while(1){
    x = rand()%19999 - 10000;
    y = rand()%19999 - 10000;
    if(x*x + y*y >=5000*5000 && x*x + y*y <= 10000*10000){
      p.x = x;
      p.y = y;
      if(search_hash(p) == 1)
	printf("登録済み");
      m++;
    }
    if(m == M)
      break;
  }
  end = clock();  
  printf("登録済みかどうかの調査にかかった時間%f秒\n",(double)(end-start)/CLOCKS_PER_SEC);

  return 0;
}
