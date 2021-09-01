#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node_t;

node_t *append(node_t *l){
    int val;
    scanf("%d",&val);

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data=val;
    new_node->next=NULL;

    node_t *tmp = l;
    if(l==NULL){
        l=new_node;
    }else{
        while(tmp->next != NULL){
            tmp=tmp->next;
        }
        tmp->next=new_node;
    }
    return l;
}

void show(node_t *l){
    while(l != NULL){
        printf("%d ",l->data);
        l=l->next;
    }
    printf("\n");
}

void get(node_t *l){
    int nub,cnt=0;
    scanf("%d",&nub);
    while(l != NULL && cnt < nub){
        l=l->next;
        cnt++;
    }
    printf("%d\n",l->data);
}

node_t *reverse(node_t *l){

node_t *last=NULL;
node_t *cur=l;
node_t *nexx=NULL;
while(cur!=NULL){
    nexx=cur->next;
    cur->next=last;
    last=cur;
    cur=nexx;
}
l=last;
return l;
}

node_t *cut(node_t *l){
int st,ed;
scanf("%d %d",&st,&ed);
node_t *temp=l;
int count=0;
while(temp!=NULL){
    if(count==st){
        l=temp;
    }
    if(count==ed){
        temp->next=NULL;
    }
    count++;
    temp=temp->next;
}
return l;
}

int main(){
    node_t *startNode = NULL;
    int n,i;
    char command;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf(" %c",&command);
        switch(command){
            case 'A':
                startNode =append(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                startNode = cut(startNode);
                break;
            default:
                break;
        }
    }
return 0;}
