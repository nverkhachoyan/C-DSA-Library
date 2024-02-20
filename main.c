#include <stdio.h>
#include <stdlib.h>

struct NODE {
	void *value;
	struct NODE *next;
};

struct POS {
	int x;
	int y;
};

struct NODE *linked_list() {
	struct NODE *head = (struct NODE*)malloc(sizeof(struct NODE));
	if (head == NULL) {
		fprintf(stderr, "Memory allocation failure.\n");
		return NULL;
	}

	head->value = NULL;
	head->next = NULL;
	return head;
}

int main(int argc, char *argv[]) {
	struct NODE* head = linked_list();

	int *number = (int *)malloc(sizeof(int));
	*number = 5;
	head->value = number;

	printf("Value: %d", *((int*)head->value));

	printf("Hey mate.\n");

	return 0;
}



