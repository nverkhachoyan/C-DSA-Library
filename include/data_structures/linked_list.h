#ifndef NK_LINKED_LIST
#define NK_LINKED_LIST

struct NODE {
	void *data;
	struct NODE *next;
};

typedef void (*printFunc)(void*);
struct NODE *linked_list(void *data);
int insert_node(struct NODE *head, void *data);
int print_node(struct NODE *node, printFunc print_node);
int print_list(struct NODE *head, printFunc print_node);

#endif