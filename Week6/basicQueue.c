#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int          data;
  struct node *next;
} node_t;

typedef node_t queue_t;

node_t *enqueue(node_t *q,int val){
    //Assign value
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data=val;
    new_node->next=NULL;

    if(q == NULL)
        q=new_node;
    else{
        node_t *tmp = q;
        while(tmp->next != NULL)
            tmp=tmp->next;
        tmp->next=new_node;
    }
    return q;
}

node_t *dequeue(node_t *q){
    if(q == NULL){
        empty(q);
        return q;
    }else{
        printf("%d\n",q->data);
        return q->next;
    }
}

void show(node_t *q){
    if(q==NULL){
        empty(q);
        return;
    }
    while(q != NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}

void empty(node_t *q){
    if(q == NULL)
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
}

void size(node_t *q){
    int cnt=0;
    while(q != NULL){
        cnt++;
        q=q->next;
    }
    printf("%d\n",cnt);
}

int main(void) {
  queue_t *q = NULL;
  int      n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;
    }
  }
  return 0;
}
