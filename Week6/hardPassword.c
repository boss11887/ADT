#include <stdio.h>

typedef struct stack{
    char cur;
    struct stack *next;
} node_t;

node_t *insert(node_t *stk,char cur){
    node_t *new_node=(node_t *)malloc(sizeof(node_t));
    new_node->cur=cur;
    new_node->next=NULL;

    if(stk == NULL){
        stk=new_node;
        return stk;
    }else{
        new_node->next=stk;
        return new_node;
    }
}

node_t *pop(node_t *stk){
    return stk->next;
}

int top(node_t *stk){
    if(stk == NULL)
        return 0;
    return stk->cur;
}


int main(){
char s[1000005];
scanf("%s",&s);
node_t *stk=NULL;
int jue=0;

for(int a=0;s[a] != 'y';a++){
    if(s[a]=='x'){
        jue=1;
        continue;
    }
    if(jue){
        if(s[a]!=top(stk)){
            printf("0");
            return 0;
        }
        stk=pop(stk);
    }else{
        stk=insert(stk,s[a]);
    }
}
if(stk==NULL)
    printf("1");
else
    printf("0");
return 0;}
/*
>>> test case #1
1q2w3e4rxr4e3w2q1y
>>> test case #2
1q2w3e4rx1q2w3e4ry
>>> test case #3
1q2w3e4rx1q2w3ey
*/
