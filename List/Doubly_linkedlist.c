//Assignment3(1) 2076016 °û¼­Áø
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

void init(DlistNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void display(DlistNode* phead) {
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<--- | %d | --->\n", p->data);
	}
	printf("\n");
}

void dinsert_node(DlistNode* before, DlistNode* new_node) {
	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

void main() {
	DlistNode* head_node = (DlistNode*)malloc(sizeof(DlistNode));
	DlistNode* p[10];

	init(head_node);
	//building list
	for (int i = 0; i < 5; i++) {
		p[i] = (DlistNode*)malloc(sizeof(DlistNode));
		p[i]->data = i;
		dinsert_node(head_node, p[i]);
	}

	//inserting new node in the beginning
	DlistNode* insertfirst = (DlistNode*)malloc(sizeof(DlistNode));
	insertfirst->data = 10;
	dinsert_node(head_node, insertfirst);

	//inserting new node at the end
	DlistNode* insertlast = (DlistNode*)malloc(sizeof(DlistNode));
	insertlast->data = 20;
	dinsert_node(head_node->llink, insertlast);

	display(head_node);

	free(head_node);
	free(insertfirst);
	free(insertlast);
}