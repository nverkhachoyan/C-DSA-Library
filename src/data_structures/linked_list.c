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


ERROR_CODE insert_node(struct NODE *head, void *data) {
	if (head == NULL) {
		fprintf(stderr, "Linked List uninitialized.\n");
		return NULL_DATA_ERROR;
	}

	struct NODE *node = (struct NODE*)malloc(sizeof(struct NODE));
	if (node == NULL) {
		fprintf(stderr, "Memory allocation failure.\n");
		return ALLOCATION_ERROR;
	}
	node->data = data;
	node->next = NULL;

	while (head->next != NULL) {
		head = head->next;
	}

	head->next = node; 
	return SUCCESS;
}

ERROR_CODE remove_node(struct NODE **head, void *data) {
	if (head == NULL || *head == NULL) {
		fprintf(stderr, "NULL head provided to remove_node.\n");
		return NULL_DATA_ERROR;
	}

	struct NODE *curr = *head;
	struct NODE *prev = NULL;

	while(curr != NULL && curr->data != data) {
		prev = curr;
		curr = curr->next;
	}

	// Data not found
	if (curr == NULL) {
        return DATA_NOT_FOUND;
    }

	// Data found, remove and free
	if (prev == NULL) {
		*head = curr->next;
	} else {
        prev->next = curr->next;
    }

	free(curr);
	return SUCCESS;
}

ERROR_CODE print_list(struct NODE *head, printFunc print_node) {
	if (head == NULL) {
		fprintf(stderr, "Linked List uninitialized.\n");
		return NULL_DATA_ERROR;
	}

	while(head != NULL) {
		print_node(head->data);
		head = head->next;
	}

	return SUCCESS;
}

ERROR_CODE print_node(struct NODE *node, printFunc print_node) {
	if (node == NULL) {
		fprintf(stderr, "Node uninitialized.\n");
		return NULL_DATA_ERROR;
	}

	print_node(node->data);
	return SUCCESS;
}



