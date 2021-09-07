#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node {
  int    data;
  int    height;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t avl_t;
#endif

avl_t *newNode(int data){
    avl_t *new_node=(avl_t*)malloc(sizeof(avl_t));
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    new_node->height = 1;
    return new_node;
}

int gbalance(avl_t *t){
    if(t==NULL)
        return 0;
    return height(t->left)-height(t->right);
}

int height(avl_t *t)
{
    if (t == NULL)
        return 0;
    return t->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

avl_t *rotateR(avl_t *t){
    avl_t *a = t;
    avl_t *b = t->left;

    a->left = b->right;
    b->right= a;

    a->height = max(height(a->left),height(a->right))+1;
    b->height = max(height(b->left),height(b->right))+1;

    return b;
}

avl_t *rotateL(avl_t *t){
    avl_t *a = t;
    avl_t *b = t->right;

    a->right = b->left;
    b->left= a;

    a->height = max(height(a->left),height(a->right))+1;
    b->height = max(height(b->left),height(b->right))+1;

    return b;
}
avl_t *insert(avl_t *t,int data){
    if(t==NULL)
        return newNode(data);
    else if(data < t->data)
        t->left = insert(t->left,data);
    else if(data > t->data)
        t->right= insert(t->right,data);
    //If there are same data in BST
    /*
    else
        return t;
    */

    //Rotate
    t->height=max(height(t->left),height(t->right))+1;
    int balance = gbalance(t);

    //L-L
    if(balance > 1 && data < t->left->data)
        return rotateR(t);
    //R-R
    if(balance < -1 &&data > t->right->data)
        return rotateL(t);

    //L-R
    if(balance > 1 && data > t->left->data){
        t->left = rotateL(t->left);
        return rotateR(t);
    }
    //R-L
    if(balance < -1 &&data < t->right->data){
        t->right= rotateR(t->right);
        return rotateL(t);
    }
    return t;
}

avl_t *minV(avl_t *t){
    avl_t *cur = t;
    while(cur && cur->left != NULL)
        cur=cur->left;
    return cur;
}

avl_t *delete(avl_t *t,int data){
    if(t==NULL)
        return t;
    else if(data < t->data)
        t->left = delete(t->left,data);
    else if(data > t->data)
        t->right= delete(t->right,data);
    else{
        //Delete 3 case
        if (t->left == NULL){
            avl_t *tmp = t->right;
            free(t);
            return tmp;
        }else if(t->right == NULL){
            avl_t *tmp = t->left;
            free(t);
            return tmp;
        }else{
            //Case have 2 child
            //get the smallest node of the right to be the parent
            avl_t *tmp= minV(t->right);
            t->data=tmp->data;
            t->right = delete(t->right,tmp->data);
        }
    }

    //Rotate
    t->height=max(height(t->left),height(t->right))+1;
    int balance = gbalance(t);

    //L-L
    if(balance > 1 && height(t->left->left) > height(t->left->right))
        return rotateR(t);
    //R-R
    if(balance < -1 && height(t->right->right) > height(t->right->left))
        return rotateL(t);

    //L-R
    if(balance > 1 && height(t->left->right) > height(t->left->left) ){
        t->left = rotateL(t->left);
        return rotateR(t);
    }
    //R-L
    if(balance < -1 &&height(t->right->left) > height(t->right->right) ){
        t->right= rotateR(t->right);
        return rotateL(t);
    }
    return t;
}

int main(void) {
  avl_t *t = NULL;
  int   n, i;
  int   command, data;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        t = insert(t, data);
        break;
      case 2:
        scanf("%d", &data);
        t = delete(t, data);
        break;
      case 3:
        print_tree(t);
        break;
    }
  }
  return 0;
}

/*
2. avlTree
>>> test case #1
16
1 1
1 2
1 3
3
1 4
1 5
1 6
3
1 7
1 8
1 9
1 10
3
1 11
1 12
3
>>> test case #2
16
1 12
1 11
1 10
3
1 9
1 8
1 7
3
1 6
1 5
1 4
1 3
3
1 2
1 1
3
>>> test case #3
17
1 4
1 69
1 22
1 50
1 8
1 16
1 31
1 77
1 35
1 9
1 12
1 24
1 57
1 96
3
2 9
3
>>> test case #4
21
1 4
1 69
1 22
1 50
1 8
1 16
1 31
1 77
1 35
1 9
1 12
1 24
1 57
1 96
2 9
2 69
3
2 8
3
2 22
3
*/
