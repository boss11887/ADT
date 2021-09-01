#include <stdio.h>

typedef struct node{
    int type;
    int num;
    double dnum;
    char name[15];
    struct node *next;
    struct node *last;
} node_t;
node_t *endNode = NULL;
node_t *startNode = NULL;

//append to the end
node_t *append(node_t *l){
    int type,val;
    scanf("%d",&type);

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->type=type;
    new_node->num=0;
    new_node->dnum=0;
    new_node->name[0]=0;
    new_node->next=NULL;
    new_node->last=NULL;

    if(type==0){
        scanf("%d",&val);
        new_node->num=val;
    }else if(type==1){
        double mlf;
        scanf("%lf",&mlf);
        new_node->dnum=mlf;
    }else{
        char s[15];
        scanf("%s",s);
        for(int a=0;s[a] != '\0';a++){
            new_node->name[a]=s[a];
        }
    }
    node_t *tmp = l;
    node_t *ll= l;
    if(l==NULL){
        l=new_node;
    }else{
        while(tmp->next != NULL){
            ll=tmp;
            tmp=tmp->next;
        }
        endNode=new_node;
        new_node->last=tmp;
        tmp->next=new_node;
    }
    return l;
}

//show
void show(node_t *l){
    while(l != NULL){
        if(l->type == 0){
            printf("%d ",l->num);
        }else if(l->type == 1){
            printf("%f ",l->dnum);
        }else{
            for(int p=0;l->name[p] != '\0';p++){
                printf("%c",l->name[p]);
            }
            printf(" ");
        }
        l=l->next;
    }
    printf("\n");
}

//get current position
void get(node_t *l){
    int nub,cnt=0;
    scanf("%d",&nub);
    while(l != NULL && cnt < nub){
        l=l->next;
        cnt++;
    }
    if(l->type == 0){
            printf("%d ",l->num);
        }else if(l->type == 1){
            printf("%f ",l->dnum);
        }else{
            for(int p=0;l->name[p] != '\0';p++){
                printf("%c",l->name[p]);
            }
            printf(" ");
        }
    printf("\n");
}

//is_empty
void is_empty(node_t *l){
    if(l==NULL){
        printf("Empty");
    }else{
        printf("Not Empty");
    }
    printf("\n");
}

//check-size
int length(node_t *l){
    int cnt=0;
    while(l != NULL){
        cnt++;
        l=l->next;
    }
    return cnt;
}


//Reverse
void show_reverse(node_t *l){
    while(l != NULL){
        if(l->type == 0){
            printf("%d ",l->num);
        }else if(l->type == 1){
            printf("%f ",l->dnum);
        }else{
            for(int p=0;l->name[p] != '\0';p++){
                printf("%c",l->name[p]);
            }
            printf(" ");
        }
        l=l->last;
    }
    printf("\n");
}

//Delete postion
node_t *delete(node_t *l){
    int want,cnt=0;
    scanf("%d",&want);

    node_t *fix = l;
    node_t *ne = l;
    if(want ==0){
        if(length(l)==1){
            endNode=NULL;
            return l=NULL;
        }
        ne=ne->next;
        ne->last=NULL;
        l=ne;
        return l;
    }else if(want==length(l)-1){
        ne=endNode->last;
        ne->next=NULL;
        endNode=ne;
        return l;
    }
    while(l != NULL){
        if(cnt==want)
            break;
        cnt++;
        l=l->next;
    }
    node_t *nextpos=l->next;
    node_t *lastpos=l->last;

    nextpos->last=lastpos;
    lastpos->next=nextpos;
    return fix;
}


//change
void change(node_t *l){
    int pos,type;
    scanf("%d %d",&pos,&type);

    int cnt=0;
    while(l != NULL){
        if(pos == cnt){
            break;
        }
        cnt++;
        l=l->next;
    }
    l->type=type;
    if(type==0){
        int val;
        scanf("%d",&val);
        l->num=val;
    }else if(type==1){
        double mlf;
        scanf("%lf",&mlf);
        l->dnum=mlf;
    }else{
        char s[15];
        scanf("%s",s);
        for(int a=0;s[a] != '\0';a++){
            l->name[a]=s[a];
        }
    }
}

//Insert
void insert(node_t *l){
    int pos,type;
    scanf("%d %d",&pos,&type);

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->type=type;
    new_node->num=0;
    new_node->dnum=0;
    new_node->name[0]=0;
    new_node->next=NULL;
    new_node->last=NULL;

    if(type==0){
        int val;
        scanf("%d",&val);
        new_node->num=val;
    }else if(type==1){
        double mlf;
        scanf("%lf",&mlf);
        new_node->dnum=mlf;
    }else{
        char s[15];
        scanf("%s",s);
        for(int a=0;s[a] != '\0';a++){
            new_node->name[a]=s[a];
        }
    }

    int cnt=0;
    while(l != NULL){
        if(pos == cnt){
            break;
        }
        cnt++;
        l=l->next;
    }
    node_t *nextpos;
    if(l->next != NULL){
        nextpos=l->next;
    }else{
        nextpos=NULL;
        endNode=new_node;
    }
    l->next=new_node;
    new_node->next=nextpos;

    if (nextpos != NULL)
        nextpos->last=new_node;
    new_node->last=l;
}

/*
10
A 2 I
A 2 am
C 1 2 You
C 0 2 hungry
I 0 2 are
R
I 1 2 guys

*/
int main(){
int n;
scanf("%d",&n);
while(n--){
    char mc;
    scanf(" %c",&mc);
    switch(mc){
            case 'A':
                startNode = append(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'E':
                is_empty(startNode);
                break;
            case 'L':
                printf("%d\n",length(startNode));
                break;
            case 'R':
                show_reverse(endNode);
                break;
            case 'D':
                startNode = delete(startNode);
                break;
            case 'C':
                change(startNode);
                break;
            case 'I':
                insert(startNode);
                break;
            default:
                break;
        }
}

return 0;}
