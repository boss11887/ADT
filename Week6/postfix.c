#include <stdio.h>
#include <stdlib.h>
typedef struct stk{
    double val;
    struct stk *next;
} node_t;

node_t *insert(node_t *stk,double v){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->val=v;
    new_node->next=NULL;

    if(stk!=NULL){
        new_node->next=stk;
    }
    return new_node;
}

float top(node_t *stk){
    if(stk == NULL){
        return 0;
    }
    return stk->val;
}
node_t *pop(node_t *stk){
    return stk->next;
}
int main(){
int n;
scanf("%d",&n);
char s[1000005];
scanf("%s",s);
node_t *stk=NULL;
for(int a=0;a<n;a++){
    if(s[a] >= '0' && s[a] <='9'){
        stk=insert(stk,s[a]-'0');
    }else{
        double ans;
        double v1=top(stk);
        stk = pop(stk);
        double v2=top(stk);
        stk = pop(stk);
        switch (s[a]) {
            case '+':
                ans=(v2+v1);
                break;
            case '-':
                ans=(v2-v1);
                break;
            case '*':
                ans=(v2*v1);
                break;
            case '/':
                ans=(v2/v1);
                break;
        }
        stk=insert(stk,ans);
    }
}
printf("%.2lf",top(stk));

return 0;}
