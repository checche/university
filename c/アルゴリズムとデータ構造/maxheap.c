#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5000000

static int A_BIN[N],A_OCT[N];
int n=0,n2=0,i=0;

int insert_bin_heap(int d){//2分ヒープにデータ格納
 int count=0;
  n++;//データ数n+1個目にdを格納する
  A_BIN[n-1]=d;
  i=n-1;
  while(i!=0){//登録データ数が2個以上の場合
    if(A_BIN[i]>A_BIN[(i-1)/2]){//子>親
      A_BIN[i]=A_BIN[(i-1)/2];//子に親を代入
      A_BIN[(i-1)/2]=d;//親のデータがd 子と親のデータ交換
      count++;
      i=(i-1)/2;//節点を親の親へ移動
    }
  else break;
  }
 return count;
}

int insert_oct_heap(int d){//8分ヒープにデータ格納
 int count=0;
  n++;//データ数n+1個目にdを格納する
  A_OCT[n-1]=d;
  i=n-1;
  while(i!=0){
    if(A_OCT[i]>A_OCT[(i-1)/8]){//子>親
      A_OCT[i]=A_OCT[(i-1)/8];//子に親を代入
      A_OCT[(i-1)/8]=d;//親のデータがd 子と親のデータ交換
      count++;
      i=(i-1)/8;//親の親へ移動
    }
  else break;
  }
 return count;
}

int deletemax_bin_heap(){
  int snode,svalue,scount=0;
  if(n==0)return-1;
  if(n==1){
    n=0; return 0;
  }
  A_BIN[0]=A_BIN[n-1];//最初のデータに最後のデータを代入
  n--;
  i=0;//根からスタート
  while(2*i+1<=n-1){//子が存在する場合
    if(2*i+1==n-1){//左の子のみの場合
      snode=2*i+1;
      svalue=A_BIN[2*i+1];
      scount++;
    }
    else{//左右に子がいる場合
      if(A_BIN[2*i+1]>=A_BIN[2*i+2]){//左の子が大きい
	snode=2*i+1;
	svalue=A_BIN[2*i+1];
        scount++;
      }
      else{//右の子が大きい
	snode=2*i+2;
	svalue=A_BIN[2*i+2];
        scount++;
      }
    }
    if(A_BIN[i]<svalue){//親が小さい場合
      A_BIN[snode]=A_BIN[i];//親と子を交換
      A_BIN[i]=svalue;
      i=snode;
      scount++;
    }
    else return scount;//子が小さい場合
  }
  return scount;
}

int deletemax_oct_heap(){
  int snode,svalue,node,nodecount=0,scount=0;
  if(n==0)return-1;
  if(n==1){
    n=0; return 0;
  }
  A_OCT[0]=A_OCT[n-1];//最初のデータに最後のデータを代入
  n--;
  i=0;//根からスタート
  while(8*i+1<=n-1){//子が存在する場合
    node=1;

    while(node<=8){//子の数を数える
      if(8*i+node<=n-1)nodecount++;
      node++;
    }

    snode=8*i+1;
    node=1;

    while(node<=nodecount){
     if(A_OCT[8*i+node]>=A_OCT[snode]){
       snode=8*i+node;
       svalue=A_OCT[8*i+node];
       scount++;
     }
    node++;
   }
    if(A_OCT[i]<svalue){//親が小さい場合
      A_OCT[snode]=A_OCT[i];//親と子を交換
      A_OCT[i]=svalue;
      i=snode;
      scount++;
    }
    else return scount;//子が小さい場合
  }
  return scount;
}

int main(void){
  static int i,d,A[N],C[N],B;
  clock_t start,end;

  //配列に格納
  for(i=0;i<=N-1;i++){
    d=rand()%100;
    A[i]=d;
  } 
  printf("N = %d\n",N);

 //2分木と8分木の２パターン入れてるのでどちらか片方コメントアウトしてから使ってください
  //2分木の場合
  printf("2分ヒープ\n");
  start=clock();
  for(i=0;i<=N-1;i++){
    B+=insert_bin_heap(A[i]);
  }
  end=clock();
  printf("Cins = %d 回\nTins = %f 秒\n",B,(double)(end-start)/CLOCKS_PER_SEC);

  
 start=clock();
 for(i=0;i<=N-1;i++){
    C[i]=deletemax_bin_heap();
  }
 end=clock();

 for(i=1;i<=N-1;i++){
   C[0]+=C[i];
 }
 printf("Cdel = %d 回\nTdel = %f 秒\n",C[0],(double)(end-start)/CLOCKS_PER_SEC);

  //8分木の場合
 printf("8分ヒープ\n");
  start=clock();
  for(i=0;i<=N-1;i++){
    B+=insert_oct_heap(A[i]);
  }
  end=clock();
  printf("Cins = %d 回\nTins = %f 秒\n",B,(double)(end-start)/CLOCKS_PER_SEC);

  
 start=clock();
 for(i=0;i<=N-1;i++){
    C[i]=deletemax_oct_heap();
  }
 end=clock();

 for(i=1;i<=N-1;i++){
   C[0]+=C[i];
 }
 printf("Cdel = %d 回\nTdel = %f 秒\n",C[0],(double)(end-start)/CLOCKS_PER_SEC);

 return 0;
}
