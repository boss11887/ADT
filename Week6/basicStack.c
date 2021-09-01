#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t stack_t;

node_t *push(node_t *stack, int val){
    node_t *newnode=(node_t*)malloc(sizeof(node_t));
    newnode->data=val;
    newnode->next=NULL;
    if(stack==NULL){
        stack=newnode;
    }else{
    newnode->next=stack;
    stack=newnode;
    }
    return stack;
}

void top(node_t *stack){
    if(stack == NULL){
        empty(stack);
        return;
    }
    printf("%d\n",stack->data);
}

void empty(node_t *stack){
    if(stack == NULL)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}

node_t *pop(node_t *stack){
    if(stack == NULL)
        return;
    stack=stack->next;
    return stack;
}
void size(node_t *stack){
    int cnt=0;
    while(stack!=NULL){
        cnt++;
        stack=stack->next;
    }
    printf("%d\n",cnt);
}
int main(void) {
  stack_t *s = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        s = push(s, value);
        break;
      case 2:
        top(s);
        break;
      case 3:
        s = pop(s);
        break;
      case 4:
        empty(s);
        break;
      case 5:
        size(s);
        break;
      }
  }
  return 0;
}
