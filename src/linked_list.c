#include <stdlib.h>
#include "linked_list.h"

linked_list_node_t *linked_list_construct(size_t len){
    linked_list_node_t *head = calloc(1, sizeof(linked_list_node_t));
    linked_list_node_t *next = calloc(1, sizeof(linked_list_node_t));
    head->next = next;
    for(size_t i = 0; i + 1 < len; i++){
        next->next = calloc(1, sizeof(linked_list_node_t));
        next = next->next;
    }
    next->next = NULL;
    return head;
}

int linked_list_free(linked_list_node_t *node){
    size_t len = linked_list_len(node);
    linked_list_node_t *head = node;
    linked_list_node_t *next = head;
    while(len - 1 > 0){
        for(size_t i = 0; i + 1 < len; i++){
            next = next->next;
        }
        free(next);
        next = head;
        len -= 1;
    }
    free(head);
    return 0;
}

size_t linked_list_len(linked_list_node_t *node){
    linked_list_node_t *head = node;
    size_t i;
    for(i = 0; head->next != NULL; i++){
        head = head->next;
    }
    return i;
}
