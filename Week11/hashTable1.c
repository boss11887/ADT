#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef struct item {
  char   *text;
  struct item *next;
} item_t;

typedef struct hash {
  item_t **table;
  int    size;
  int    hash_key;
} hash_t;

hash_t *init_hashtable( int m , int hkey){
    hash_t *list=(hash_t*)malloc(sizeof(hash_t));
    list->size =m;
    list->hash_key =hkey;
    list->table = (item_t**)malloc(sizeof(item_t*)*m);
    return list;
}

int lentxt(char txt[105]){
    int yao=0;
    for(int a=0;txt[a] != '\0';a++){
        yao++;
    }
    return yao;
}


int sai(char txt[105],hash_t *ht,int pos){
    int yao=lentxt(txt);
    item_t *new_node=(item_t*)malloc(sizeof(item_t));
    new_node->text = (char*)malloc(sizeof(char)*yao);
    strcpy(new_node->text,txt);
    new_node->next = NULL;

    if(ht->table[pos]==NULL)
        return new_node;
    new_node->next=ht->table[pos];
    return new_node;
}

int hash(hash_t *ht,char txt[105]){
    int yao=lentxt(txt);
    unsigned cur=0;
    for(int a=0;a<yao;a++){
        cur*=ht->hash_key;
        cur+=txt[a];
    }
    return cur%ht->size;
}
void insert(hash_t *ht,char txt[105]){
    int cur=hash(ht,txt);
    //printf("(%d)",cur);
    ht->table[cur] = sai(txt,ht,cur);
    //printf("..--(%s)--..",ht->table[cur]->text);
}

int search(hash_t *ht,char txt[105]){
    int cur=hash(ht,txt);
    //printf("(%d)",cur);

    item_t *tmp=ht->table[cur];

    while(tmp != NULL){
        //printf("===%s %s===",tmp->text,txt);
        if(!strcmp(tmp->text,txt)){
            //printf("Jue");
            return cur;
        }
        tmp=tmp->next;
    }
    return -1;
}
int main(void) {
  hash_t *hashtable = NULL;
  char   *text = NULL;
  int    m, n, i, hash_key;
  int    command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);

  for (i=0; i<n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
      case 1:
        insert(hashtable, text);
        break;
      case 2:
        printf("%d\n", search(hashtable, text));
        break;
      }
  }
  return 0;
}
/*
>>> test case #1
13 10 19
1 qwert
1 asdf
1 zklwo
1 a
2 qwert
2 qwerty
2 a
2 asdf
2 omg
2 abcd
>>> test case #2
211 20 93
1 abcd
1 abdc
1 afnc
1 oog
1 ozg
1 obg
1 obp
1 fjdlo
1 auvun
1 adzlr
2 abcd
2 abdc
2 afnc
2 oog
2 ozg
2 obg
2 obp
2 fjdlo
2 auvun
2 adzlr
>>> test case #3
31 14 19
1 mhewrv
1 rkrfni
1 wtabik
1 ibpffi
1 hwrthu
1 mcpsnn
1 xmyprx
2 mhewrv
2 rkrfni
2 wtabik
2 ibpffi
2 hwrthu
2 mcpsnn
2 xmyprx
*/
