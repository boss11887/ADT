#include <stdio.h>
#include <stdlib.h>
#include <week8.h>

#ifndef __bin_tree__
typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif

int is_full(tree_t *t){
    if(t==NULL)
        return 1;
    if(t->left == NULL && t->right==NULL)
        return 1;
    if(t->left && t->right)
        return (is_full(t->left) && is_full(t->right));
    return 0;
}

int perfect_cnt(tree_t *t){
    if(t==NULL)
        return 1;
    int ls=perfect_cnt(t->left);
    int rs=perfect_cnt(t->right);
    if(ls == rs)
        return ls+rs;
    return 0;
}
int is_perfect(tree_t *t){
    if(perfect_cnt(t) !=0)
        return 1;
    return 0;
}

int size(tree_t *t)
{
    if (t == NULL)
        return 0;
    return (1 + size(t->left) + size(t->right));
}

int is_complete2(tree_t *t,int cur,int all){
    if(t==NULL)
        return 1;
    if(cur > all)
        return 0;
    return (is_complete2(t->left,cur*2,all) && is_complete2(t->right,cur*2+1,all));
}
int is_complete(tree_t *t){
    return is_complete2(t,1,size(t));
}

int is_degenerate(tree_t *t){
    if(t==NULL)
        return 1;
    if(t->left != NULL && t->right != NULL)
        return 0;
    if(t->left != NULL)
        return is_degenerate(t->left);
    return is_degenerate(t->right);
}

/*
status 0 = left;
status 1 = right;
*/
int is_skewed2(tree_t *t, int status){
    if(t==NULL)
        return 1;
    if( (status==0 && t->right != NULL) || (status==1 && t->left != NULL))
        return 0;
    if(!status)
        return is_skewed2(t->left,status);
    return is_skewed2(t->right,status);
}
int is_skewed(tree_t *t){
    if(t->left != NULL)
        return is_skewed2(t,0);
    return is_skewed2(t,1);
}

int main(void) {
  tree_t *t = NULL;
  int n, i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }

  printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

  return 0;
}