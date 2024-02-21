#include <stdio.h>
#include <stdlib.h>

#include "data_structures/linked_list.h"

struct POS {
	int x;
	int y;
};

void print_pos(void *data) {
	struct POS *pos = (struct POS*)data;
	printf("POS X: %d, Y: %d\n", pos->x, pos->y);
}

struct POS *create_pos(int x, int y) {
	struct POS *pos = (struct POS*)malloc(sizeof(struct POS));

    if (pos == NULL) {
		fprintf(stderr, "Allocation failure.\n");
        return NULL;
    }

	pos->x = x;
	pos->y = y;
	return pos;
}

int main(int argc, char *argv[]) {
	struct NODE* head = NULL;

	struct POS *pos = create_pos(5, 6);

	insert_node(&head, create_pos(12, 43));
	insert_node(&head, create_pos(15, 98));
	insert_node(&head, create_pos(15, 98));
	insert_node(&head, create_pos(15, 98));
	insert_node(&head, pos);
	insert_node(&head, create_pos(15, 98));


	remove_node(&head, pos);

	print_list(head, print_pos);

	return 0;
}



