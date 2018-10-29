#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct _node_d{
  int data;
  struct _node_d *left;
  struct _node_d *right;
  int depth;
} NODE_D;

NODE_D *root;    // =NULL

int random_01(int min, int max){
  return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
}

NODE_D *create_node(int d, int n){
  NODE_D *p;
  p = (NODE_D *)malloc(sizeof(NODE_D));
  p->data = d;
  p->left = NULL;
  p->right = NULL;
  p->depth = n;
  return p;
}

void insert_data_depth(int d){
  NODE_D *p;
  int a;
  int n = 0;

  if(root == NULL){
    root = create_node(d ,n);
    p = root;
    return;
  }
  else {
    p = root;
    n++;
  }

  while(1){
    a = random_01(0, 1);
    if(a == 0){
      if(p->left == NULL){
	p->left = create_node(d, n);
	break;
      }
      else{
	p = p->left;
	n++;
      }
    }
    else {
	if(p->right == NULL){
	  p->right = create_node(d, n);
	  break;
	}
	else {
	  p = p->right;
	  n++;
	}
      } 
     
  }
    return;
  }

void preorder (NODE_D *node){
  if(node == NULL) return;
  printf("%d %d\n", node->data, node->depth);
  preorder(node->left);
  preorder(node->right);
}

struct queue{
  NODE_D *data[10];
  int head;
  int tail;
}; 

void initialize(struct queue *q){
  int i;
  
  q->head=0;
  q->tail=0;
  for(i=0; i < 10; ++i){
    q->data[i]=' ';
  }
}

void enqueue(struct queue *q, NODE_D *item){
  if (q->tail+1 == q->head) {
    printf("This queue is full! \n");
  }else{
    q->data[q->tail]=item;
    q->tail = q->tail%10+1;
  }
}
/*
void enqueue(NODE_D *queue[], NODE_D *d){
  if ((rear+1) == front){
    printf("Queue Overflow");
    return;
  }
  *queue[rear] = *d;
  rear = rear%10+1;
}
*/

NODE_D *dequeue(struct queue *q){
  NODE_D *tmp;
  
  if(q->head == q->tail){
    return -1;
  }else{
    tmp=q->data[q->head];
    q->head = q->head%10+1;
    return tmp;
  }
}

/*
NODE_D *dequeue(NODE_D *queue[]){
  NODE_D *x;
  x = (NODE_D *)malloc(sizeof(NODE_D));
  if (front == rear)
    printf("Queue Underflow");
  *x = *queue[front];
  front = front%10+1;
  return x;
}
*/

int bfs_depth(int d){
  NODE_D *node;
  NODE_D *queue;
  int n = 0;
  node = (NODE_D *)malloc(sizeof(NODE_D));
  enqueue(queue, root);
  while (q->tail != q->head){
    node = dequeue(queue);
    if(node->data == d)
      return node->depth;
    n++;
    if (node->left != NULL)
      enqueue(queue, node->left);
    if (node->right != NULL)
      enqueue(queue, node->right);
  }
  return 0;
}

int main(void){
  int d;
  int n;
  int b;


  scanf("%d",&n);
  printf("\n");

  for(d = 0; d < n; d++)
    insert_data_depth(d);

  preorder(root);

  scanf("%d",&b);

  bfs_depth(b);


 


  return(0);
}
