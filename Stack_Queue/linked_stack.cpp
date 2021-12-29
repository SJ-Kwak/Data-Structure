// linked_stack.cpp : Defines the entry point for the console application.

//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct DlistNode {
	element item;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;

typedef struct {
	DlistNode* top;
} LinkedStackType;

void init(LinkedStackType* s, DlistNode* head)
{
	s->top = head;
	head->llink = head;
	head->rlink = head;
}

int is_empty(LinkedStackType* s, DlistNode* head)
{
	return (s->top == head);
}

void push(LinkedStackType* s, element item)
{
	DlistNode* temp = (DlistNode*)malloc(sizeof(DlistNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return;
	}

	else {
		temp->item = item;
		temp->rlink = s->top;
		temp->llink = s->top->llink;
		s->top->llink->rlink = temp;
		s->top->llink = temp;
		s->top = temp;
	}
}

element pop(LinkedStackType* s, DlistNode *head)
{
	if (is_empty(s, head)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		DlistNode* temp = s->top;
		int item = temp->item;
		temp->llink->rlink = temp->rlink;
		temp->rlink->llink = temp->llink;
		s->top = s->top->rlink;
		free(temp);
		return item;
	}
}

element peek(LinkedStackType* s, DlistNode* head)
{
	if (is_empty(s, head)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

void main()
{
	LinkedStackType s;
	DlistNode head;
	init(&s, &head);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s, &head));
	printf("%d\n", pop(&s, &head));
	printf("%d\n", pop(&s, &head));
}