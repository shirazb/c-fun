#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H


#include <stdlib.h>

#define list_node(TYPE) list_node_##TYPE
#define list_node_elem_destroyer(TYPE) list_node_elem_destroyer_##TYPE
#define list_node_init(TYPE) list_node_init_##TYPE
#define list_node_new(TYPE) list_node_new_##TYPE
#define list_node_deinit(TYPE) list_node_deinit_##TYPE
#define list_node_destroy(TYPE) list_node_destroy_##TYPE
/**
 * Generates declarations and definitions of list_node struct for type `TYPE`.
 * Example Usage (for ints):
 * 
 * GENERATE_LIST_NODE(int)
 * 
 * void f(void) {
 *     // Initialiser function
 *     struct list_node(int) x;
 *     list_node_init(int)(x, 10);
 *     
 *     // Can also use return value if more convenient
 *     struct list_node(int) y;
 *     y = list_node_init(int)(y, 20);
 * 
 *     // New function that gives pointer to heap
 *     struct list_node(int) *z = list_node_new(int)(30);
 *     
 *     x->next = &y;
 *     y->next = z;
 * 
 *    // Can deinit an individual node, optionally passing in destroyer of
 *    // element type
 *    list_node_deinit(z, NULL);
 *   
 *    // Can destroy a node: will destroy `next`, deinit this node using the
 *    // given element type destroyer, then free the memory of this node
 *    list_node_destroy(x, NULL);
 * }
 */
#define GENERATE_LIST_NODE(TYPE) \
/* struct list_node */ \
struct list_node(TYPE) { \
    TYPE elem; \
    struct list_node(TYPE) *next; \
}; \
\
/* Prototypes */ \
/* list_node_elem_destroyer(TYPE) returns void, takes TYPE* */ \
typedef void(*list_node_elem_destroyer(TYPE))(TYPE *); \
\
struct list_node(TYPE) * \
list_node_init(TYPE)(struct list_node(TYPE) *node, TYPE elem); \
\
struct list_node(TYPE) * \
list_node_new(TYPE)(TYPE elem); \
\
void \
list_node_deinit(TYPE)( \
        struct list_node(TYPE) *node, \
        list_node_elem_destroyer(TYPE) elem_destroyer \
); \
\
void \
list_node_destroy(TYPE)( \
        struct list_node(TYPE) *node, \
        list_node_elem_destroyer(TYPE) elem_destroyer \
); \
\
/* Definitions */ \
struct list_node(TYPE) * \
list_node_init(TYPE)(struct list_node(TYPE) *node, TYPE elem) { \
    node->elem = elem; \
    node->next = NULL; \
    \
    return node; \
} \
\
struct list_node(TYPE) * \
list_node_new(TYPE)(TYPE elem) { \
    struct list_node(TYPE) *node = (struct list_node(TYPE) *) malloc(sizeof(struct list_node(TYPE))); \
    if (!node) { \
        return node; \
    } \
    \
    return list_node_init(TYPE)(node, elem); \
} \
\
void \
list_node_deinit(TYPE)( \
        struct list_node(TYPE) *node, \
        list_node_elem_destroyer(TYPE) elem_destroyer \
) { \
    if (elem_destroyer) { \
        elem_destroyer(&node->elem); \
    } \
    node->next = NULL; \
} \
\
void \
list_node_destroy(TYPE)( \
        struct list_node(TYPE) *node, \
        list_node_elem_destroyer(TYPE) elem_destroyer \
) { \
    if (node->next) { \
        list_node_destroy(TYPE)(node->next, elem_destroyer); \
    } \
    list_node_deinit(TYPE)(node, elem_destroyer); \
    free(node); \
}


#endif
