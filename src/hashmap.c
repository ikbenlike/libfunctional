#include <string.h>
#include <stdlib.h>
#include "hashmap.h"

/*typedef struct {
    int key;
    char *name;
    void *value;
} hashmap_element_t;

typedef struct {
    size_t len;
    hashmap_element_t *list;
} hashmap_vector_t;

typedef struct {
    size_t size;
    hashmap_vector_t *map;
} hashmap_t;*/

hashmap_vector_t *hashmap_resize_vector(hashmap_vector_t *hv){
    hv->len *= 0.75;
    hashmap_element_t *a = realloc(hv->list, hv->len * sizeof(hashmap_element_t));
    if(a != NULL){
        hv->list = a;
    }
    else {
        return NULL;
    }
    return hv;
}

hashmap_t *hashmap_init(int size){
    hashmap_t *hm = calloc(1, sizeof(hashmap_t));
    hm->map = calloc(size, sizeof(hashmap_vector_t));
    hm->size = size;
    for(int i = 0; i < hm->size; i++){
        hm->map[i].len = 1;
        hm->map[i].list = calloc(1, sizeof(hashmap_element_t));
    }
    return hm;
}

int hashmap_free(hashmap_t *hm){
    for(int i = 0; i < hm->size; i++){
        free(hm->map[i].list);
    }
    free(hm->map);
    free(hm);
    return 0;
}

long int hashmap_hash(hashmap_t *hm, char *inp){
    int output = 0;
    int i = 0;
    int l = strlen(inp);
    while((i + 1) <= l){
        output = output*17 + inp[i++];
    }
    return output % hm->size;
}

long int hashmap_standalone_hash(char *inp){
    int output = 0;
    int i = 0;
    int l = strlen(inp);
    while((i + 1) <= l){
        output = output*17 + inp[i++];
    }
    return output;
}

int hashmap_item_exists(hashmap_t *hm, char *inp){
    int c = hashmap_standalone_hash(inp);
    int n = c % hm->size;
    hashmap_vector_t a = hm->map[n];
    for(int i = 0; i < a.len; i++){
        if(a.list[i].key = c){
            return i;
        }
    }
    return -1;
}

int hashmap_set(hashmap_t *hm, char *name, void *value){
    long int c = hashmap_standalone_hash(name);
    int n = c % hm->size;
    hm->map[n].list[0].key = c;
    hm->map[n].list[0].name = name;
    hm->map[n].list[0].value = value;
    return 0;
}

hashmap_element_t *hashmap_get(hashmap_t *hm, char *name){
    if(hashmap_item_exists(hm, name) != -1){
        hashmap_vector_t v = hm->map[hashmap_hash(hm, name)];
        for(int i = 0; i < v.len; i++){
            if(!strcmp(v.list[i].name, name)){
                return &v.list[i];
            }
        }
    }
    return NULL;
}
