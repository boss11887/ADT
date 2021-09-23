#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
  int *data;
  int last_index;
} heap_t;

void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
int *init_heap(int m){
    heap_t* pq = (heap_t *)malloc(sizeof (heap_t));
	pq->data = (int *)malloc(sizeof(int) * (m+5));
	pq->last_index = 1;
	return pq;
}

void insert(heap_t *pq,int data){
    int now = pq->last_index;
    pq->data[now]=data;
    pq->last_index++;
    while(now > 1){
        if(pq->data[now] > pq->data[now/2]){
            int chua= pq->data[now/2];
            pq->data[now/2] = pq->data[now];
            pq->data[now]=chua;
        }
        now/=2;
    }
}

void delete_max(heap_t *pq){
    //point max
    int l = pq->last_index-1;
    if(l==0)
        return;
    int val = pq->data[l];

    //delmax
    pq->data[l]=0;
    pq->last_index--;

    int now=1;
    pq->data[now]=val;

    while(now*2 < l){
        if(pq->data[now] < pq->data[now*2] || pq->data[now] < pq->data[now*2+1]){
            if(pq->data[now*2] > pq->data[now*2+1]){
                //left
                swap(&pq->data[now*2],&pq->data[now]);
                now*=2;

            }else if(pq->data[now*2] < pq->data[now*2+1]){
                //right
                swap(&pq->data[now*2+1],&pq->data[now]);
                now=now*2+1;
            }
        }else{
            break;
        }
    }
}
int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int dfs(heap_t *pq,int pos,int want){
    if(pos > pq->last_index){
        return 0;
    }
    if(pq->data[pos]==want)
        return pos;
    return max(dfs(pq,pos*2,want),dfs(pq,pos*2+1,want));
}
void update_key(heap_t *pq,int old_key,int new_key){
    int poswant=dfs(pq,1,old_key);
    int now=poswant;
    pq->data[poswant]=new_key;
    //down
    while(now > 1){
        if(pq->data[now] > pq->data[now/2]){
            int chua= pq->data[now/2];
            pq->data[now/2] = pq->data[now];
            pq->data[now]=chua;
        }
        now/=2;
    }
    now=poswant;
    while(now*2 < pq->last_index){
        if(pq->data[now] < pq->data[now*2] || pq->data[now] < pq->data[now*2+1]){
            if(pq->data[now*2] > pq->data[now*2+1]){
                //left
                swap(&pq->data[now*2],&pq->data[now]);
                now*=2;

            }else if(pq->data[now*2] < pq->data[now*2+1]){
                //right
                swap(&pq->data[now*2+1],&pq->data[now]);
                now=now*2+1;
            }
        }else{
            break;
        }
    }
}
int find_max(heap_t *pq){
    if(pq->last_index == 1)
        return -1;
    return pq->data[1];
}

void bfs(heap_t *pq){
    int last = pq->last_index;
    for(int a=1;a<last;a++){
        printf("%d ",pq->data[a]);
    }
    printf("\n");
}
int main(void) {
  heap_t *max_heap = NULL;
  int    m, n, i;
  int    command, data;
  int    old_key, new_key;

  scanf("%d %d", &m, &n);
  max_heap = init_heap(m);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
      case 1:
        scanf("%d", &data);
        insert(max_heap, data);
        break;
      case 2:
        delete_max(max_heap);
        break;
      case 3:
        printf("%d\n", find_max(max_heap));
        break;
      case 4:
        scanf("%d %d", &old_key, &new_key);
        update_key(max_heap, old_key,new_key);
        break;
      case 5:
        bfs(max_heap);
        break;
    }
  }
  return 0;
}

/*
1. priorityQueue
>>> test case #1
10 8
1 2
1 3
1 5
1 6
5
1 1
1 7
5
>>> test case #2
10 11
1 2
3
1 3
1 4
1 5
1 6
3
1 1
3
1 7
3
>>> test case #3
10 11
1 2
5
1 3
1 4
1 5
1 6
3
2
5
1 7
5
>>> test case #4
5 13
1 2
1 3
1 4
5
2
5
2
5
2
5
2
5
3
>>> test case #5
5 10
1 2
1 3
1 4
5
4 2 5
5
4 4 1
5
4 5 10
5
>>> test case #6
5 13
1 82
1 79
1 66
1 78
5
2
3
1 93
2
1 69
5
1 99
3
>>> test case #7
5 11
3
1 11
1 3
1 90
1 43
3
2
2
5
4 3 20
3
----------
*/
