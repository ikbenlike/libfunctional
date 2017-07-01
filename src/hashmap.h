#ifndef __HASHMAP_H__
    #define __HASHMAP_H__

    #define HASHMAP_GETVAL(map, name, type) (*(type*)hashmap_get(map, name)->value)

    typedef struct {
        int key;
        char *name;
        void *value;
    } hashmap_element_t;

    typedef struct {
        size_t len;
        size_t cursor;
        hashmap_element_t *list;
    } hashmap_vector_t;

    typedef struct {
        size_t size;
        hashmap_vector_t *map;
    } hashmap_t;

    hashmap_vector_t *hashmap_resize_vector(hashmap_vector_t *hv);
    hashmap_t *hashmap_init(int size);
    int hashmap_free(hashmap_t *hm);
    long int hashmap_hash(hashmap_t *hm, char *inp);
    long int hashmap_standalone_hash(char *inp);
    int hashmap_item_exists(hashmap_t *hm, char *inp);
    int hashmap_set(hashmap_t *hm, char *name, void *value);
    hashmap_element_t *hashmap_get(hashmap_t *hm, char *name);
#endif
