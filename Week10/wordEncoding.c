#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nn {
  char	word[20];
  int	freq;
  int 	yao;
  struct node *left;
  struct node *right;
} bst_t;


bst_t* new_node(char word[], int freq, int yao){
	bst_t* tmp = (bst_t*)malloc(sizeof(bst_t));
	strcpy(tmp->word,word);
    tmp->freq   = freq;
    tmp->yao = yao;
    tmp->left   = NULL;
    tmp->right  = NULL;
    return tmp;
}

typedef struct heap {
  int *data;
  int last_index;
} heap_t;

heap_t* init_heap(int m) {
	heap_t* pq = (heap_t *)malloc(sizeof (heap_t));
	pq->data = (int *)malloc(sizeof (bst_t*) * (m+5));
	pq->last_index = 1;
	return pq;
}

void insert(heap_t* pq, char word[], int data){
	bst_t* tmp = new_node(word,data,1);
	pq->data[pq->last_index] = tmp;
	int now = pq->last_index;
	pq->last_index++;
	while(1){
		int pa = now/2;
		if(pa==0)	break;
		bst_t* a = pq->data[pa];
		bst_t* b = pq->data[now];
		if( a->freq > b->freq ){
			bst_t* ch;
			ch = pq->data[pa];
			pq->data[pa] = pq->data[now];
			pq->data[now] = ch;
		}
		else	break;
		now = pa;
	}
}

void insert2(heap_t* pq, bst_t* tmp){
	pq->data[pq->last_index] = tmp;
	int now = pq->last_index;
	pq->last_index++;
	while(1){
		int pa = now/2;
		if(pa==0)	break;
		bst_t* a = pq->data[pa];
		bst_t* b = pq->data[now];
		if( a->freq > b->freq ){
			bst_t* ch;
			ch = pq->data[pa];
			pq->data[pa] = pq->data[now];
			pq->data[now] = ch;
		}
		else	break;
		now = pa;
	}
}

bst_t* delete_max(heap_t* pq){
	if(pq->last_index==1)	return NULL;
	bst_t* temp = pq->data[1];
	pq->data[1] = pq->data[pq->last_index-1];
	pq->last_index--;
	int now = 1;
	if(pq->last_index<=2)	return temp;
	while(1){
		int c2 = now*2+1, c1 = now*2;
		bst_t* a = pq->data[now];
		bst_t* b = pq->data[c1];
		bst_t* c = pq->data[c2];
		if(c1<=pq->last_index && c2<=pq->last_index ){
			if(b->freq < c->freq && a->freq > b->freq ){
				int ch;
				ch = pq->data[c1];
				pq->data[c1] = pq->data[now];
				pq->data[now] = ch;
				now = c1;
			}
			else if(b->freq > c->freq && a->freq > c->freq ){
				int ch;
				ch = pq->data[c2];
				pq->data[c2] = pq->data[now];
				pq->data[now] = ch;
				now = c2;
			}
			else if(b->freq == c->freq && a->freq > b->freq ){
				int ch;
				ch = pq->data[c1];
				pq->data[c1] = pq->data[now];
				pq->data[now] = ch;
				now = c1;
			}
			else 	break;
		}
		else	break;
	}

	return temp;
}

bst_t* combine(bst_t* a, bst_t* b){
	char word[50];
	strcpy(word,a->word);
	strcat(word,b->word);
	bst_t* tmp = new_node(word,a->freq+b->freq,0);
	tmp->left = a;
	tmp->right = b;
	return tmp;
}

bst_t* delete_2(heap_t* pq){
	if(pq->last_index==1)	return NULL;
	while(1){
		bst_t* a = delete_max(pq);
		bst_t* b = delete_max(pq);
		if(a==NULL || b==NULL){
			if(b==NULL){
				return a;
			}
			return NULL;
		}
		else{
			insert2( pq, combine(a,b) );
		}
	}
	return NULL;
}

void dfs(bst_t* t,int ll[],int n){
	if(t==NULL)	return NULL;

	if(t->yao==1){
		printf("%s: ",t->word);
		for(int i=0;i<n;i++){
			printf("%d",ll[i]);
		}
		printf("\n");
	}


	ll[n] = 0;
	dfs(t->left,ll,n+1);

	ll[n] = 1;
	dfs(t->right,ll,n+1);
}

int main(void) {
	heap_t *mh = NULL;
	int    m, n, i;
	int    command, data;
	int    old_key, new_key;

	scanf("%d",&m);
	mh = init_heap(2*m);
	char word[m+2][20];
	int sq[m+2];
	for(i=0;i<m;i++){
	  	scanf("%s %d",word[i],&sq[i]);
	  	insert(mh,word[i],sq[i]);
	}
  	bst_t* t = delete_2(mh);
  	int ll[m+2];
  	dfs(t,ll,0);
  	return 0;
}
