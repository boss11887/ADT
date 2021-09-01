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
node_t *empty(node_t *stk){
    if(stk == NULL)
        return 1;
    return 0;
}
int top(node_t *stk){
    if(stk == NULL)
        return 0;
    return stk->cur;
}

int cmp(char s1,char s2){
    if(s1 == '[' && s2 == ']')
        return 1;
    if(s1 == '{' && s2 == '}')
        return 1;
    if(s1 == '(' && s2 == ')')
        return 1;
    return 0;
}
int main(){
int n;
scanf("%d",&n);
char s[1000005];
scanf("%s",&s);
node_t *stk=NULL;

for(int a=0;a<n;a++){
    if(cmp(top(stk),s[a])){
        stk=pop(stk);
    }else{
        stk=insert(stk,s[a]);
    }
}
if(empty(stk))
    printf("1");
else
    printf("0");
return 0;}
