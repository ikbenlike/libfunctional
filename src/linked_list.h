typedef struct linked_list_node_t {
    struct linked_list_node_t *next;
    void *value;
} linked_list_node_t;

linked_list_node_t *linked_list_construct(size_t len);
size_t linked_list_len(linked_list_node_t *node);
int linked_list_free(linked_list_node_t *node);
