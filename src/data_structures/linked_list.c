#include "data_structures/linked_list.h"

#include <stdio.h>
#include <stdlib.h>

struct NODE *_create_node(void *data) {
	struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
	if (new_node == NULL) {
		fprintf(stderr, "Memory allocation failure.\n");
		return NULL;
	}

	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

ERROR_CODE insert_node(struct NODE **head, void *data) {
	struct NODE *new_node = _create_node(data);
	if (new_node == NULL) {
		fprintf(stderr, "Memory allocation failure.\n");
		return ALLOCATION_ERROR;
	}

	if (*head == NULL) {
		*head = new_node;
		return SUCCESS;
	}

	struct NODE *curr_node = *head;
	while (curr_node->next != NULL) {
		curr_node = curr_node->next;
	}

	curr_node->next = new_node; 
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

ERROR_CODE print_list(struct NODE *head, print_func print_data) {
	if (head == NULL) {
		fprintf(stderr, "Linked List uninitialized.\n");
		return NULL_DATA_ERROR;
	}

	while(head != NULL) {
		print_data(head->data);
		head = head->next;
	}

	return SUCCESS;
}

ERROR_CODE print_node(struct NODE *node, print_func print_data) {
	if (node == NULL) {
		fprintf(stderr, "Node uninitialized.\n");
		return NULL_DATA_ERROR;
	}

	print_data(node->data);
	return SUCCESS;
}



