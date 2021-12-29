//2076016 °û¼­Áø

#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

//Initialization
void init(HeapType* h) {
	h->heap_size = 0;
}

//Insertion
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	//process comparing with the parent node as it traverses the tree
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = item;	//insert new node
}

//decrease the element ith value to 'key'
void decrease_key_min_heap(HeapType *h, int i, int key) {
	int temp;

	if (key >= h->heap[i].key) {
		printf("error : new key is not smaller than current key");
	}

	while ((i != 1) && (h->heap[i].key < h->heap[i / 2].key)) {
		temp = h->heap[i].key;
		h->heap[i].key = h->heap[i / 2].key;
		h->heap[i / 2].key = temp;
		i /= 2;
	}
}

//increase the element i's value to 'key'
void increase_key_min_heap(HeapType* h, int i, int key) {
	int parent = i, child = 2 * i;

	if (key <= h->heap[i].key) {
		printf("error : new key is not larger than current key");
	}

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key)) {
			child++;
		}

		if (key <= h->heap[child].key) {
			break;
		}

		h->heap[parent].key = h->heap[child].key;
		parent = child;
		child *= 2;
	}
	h->heap[parent].key = key;
}

//Print heap
void print_heap(HeapType* h) {
	for (int i = 1; i < h->heap_size; i++) {
		printf("%d ", h->heap[i].key);
	}
	printf("\n");
}

void main() {
	
	element e[10] = { 1,4,2,7,5,3,3,7,8,9 };
	HeapType h;

	init(&h);

	for (int i = 0; i < 10; i++) {
		insert_min_heap(&h, e[i]);
	}

	printf("Min heap: ");
	print_heap(&h);

	decrease_key_min_heap(&h, 4, 3);
	increase_key_min_heap(&h, 3, 10);

	printf("Result: ");
	print_heap(&h);
}