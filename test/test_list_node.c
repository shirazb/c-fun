#include <linked_list/list_node.h>

#include <stdlib.h>

typedef char * string;

GENERATE_LIST_NODE(int)
GENERATE_LIST_NODE(string)
GENERATE_LIST_NODE(float)

#define test_list_node_can_call_new_and_destroy(TYPE, NODE_ONE_ELEM, NODE_TWO_ELEM, ELEM_DESTROYER)\
do { \
    TYPE _val1 = (NODE_ONE_ELEM); \
    TYPE _val2 = (NODE_TWO_ELEM); \
    list_node_elem_destroyer(TYPE) _elem_destroyer = (ELEM_DESTROYER); \
    \
    struct list_node(TYPE) *_node = list_node_new(TYPE)(_val1); \
    _node->next = list_node_new(TYPE)(_val2); \
    \
    list_node_destroy(TYPE)(_node, _elem_destroyer); \
} while(0)

int main(void) {
    // Must have already generated list node for that type at top level.
    test_list_node_can_call_new_and_destroy(int, 5, 10, NULL);
    test_list_node_can_call_new_and_destroy(string, "hello", "why hello there", NULL);
    test_list_node_can_call_new_and_destroy(float, 2.0e4, -3.0f, NULL);
}
