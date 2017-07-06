#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/func.h"
#include "../src/hashmap.h"
#include "../src/linked_list.h"
#include "../src/binary_tree.h"

void mul2(void *i){
    *(int*)i *= 2;
}

int greater_than4(void *i){
    if(*(int*)i > 4){
        return 1;
    }
    return 0;
}

void add_voids(void *a, void *b){
    *(int*)a += *(int*)b;
}

either_t *add_test(int a, int b){
    if(a != b){
        int *c = calloc(1, sizeof(int));
        int x = a + b;
        memcpy(c, &x, sizeof(int));
        return either_init(S_RIGHT, (void*)c);
    }
    else {
        return either_init(S_LEFT, strcpy(calloc(7, sizeof(char)), "a == b"));
    }
}

void *wrap_puts(void *data){
    puts((char*)data);
    return data;
}

void *wrap_printf_int(void *data){
    int *i = (int*)data;
    printf("%d\n", *i);
    return data;
}

int main(int argc, char **argv){
    int a[] = {1, 2, 3, 4, 5};
    printf("the average value of a: %f\n", average(a, 5));
    
    int *x[] = {a, a + 1, a + 2, a + 3, a + 4};
    map((void**)x, 5, mul2);
    for(int i = 0; i < 5; i++){
        printf("values from a multiplied by 2: %d\n", *x[i]);
    }

    int *y[5];
    int n = filter((void**)x, (void**)y, 5, greater_than4);
    for(int i = 0; i < n; i++){
        printf("values from a greater than 4: %d\n", *y[i]);
    }

    int red_res = 0;
    reduce((void**)x, (void*)&red_res, 5, add_voids);
    printf("the result of reducing x is: %d\n", red_res);

    either_t *e = add_test(10, 10);
    either(e, wrap_puts, wrap_printf_int);
    e = add_test(10, 14);
    either(e, wrap_puts, wrap_printf_int);

    hashmap_t *hm = hashmap_init(10);
    hashmap_set(hm, "one", a + 4);
    printf("hashmap value of 'one': %d\n", *HASHMAP_GETVAL(hm, "one", int*));

    linked_list_node_t *head = linked_list_construct(10);
    printf("linked list length: %d\n", linked_list_len(head));
    printf("'linked_list_free' exit code: %d\n", linked_list_free(head));

    bt_node_t *tree = calloc(1, sizeof(bt_node_t));
    bt_insert(tree, 5, "Hello!");
    bt_insert(tree, 7, "There!");
    bt_insert(tree, 3, "World!");

    printf("%s\n", BT_GETDATA(tree, 5, char*));
    printf("%s\n", BT_GETDATA(tree, 7, char*));
    printf("%s\n", BT_GETDATA(tree, 3, char*));
}
