//Assignment3(2) 2076016 °û¼­Áø
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int length;
	ListNode* head;
	ListNode* tail;
}ListType;

void init(ListType* list) {//list: pointer to point the header of the linked list
	list->length = 0;
	list->head = list->tail = NULL;
}

void insert_last(ListType* list, element data) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));

	new_node->data = data;
	new_node->link = NULL;//tail node linked with NULL

	if (list->tail == NULL) {
		list->head = list->tail = new_node;
	}
	else {
		list->tail->link = new_node;
		list->tail = new_node;
	}
	list->length++;

}

void merge_list(ListType* list1, ListType* list2, ListType* list3) {
	ListNode* a = list1->head;
	ListNode* b = list2->head;
	while (a && b) {//a,b both not null
		if (a->data > b->data) {
			insert_last(list3, b->data);
			b = b->link;
		}
		else {
			insert_last(list3, a->data);
			a = a->link;
		}
	}
	for (; a != NULL; a = a->link) {
		insert_last(list3, a->data);
	}
	for (; b != NULL; b = b->link) {
		insert_last(list3, b->data);
	}
}

void display(ListType* list) {
	ListNode* p = list->head;
	printf("{ ");
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("}\n");
}

void main() {
	ListType* A = (ListType*)malloc(sizeof(ListType));
	ListType* B = (ListType*)malloc(sizeof(ListType));
	ListType* C = (ListType*)malloc(sizeof(ListType));

	init(A), init(B), init(C);

	int a[] = { 1,2,5,10,15,20,25 };
	int b[] = { 3,7,8,15,18,30 };

	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {//sizeof(int): 4 byte
		insert_last(A, a[i]);
	}

	for (int i = 0; i < sizeof(b) / sizeof(int); i++) {
		insert_last(B, b[i]);
	}

	printf("A = ");
	display(A);
	printf("B = ");
	display(B);

	merge_list(A, B, C);
	printf("C = ");
	display(C);

	free(A), free(B), free(C);
}