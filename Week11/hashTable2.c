#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
  item_t **table;
  int    size;
  int    hash_key;
} hash_t;

// Write your code here
hash_t *init_hashtable( int m , int hkey){
    hash_t *list=(hash_t*)malloc(sizeof(hash_t));
    list->size =m;
    list->hash_key =hkey;
    list->table = (item_t**)malloc(sizeof(item_t*)*(m+5));
    return list;
}

int lentxt(char txt[105]){
    int yao=0;
    for(int a=0;txt[a] != '\0';a++){
        yao++;
    }
    return yao;
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
    unsigned cur=hash(ht,txt);
    int yao = lentxt(txt);
    //printf("st = (%d) %s\n",cur,ht->table[cur]);
    for(int i=0;i<ht->size;i++){
        unsigned now = ((cur+((i+i*i)/2)) % ht->size);
        //printf("now = %d\n ",(i+i^2)/2);
        if (ht->table[now] == NULL){
            //printf("%d",now);
            ht->table[now]=(item_t*)malloc(sizeof(item_t)*TEXTSIZE);
            //printf("yo");
            strcpy(ht->table[now],txt);
            break;
        }
    }
    //printf("..--(%s)--..",ht->table);
}

int search(hash_t *ht,char txt[105]){
    unsigned cur=hash(ht,txt);
    //printf("(%d)",cur);

    for(int i=0;i<ht->size;i++){
        int now = ((cur+((i+i*i)/2)) % ht->size);
        //printf("now = %d %d",now,ht->size);
        if(ht->table[now]==NULL)
            break;
        //printf(".....%s %s %d...\n",ht->table[now],txt,now);
        if (!strcmp(ht->table[now],txt)){
            return now;
        }
    }
    return -1;
}


int main(void) {
  hash_t *hashtable = NULL;
  char   *text = NULL;
  int    m, n, i, hash_key;
  int    command;

  //freopen("out.txt","w",stdout);

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);

  for(int i=0;i<hashtable->size;i++){
      hashtable->table[i]=NULL;
  }
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
      //printf("finish\n");
  }
  return 0;
}
/*
2. hashTable2
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
----------
test 8
251 176 53
1 look
1 at
1 this
1 stuff
1 isnt
1 it
1 neat
1 wouldnt
1 you
1 think
1 my
1 collection
1 complete
1 i
1 am
1 the
1 girl
1 who
1 has
1 everything
1 trove
1 treasures
1 untold
1 how
1 many
1 wonders
1 can
1 one
1 cavern
1 hold
1 looking
1 around
1 here
1 would
1 sure
1 she
1 got
1 have
1 gadgets
1 and
1 gizmos
1 aplenty
1 whozits
1 whatzits
1 galore
1 want
1 thingamabobs
1 twenty
1 but
1 cares
1 no
1 big
1 deal
1 more
1 to
1 be
1 where
1 people
1 are
1 see
1 them
1 dancing
1 walking
1 on
1 those
1 what
1 call
1 oh
1 feet
1 flipping
1 your
1 fins
1 dont
1 get
1 too
1 far
1 legs
1 required
1 for
1 jumping
1 strolling
1 along
1 down
1 a
1 that
1 word
1 again
1 street
1 up
1 they
1 walk
1 run
1 stay
1 all
1 day
1 in
1 sun
1 wandering
1 free
1 wish
1 could
1 part
1 of
1 world
1 give
1 if
1 live
1 outta
1 these
1 waters
1 pay
1 spend
1 warm
1 sand
1 betcha
1 land
1 understand
1 bet
1 reprimand
1 their
1 daughters
1 bright
1 young
1 women
1 sick
1 swimming
1 ready
1 stand
1 know
1 ask
1 questions
1 some
1 answers
1 fire
1 why
1 does
1 burn
1 when
1 turn
1 love
1 explore
1 shore
1 above
1 out
1 sea
2 i
2 you
2 we
2 they
2 he
2 she
2 it
2 is
2 am
2 are
2 was
2 were
2 be
2 been
2 can
2 could
2 may
2 might
2 will
2 would
2 shall
2 should
2 rather
2 what
2 when
2 where
2 why
2 who
2 whose
2 whom
2 how
*/
