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


int main(int argc, char *argv[]) {

	struct POS *pos = (struct POS*)malloc(sizeof(struct POS));
	pos->x = 50;
	pos->y = 55;

	struct NODE* head = linked_list(pos);

	struct POS *new_pos = (struct POS*)malloc(sizeof(struct POS));
	new_pos->x = 67;
	new_pos->y = 93;

	insert_node(head, new_pos);

	print_node(head, print_pos);

	return 0;
}



