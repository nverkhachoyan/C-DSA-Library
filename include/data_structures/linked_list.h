#ifndef NK_LINKED_LIST
#define NK_LINKED_LIST

typedef enum {
    SUCCESS = 0,
    NULL_DATA_ERROR = 1,
    DATA_NOT_FOUND = 2,
    ALLOCATION_ERROR = -1
} ERROR_CODE;

struct NODE {
	void *data;
	struct NODE *next;
};

typedef void (*print_func)(void*);
struct NODE *_create_node(void *data);
ERROR_CODE insert_node(struct NODE **head, void *data);
ERROR_CODE remove_node(struct NODE **head, void *data);
ERROR_CODE print_node(struct NODE *node, print_func print_data);
ERROR_CODE print_list(struct NODE *head, print_func print_data);

#endif