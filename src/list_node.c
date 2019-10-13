#include <linked_list.h>

#include <stdlib.h>

struct list_node *
list_node_init(struct list_node *node, int x) {
    node->x = x;
    node->next = NULL;

    return node;
}

struct list_node *
list_node_new(int x) {
    struct list_node *node = malloc(sizeof(struct list_node));
    if (!node) {
        return node;
    }

    node->x = x;
    node->next = NULL;

    return node;
}

void
list_node_deinit(struct list_node *node) {
    list_node_destroy(node->next);
}

void
list_node_destroy(struct list_node *node) {
    list_node_deinit(node);
    free(node);
}
