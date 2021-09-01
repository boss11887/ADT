#include <stdio.h>
#include <stdlib.h>

// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
typedef struct node {
    int name;
    struct node *sibling;
    struct node *child;
} node_t;
typedef node_t tree_t;


//Stack
typedef struct nodd {
  int          data;
  struct nodd *next;
} ee_t;
typedef ee_t stack_t;
stack_t *push(stack_t *stack, int val){
    stack_t *newnode=(stack_t*)malloc(sizeof(stack_t));
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
int top(stack_t *stack){
    if(stack == NULL){
        empty(stack);
        return 0;
    }
    return stack->data;
}
int empty(stack_t *stack){
    if(stack == NULL)
        return 1;
    else
        return 0;
}
stack_t *pop(stack_t *stack){
    if(stack == NULL)
        return;
    stack_t *tmp=stack;
    stack=stack->next;
    free(tmp);
    return stack;
}
int size(stack_t *stack){
    int cnt=0;
    while(stack!=NULL){
        cnt++;
        stack=stack->next;
    }
    return cnt;
}
//Stack
stack_t *s = NULL;

// Write your code here
node_t *search_p(node_t *t,int p){
    if(t==NULL)
        return t;
    if(t->name == p)
        return t;
    node_t *pos = search_p(t->child,p);
    if(pos != NULL)
        return pos;
    else
        return search_p(t->sibling,p);
}
///Case 3
int search(node_t *t,int p){
    if(search_p(t,p) != 0)
        return 1;
    return 0;
}

///Case 1
node_t *attach(node_t *t,int p,int c){
    tree_t *new_node=(tree_t*)malloc(sizeof(tree_t));
    new_node->sibling=NULL;
    new_node->child=NULL;
    new_node->name=c;

    if(p == -1){
        t=new_node;
        return t;
    }
    node_t *pos = search_p(t,p);
    if(pos->child == NULL){
        pos->child = new_node;
    }else{
        pos = pos->child;
        while(pos->sibling != NULL)
            pos = pos->sibling;
        pos->sibling=new_node;
    }
    return t;
}


///Case 2


int sib(node_t *t,int node){
    if(t == NULL)
        return NULL;
    if(t->name == node)
        return 1;
    if(sib(t->child,node) || sib(t->sibling,node)){
        s=push(s,t->name);
        return 1;
    }
}
node_t *detach(node_t *t,int node){
    ancestor(t, node);
    int parent=0;
    while(!empty(s)){
        parent=top(s);
        s=pop(s);
    }
    //printf("%d",parent);
    sib(t, node);
    int ssib=0;
    while(!empty(s)){
        ssib=top(s);
        s=pop(s);
    }
    node_t *sib_pos = search_p(t,ssib);
    node_t *cur_pos = search_p(t,node);
    node_t *par_pos = search_p(t,parent);
    if(ssib==parent){
        free(cur_pos);
        sib_pos->child=sib_pos->child->sibling;
    }else{
        if(cur_pos->sibling == NULL){
            free(cur_pos);
            sib_pos->sibling=NULL;
        }else{
            sib_pos->sibling=cur_pos->sibling;
            free(cur_pos);
        }
    }
    return t;
}

///Case 4
int degree(node_t *t,int node){
    node_t *pos = search_p(t,node);
    int cnt=0;
    if(pos->child != NULL){
    cnt++;
    pos = pos->child;
        while(pos->sibling != NULL){
            pos = pos->sibling;
            cnt++;
        }
    }
    return cnt;
}
///Case 5
int is_root(node_t *t,int node){
    if(t->name==node)
        return 1;
    return 0;
}
///Case 6
int is_leaf(node_t *t,int node){
    node_t *pos = search_p(t,node);
    if(pos->child == NULL)
        return 1;
    return 0;
}

///Case 11
int ancestor(node_t *t,int node){
    if(t == NULL)
        return NULL;
    if(t->name == node)
        return 1;
    int want = ancestor(t->child,node);
    if(want || ancestor(t->sibling,node)){
        if(want){
            s=push(s,t->name);
        }
        return 1;
    }
}


///Case 7
void siblings(node_t *t,int node){
    ancestor(t, node);
    int parent=0;
    while(!empty(s)){
        parent=top(s);
        s=pop(s);
    }
    //printf("(%d) ",parent);
    if(!parent)
        return;
    node_t *find = search_p(t,parent);
    node_t *chua = find->child;
    while(chua != NULL){
        if(chua->name != node)
            printf("%d ",chua->name);
        chua=chua->sibling;
    }
}
///Case 8
int depth(node_t *t,int node){

    ancestor(t, node);
    int ans=size(s);
    while(!empty(s)){
        s=pop(s);
    }
    return ans;
}


///Case 9
int print_path_ans(node_t *t,int p){
    if(t==NULL)
        return t;
    if(t->name == p){
        s=push(s,t->name);
        return t;
    }
    node_t *pos = print_path_ans(t->child,p);
    if(pos != NULL){
        s=push(s,t->name);
        return pos;
    }else
        return print_path_ans(t->sibling,p);
}
int print_path(node_t *t,int st,int ed){
    node_t *from=search_p(t,st);
    print_path_ans(from,ed);
    while(!empty(s)){
        printf("%d ",top(s));
        s=pop(s);
    }
}

///Case 10
int path_length(node_t *t,int st,int ed){
    node_t *from=search_p(t,st);
    print_path_ans(from,ed);
    int ans=size(s);
    while(!empty(s)){
        s=pop(s);
    }
    return ans;
}

///Case 12
void descendant(node_t *t,int node){
    tree_t *ar[10005];
    int now=1,last=1;
    tree_t *pos = search_p(t,node);
    ar[now]=pos;
    while(now<=last){
        printf("%d ",ar[now]->name);
        node_t *chua = ar[now]->child;
        now++;
        while(chua!=NULL){
            last++;
            ar[last]=chua;
            chua=chua->sibling;
        }
    }
}
///Case 13
node_t *dfs(node_t *t){
    if(t == NULL)
        return NULL;
    printf("%d ",t->name);
    node_t *pos = dfs(t->child);
    if(pos != NULL)
        return pos;
    return dfs(t->sibling);
}
///Case 14
node_t *bfs(node_t *t){
    tree_t *ar[10005];
    int now=1,last=1;
    ar[now]=t;
    while(now<=last){
        printf("%d ",ar[now]->name);
        node_t *chua = ar[now]->child;
        now++;
        while(chua!=NULL){
            last++;
            ar[last]=chua;
            chua=chua->sibling;
        }
    }
}

///Case 15
node_t *pt(node_t *t,int yao){
    if(t == NULL)
        return NULL;
    for(int i=0;i<yao;i++){
        printf("    ");
    }
    printf("%d\n",t->name);
    node_t *pos = pt(t->child,yao+1);
    if(pos != NULL)
        return pos;
    return pt(t->sibling,yao);
}
void print_tree(node_t *t){
    pt(t,0);
}
/*
test1
15
1 -1 1
1 1 2
1 1 3
1 2 4
1 2 5
1 3 6
1 3 7
1 4 8
1 5 9
1 5 10
1 6 11
1 6 12
1 6 13
1 13 14
13
*/
int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        printf("\n");
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        printf("\n");
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        while(!empty(s)){
            printf("%d ",top(s));
            s=pop(s);
        }
        printf("%d ",node);
        printf("\n");
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        printf("\n");
        break;
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;
    }
  }
  return 0;
}
