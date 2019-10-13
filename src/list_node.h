#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct list_node {
    int x;
    struct list_node *next;
};

struct list_node *
list_node_init(struct list_node *node, int x);

struct list_node *
list_node_new(int x);

void
list_node_deinit(struct list_node *node);

void
list_node_destroy(struct list_node *node);

#endif
