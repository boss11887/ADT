#include <stdio.h>

typedef struct node{
    int left;
    int pos;
    struct node *next;
}node_t;
node_t *list=NULL;
node_t *st;

int main(){
int n,k;
scanf("%d %d",&n,&k);

for(int a=1;a<=n;a++){
    int cur;
    scanf("%d",&cur);
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->left=cur;
    new_node->pos=a;
    new_node->next=NULL;
    if(a==1){
        list=new_node;
        st=new_node;
    }else{
        list->next=new_node;
        list=list->next;
    }
}
list->next=st;
node_t *cur = st;
node_t *last=list;

int cnt=0;
n-=1;
while(n){
    cnt++;
    int jue=0,chua=cnt;
    while(chua){
        if(k==chua%10){
            jue=1;
            break;
        }
        chua/=10;
    }
    if(cnt%k==0 || jue){
        cur->left--;
        if(cur->left == -1){
            last->next=cur->next;
            n--;
        }else{
        last=cur;
        }
    }else{
    last=cur;
    }
    cur=cur->next;
    //printf("%d ",cur->pos);
}
printf("%d",cur->pos);
return 0;}

/*
>>> test case #1
5 2
1 5 3 1 2
>>> test case #2
5 3
1 5 3 1 2
>>> test case #3
10 9
97 65 84 21 5 43 58 18 63 91 99
*/
