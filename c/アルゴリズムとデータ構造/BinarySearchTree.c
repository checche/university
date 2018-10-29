#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct bst_node{
  double value;
  struct bst_node *left;
  struct bst_node *right;
}NODE;

NODE *root=NULL;

NODE *create_node(double d){
  NODE *p;
  p=(NODE*)malloc(sizeof(NODE));
  p->value=d;
  return p;
}
int insert_bst(double d){
 int count=0;
 NODE *p;
 p=(NODE*)malloc(sizeof(NODE));
  if(root==NULL){
    root=create_node(d);
    return count;
  }
  p=root;
  while(1){
    if(p->value==d)return -1;
    if(p->value>d){
     count++;
      if(p->left==NULL){
	p->left=create_node(d);
	return count;
      }
      else p=p->left;
    }
    else{
      if(p->right==NULL){
	p->right=create_node(d);
	return count;
      }
      else p=p->right;
    }
  }
}


int main(void){
  srand((unsigned)time(NULL));
  double random,c=0;
  int i,n,k = 1000;
  static double C[100000];
  clock_t start,end;

  puts("n=(1以上)?");
  scanf("%d",&n);
 
  for(i=1;i<=n;i++){
  random=rand();
  C[i] = insert_bst(random);
  }

  start=clock();
  for(i=n+1;i<=n+k;i++){
  random=rand();
  C[i]=insert_bst(random);
  }
  end=clock();

  for(i=n+1;i<=n+k;i++){
  random=rand();
  c+=C[i];
  }
  printf("n=%d k=%d %f sec 平均 %f\n",n,k,(double)(end-start)/CLOCKS_PER_SEC,(double)c/k);

  return 0;
}
