#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"



int bt_insert(bt_node_t *tree, int value, void *data){
    if(tree == NULL){
        return 1;
    }
    bt_node_t *head = tree;
    while(head->value != 0){
        if(value < head->value){
            if(head->left != NULL){
                head = head->left;
                head->value = value;
                head->data = data;
            }
            else {
                head->left = calloc(1, sizeof(bt_node_t));
                head = head->left;
                head->value = value;
                head->data = data;
            }
        }
        else if(value > head->value){
            if(head->right != NULL){
                head = head->right;
                head->value = value;
                head->data = data;
            }
            else {
                head->right = calloc(1, sizeof(bt_node_t));
                head = head->right;
                head->value = value;
                head->data = data;
            }
        }
        else if(value == head->value){
            head->data = data;
            return 0;
        }
    }
    if(head->value == 0){
        head->value = value;
        head->data = data;
    }
    return 1;
}

bt_node_t *bt_search(bt_node_t *tree, int value){
    if(tree == NULL){
        return NULL;
    }
    bt_node_t *head = tree;
    while(1){
        if(value < head->value){
            head = head->left;
            if(head == NULL){
                return NULL;
            }
            continue;
        }
        else if(value > head->value){
            head = head->right;
            if(head == NULL){
                return NULL;
            }
            continue;
        }
        else if(value == head->value){
            return head;
        }
    }
    return NULL;
}
