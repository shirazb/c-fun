#include <list_node.h>

void test_list_node_blank(void) {
    struct list_node *node = list_node_new(5);
    node->next = list_node_new(10);

    list_node_destroy(node);
}
