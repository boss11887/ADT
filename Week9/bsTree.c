#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;
typedef node_t bst_t;

bst_t *newD(int data){
    bst_t *new_node=(bst_t*)malloc(sizeof(bst_t));
    new_node->left = new_node->right = NULL;
    new_node->data = data;
    return new_node;
}
// Write your code here
bst_t *insert(bst_t *t,int data){
    if (t==NULL)
        return newD(data);
    if(data < t->data)
        t->left = insert(t->left,data);
    else
        t->right= insert(t->right,data);
    return t;
}

bst_t *minV(bst_t *t){
    bst_t *cur = t;
    while(cur && cur->left != NULL)
        cur=cur->left;
    return cur;
}

bst_t *delete(bst_t *t,int data){
    if (t==NULL)
        return t;
    if(data < t->data)
        t->left = delete(t->left,data);
    else if(data > t->data)
        t->right= delete(t->right,data);
    else{
        //Case have child (L or R) or no child
        if (t->left == NULL){
            bst_t *tmp = t->right;
            free(t);
            return tmp;
        }else if(t->right == NULL){
            bst_t *tmp = t->left;
            free(t);
            return tmp;
        }
        //Case have 2 child
        //get the smallest node of the right to be the parent
        bst_t *tmp= minV(t->right);
        t->data=tmp->data;
        t->right = delete(t->right,tmp->data);
    }
    return t;
}

int find(bst_t *t,int data){
    if(t==NULL)
        return 0;
    if(data == t->data)
        return 1;
    if(data < t->data)
        return find(t->left,data);
    else
        return find(t->right,data);
}

bst_t *find_min(bst_t *t){
    bst_t *cur = t;
    while(cur && cur->left != NULL)
        cur=cur->left;
    return cur->data;
}

bst_t *find_max(bst_t *t){
    bst_t *cur = t;
    while(cur && cur->right != NULL)
        cur=cur->right;
    return cur->data;
}


int main(void) {
  bst_t *t = NULL;
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
        scanf("%d", &data);
        printf("%d\n", find(t, data));
        break;
      case 4:
        printf("%d\n", find_min(t));
        break;
      case 5:
        printf("%d\n", find_max(t));
        break;
    }
  }
  return 0;
}

/*
1. bsTree
>>> test case #1
16
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
3 1
3 10
3 15
3 20
>>> test case #2
16
1 1
1 2
1 3
1 4
4
5
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
4
5
>>> test case #3
16
1 82
1 79
1 66
1 78
3 79
2 79
3 79
1 93
1 99
1 5
1 61
1 68
1 3
5
2 99
5
>>> test case #4
7
3 11
1 3
1 90
1 43
3 50
4
5
>>> test case #5
13
1 50
1 8
1 61
1 1
1 35
1 87
2 50
3 50
2 8
2 61
3 8
3 87
3 61
*/
