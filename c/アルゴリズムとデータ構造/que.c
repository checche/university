#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define next(x)(((x)+1)%SIZE)
#define SIZE 100000000


typedef struct _node{
  int data;
  struct _node *left;
  struct _node *right;
  int depth;
}NODE;

NODE *root;
NODE *QUEUE[SIZE];
int rear=0;
int front=0;

void enqueue(NODE *node){
  if(rear+1 == front){
    printf("Queue Overflow!!");
    exit(1);}
    QUEUE[rear]=node;
    rear=next(rear);}

NODE *dequeue(){
       NODE *d;
       if(front==rear){
	 printf("Queue Underflow!");
	 exit(1);}
       d=QUEUE[front];
       front = next(front);
       return d;}

     int bfs_depth(int x){
       NODE *q;
       enqueue(root);
       while(front!=rear){
	 q=dequeue();
	 if(q->data==x)
	   return q->depth;
	 if(q->left != NULL){
	   enqueue(q->left);
	 }
	     if(q->right != NULL){
	       enqueue(q->right);
	     }
	 }
	 exit(1);
       }



NODE *create_node(int d,int k){
  
  NODE *p;
  p=(NODE*)malloc(sizeof(NODE));
  p->data=d;
  p->left=NULL;
  p->right=NULL;
  p->depth=k;
  
  return p;
}


void insert_data(int d){
  
  NODE *p;
  int k=1;
  p=(NODE*)malloc(sizeof(NODE));
  
if(root==NULL)
  root=create_node(d,0);
  else 
    p=root;
 int a;
while(1){
a=(double)rand()/((double)RAND_MAX+1.0)*100;
 if(a%2==0){
    if(p->left==NULL){
      
      p->left=create_node(d,k);
      
      
      break;}
      
	else
      p=p->left;
    k=k+1;
  }

 if(a%2==1){
      if(p->right==NULL){

	p->right=create_node(d,k);
	k=k+1;
	break;}
	else
	  p=p->right;
      k=k+1;    
 }
 }
}
void preorder (NODE*node){
  if(node==NULL)
    return ;

  printf("%d:%d\n",node->data,node->depth);
  preorder(node->left);
  preorder(node->right);
}




 int main(void){
  
   int  n,d,t;
 clock_t start,end;
 int ac[1000];
 srand((unsigned)time(NULL));
     
      printf("n=");
      scanf("%d",&n);
      //   printf("serch:");
      for(d=0;d<1000;d++)
	ac[d] = 5*(d+1);

      /*    if(x>n){
	printf("error\n");
	return 0;
      }
      */
     
      for(d=0;d<n;d++)	
	insert_data(d);
      for(d=0;d<1000;d++){
 start = clock();
      t=bfs_depth(ac[d]*10000);  
      end=clock();
 
      // preorder(root);
      

  
      printf("%d 深さ%d  ",ac[d]*10000,t);
      printf("%f 秒\n",(double)(end-start)/CLOCKS_PER_SEC);
      }
 return 0;

 }
