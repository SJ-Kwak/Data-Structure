//Assignment03(3) 2076016 °û¼­Áø
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
	ListNode* tail;
	int length;
}ListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ListType* list) {
	if (list == NULL)
		return;
	list->length = 0;
	list->head = list->tail = NULL;
}

int is_empty(ListType* list) {
	if (list->head == NULL)
		return 1;
	else
		return 0;
}

int get_length(ListType* list) {
	return list->length;
}

ListNode* get_node_at(ListType* list, int pos) {
	int i;
	ListNode* tmp_node = list->head;
	if (pos < 0)
		return NULL;
	for (i = 0; i < pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;
}

element get_entry(ListType* list, int pos) {
	ListNode* p;
	if (pos >= list->length)
		error("Position error");
	p = get_node_at(list, pos);
	return p->data;
}

void display(ListType* list) {
	int i;
	ListNode* node = list->head;
	printf("{ ");
	for (i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}
	printf("}\n");
}

int is_in_list(ListType* list, element item) {
	ListNode* p;
	p = list->head;
	while ((p != NULL)) {
		if (p->data == item)
			break;
		p = p->link;
	}
	if (p == NULL)
		return FALSE;
	else
		return TRUE;
}

void insert_node(ListType* list, ListNode* before, ListNode* new_node) {
	if (is_empty(list)) {
		new_node->link = NULL;
		list->head = new_node;
		list->tail = new_node;
	}
	else {
		if (before == NULL) {
			new_node->link = list->head;
			list->head = new_node;
		}
		else {
			new_node->link = before->link;
			before->link = new_node;
		}
	}
}

void add(ListType* list, int pos, element data) {
	ListNode* p;
	if ((pos >= 0) && (pos <= list->length)) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL)
			error("Memory allocation error");
		else {
			node->data = data;
			p = get_node_at(list, pos - 1);
			insert_node(&(list->head), p, node);
			list->length++;
		}
	}
}

void add_first(ListType* list, int value) {
	add(list, 0, value);
}

void add_last(ListType* list, int value) {
	add(list, get_length(list), value);
}

void remove_node(ListType* list, ListNode* before, ListNode* removed) {
	if (is_empty(list)) {
		printf("The list is blank.\n");
	}
	else {
		if (before == NULL)
			list->head = (list->head)->link;
		else {
			before->link = removed->link;
			free(removed);
		}
	}
}

void delete(ListType* list, int pos) {
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		ListNode* before = get_node_at(list, pos - 1);
		ListNode* removed = get_node_at(list, pos);
		remove_node(list, before, removed);
		list->length--;
	}
}

void delete_first(ListType* list) {
	delete(list, 0);
}

void delete_last(ListType* list) {
	delete(list, get_length(list) - 1);
}

void main() {
	ListType list1;
	init(&list1);
	add_first(&list1, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);
	add(&list1, 2, 70);
	display(&list1);

	delete(&list1, 2);
	delete_first(&list1);
	delete_last(&list1);
	display(&list1);

	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "TRUE" : "FALSE");
	printf("%d\n", get_entry(&list1, 0));
}
