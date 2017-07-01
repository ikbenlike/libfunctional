#include <stdlib.h>

typedef struct bt_node_t {
    struct bt_node_t *left;
    struct bt_node_t *right;
    int value;
} bt_node_t;

void bt_insert(bt_node_t *tree, int value){
    if(!tree->value){
        tree->value = value;
    }
    else {
        if(value < tree->value){
            if(tree->left != NULL){
                bt_insert(tree->left, value);
            }
            else {
                tree->left = calloc(1, sizeof(bt_node_t));
                tree->value = value;
            }
        }
        else{
            if(value >= tree->value){
                if(tree->right != NULL){
                    bt_insert(tree->right, value);
                }
                else {
                    tree->right = calloc(1, sizeof(bt_node_t));
                    tree->right->value = value;
                }
            }
        }
    }
}

bt_node_t *bt_search(bt_node_t *tree, int value){
    if(tree != NULL){    
        if(tree->value == value){
            return tree;
        }
        else if(tree->value < value){
            return bt_search(tree->left, value);
        }
        else {
            return bt_search(tree->right, value);
        }
    }
    return NULL;
}
