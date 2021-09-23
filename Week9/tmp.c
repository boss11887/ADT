#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int	frequencies;
  char	word[20];
  int 	have_word;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t bst_t;

// Write your code here
bst_t* New_node(char word[], int frequencies, int have_word){
	bst_t* node = (bst_t*)malloc(sizeof(bst_t));
    node->frequencies   = frequencies;
    //printf("%s\n",word);
    strcpy(node->word,word);
    node->have_word = have_word;
    node->left   = NULL;
    node->right  = NULL;
    return(node);
}

typedef struct heap {
  int *data;
  int last_index;
} heap_t;

// Write your code here

heap_t* init_heap(int m) {
	heap_t* xxnxx = (heap_t *)malloc(sizeof (heap_t));
	xxnxx->data = (int *)malloc(sizeof (bst_t*) * (m+5));
	xxnxx->data[0] = NULL;
	xxnxx->last_index = 1;
	return xxnxx;
}

void bfs(heap_t* xxnxx){
	printf("check\n");
	for(int i=1;i<xxnxx->last_index;i++){
		//printf("%d",i);
		bst_t* a = xxnxx->data[i];
		printf("%s %d \n",a->word,a->frequencies);
	}printf("\n");
	printf("check\n");
}

void insert(heap_t* xxnxx, char word[], int data){
	bst_t* newnode = New_node(word,data,1);
	xxnxx->data[xxnxx->last_index] = newnode;
	int now = xxnxx->last_index;
	xxnxx->last_index++;
	while(1){
		int pa = now/2;
		if(pa==0)	break;
		//printf("be = %d %d\n",now,pa);
		//bfs(xxnxx);
		bst_t* a = xxnxx->data[pa];
		bst_t* b = xxnxx->data[now];
		if( a->frequencies > b->frequencies ){
			bst_t* ch;
			ch = xxnxx->data[pa];
			xxnxx->data[pa] = xxnxx->data[now];
			xxnxx->data[now] = ch;
		}
		else	break;
		//printf("af = %d %d\n",now,pa);
		//bfs(xxnxx);
		now = pa;
	}
}

void insert2(heap_t* xxnxx, bst_t* newnode){
	xxnxx->data[xxnxx->last_index] = newnode;
	int now = xxnxx->last_index;
	xxnxx->last_index++;
	while(1){
		int pa = now/2;
		if(pa==0)	break;
		//printf("be = %d %d\n",now,pa);
		//bfs(xxnxx);
		bst_t* a = xxnxx->data[pa];
		bst_t* b = xxnxx->data[now];
		if( a->frequencies > b->frequencies ){
			bst_t* ch;
			ch = xxnxx->data[pa];
			xxnxx->data[pa] = xxnxx->data[now];
			xxnxx->data[now] = ch;
		}
		else	break;
		//printf("af = %d %d\n",now,pa);
		//bfs(xxnxx);
		now = pa;
	}
}

bst_t* delete_max(heap_t* xxnxx){
	if(xxnxx->last_index==1)	return NULL;
	bst_t* temp = xxnxx->data[1];
	xxnxx->data[1] = xxnxx->data[xxnxx->last_index-1];
	xxnxx->last_index--;
	int now = 1;
	//printf("%d %d\n",temp->frequencies,temp->have_word);
	//printf("%s\n",temp->word);
	if(xxnxx->last_index<=2)	return temp;
	while(1){
		int c2 = now*2+1, c1 = now*2;
		bst_t* a = xxnxx->data[now];
		bst_t* b = xxnxx->data[c1];
		bst_t* c = xxnxx->data[c2];
		//printf("%d %d %d\n",now,c1,c2);
		//printf("be...");
		//bfs(xxnxx);
		if(c1<=xxnxx->last_index && c2<=xxnxx->last_index ){
			if(b->frequencies < c->frequencies && a->frequencies > b->frequencies ){
				int ch;
				ch = xxnxx->data[c1];
				xxnxx->data[c1] = xxnxx->data[now];
				xxnxx->data[now] = ch;
				now = c1;
			}
			else if(b->frequencies > c->frequencies && a->frequencies > c->frequencies ){
				int ch;
				ch = xxnxx->data[c2];
				xxnxx->data[c2] = xxnxx->data[now];
				xxnxx->data[now] = ch;
				now = c2;
			}
			else if(b->frequencies == c->frequencies && a->frequencies > b->frequencies ){
				int ch;
				ch = xxnxx->data[c1];
				xxnxx->data[c1] = xxnxx->data[now];
				xxnxx->data[now] = ch;
				now = c1;
			}
			else 	break;
		}
		else	break;
		//printf("af...");
		//bfs(xxnxx);
	}

	return temp;
}

bst_t* combine(bst_t* a, bst_t* b){
	char word[100];
	strcpy(word,a->word);
	strcat(word,b->word);
	bst_t* newnode = New_node(word,a->frequencies+b->frequencies,0);
	newnode->left = a;
	newnode->right = b;
	//printf("test newnode\n");
  	//int arr[100];
  	//dfs(newnode,arr,0);
  	//printf("test newnode\n");
	return newnode;
}

bst_t* delete_2(heap_t* xxnxx){
	//printf("to delete\n");
	if(xxnxx->last_index==1)	return NULL;
	while(1){
		bst_t* a = delete_max(xxnxx);
		bst_t* b = delete_max(xxnxx);
		//printf("%d %d\n",a->frequencies,b->frequencies);
		if(a==NULL || b==NULL){
			if(b==NULL){
				return a;
			}
			return NULL;
		}
		else{
			insert2( xxnxx, combine(a,b) );
			//bfs(xxnxx);
		}
	}
	return NULL;
}

void dfs(bst_t* t,int arr[],int n){
	if(t==NULL)	return NULL;

	if(t->have_word==1){
		printf("%s: ",t->word);
		for(int i=0;i<n;i++){
			printf("%d",arr[i]);
		}
		printf("\n");
	}

	int arrL[n+2];
	for(int i=0;i<n;i++)	arrL[i] = arr[i];
	arrL[n] = 0;
	dfs(t->left,arrL,n+1);

	int arrR[n+2];
	for(int i=0;i<n;i++)	arrR[i] = arr[i];
	arrR[n] = 1;
	dfs(t->right,arrR,n+1);
}

// ...

int main(void) {
	heap_t *max_heap = NULL;
	int    m, n, i;
	int    command, data;
	int    old_key, new_key;

	scanf("%d %d", &m);
	max_heap = init_heap(2*m);
	char	word[m+2][20];
	int 	sq[m+2];
	for(i=0;i<m;i++){
	  	scanf("%s %d",word[i],&sq[i]);
	  	insert(max_heap,word[i],sq[i]);
	}
	//printf("\n\n");
  	//bfs(max_heap);
  	bst_t* t = delete_2(max_heap);
  	//printf("finish\n");
  	int arr[m+2];
  	dfs(t,arr,0);
  	return 0;
}

/*
9
a 1
e 2
g 1
h 2
i 3
m 1
s 5
t 1
_ 3
*/
