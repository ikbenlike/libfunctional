typedef struct bt_node_t {
  int value;
  void *data;
  struct bt_node_t *left;
  struct bt_node_t *right;
} bt_node_t;

int bt_insert(bt_node_t *tree, int value, void *data);
bt_node_t *bt_search(bt_node_t *tree, int value);
