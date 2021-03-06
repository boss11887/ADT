
#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  int mem_addr;
} cell_t;

typedef struct hash {
  cell_t *table;
  int    cache_size;
} hash_t;

typedef hash_t cache_t;
typedef int    memory_t;

memory_t *init_memory(int size) {
  memory_t *memory = (memory_t *)malloc(sizeof(memory_t)*size);
  int      i = 0;

  // Randomly assign integers to memory
  for (i=0; i<size; i++)for (i=0; i<size; i++)
     memory[i] = rand();
  return memory;
}

// Write your code here
cache_t *init_cache(int size){
    cache_t *cc = (cache_t *)malloc(sizeof(cache_t));
    cc->table =(cell_t*)malloc(sizeof(cell_t)*size);
    cc->cache_size = size;
    for (int i=0; i<size; i++){
        cc->table[i].mem_addr=-1;
        cc->table[i].data = 0;
    }
    return cc;
}
void get_data(int addr,memory_t *memory,cache_t *cache){
     int cpos=addr%cache->cache_size;
     int mem_val=memory[addr];
     int ca_addr=cache->table[cpos].mem_addr;
     int ca_val=cache->table[cpos].data;
     if(ca_addr == -1){
        printf("Load from memory\n");
        cache->table[cpos].mem_addr=addr;
        cache->table[cpos].data=mem_val;
     }else if(ca_addr != -1 && (mem_val != ca_val)){
        printf("Index: %d is used\n",cpos);
        printf("Load from memory\n");
        cache->table[cpos].mem_addr=addr;
        cache->table[cpos].data=mem_val;
     }else if(mem_val == ca_val){
        printf("Address %d is loaded\n",addr);
     }
     printf("Data: %d\n",mem_val);

}

int main(void) {
  memory_t *memory = NULL;
  cache_t  *cache = NULL;
  int memory_size, cache_size;
  int i, n, addr;

  scanf("%d %d %d", &memory_size, &cache_size, &n);
  memory = init_memory(memory_size);
  cache = init_cache(cache_size);

  for (i=0; i<n; i++) {
    printf("Load address: ");
    scanf("%d", &addr);
    get_data(addr, memory, cache);
  }
  return 0;
}
