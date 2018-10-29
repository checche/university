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


int height(NODE *p){
  int l,r;
  if (p ==NULL)
    return -1;
  l = height(p->left);
  r = height(p->right);

  if(l >= r)
    return l+1;
  else
    return r+1;
}

int isAVL(NODE *p){
  int l,r;
  if(p == NULL)
    return 1;

  l = height(p->left);
  r = height(p->right);
  if(l - r >= 2 || l - r <= -2)
    return 0;

  if(isAVL(p->left) == 1 && isAVL(p->right) == 1
     && (l - r == 1 || l - r == 0 || l - r == -1))
    return 1;
  else 
    return 0;

}

total_depth(NODE *p, int d){
  if(p ==NULL)
    return 0;

 return total_depth(p->left) + total_depth(p->right);
