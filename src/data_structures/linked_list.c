#include "data_structures/linked_list.h"

#include <stdio.h>
#include <stdlib.h>

struct NODE *linked_list(void *data) {
	struct NODE *head = (struct NODE*)malloc(sizeof(struct NODE));
	if (head == NULL) {
		fprintf(stderr, "Memory allocation failure.\n");
		return NULL;
	}

	head->data = data;
	head->next = NULL;
	return head;
}

int insert_node(struct NODE *head, void *data) {
	if (head == NULL) {
		fprintf(stderr, "Linked List uninitialized.\n");
		return 1;
	}

	struct NODE *node = (struct NODE*)malloc(sizeof(struct NODE));
	if (node == NULL) {
		fprintf(stderr, "Memory allocation failure.\n");
		return -1;
	}
	node->data = data;
	node->next = NULL;

	while (head->next != NULL) {
		head = head->next;
	}

	head->next = node; 
	return 0;
}

int print_list(struct NODE *head, printFunc print_node) {
	if (head == NULL) {
		fprintf(stderr, "Linked List uninitialized.\n");
		return 1;
	}

	while(head != NULL) {
		print_node(head->data);
		head = head->next;
	}

	return 0;
}



