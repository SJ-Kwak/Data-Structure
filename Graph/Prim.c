//2076016 °û¼­Áø

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 8
#define INF 1000L

int weight[MAX_VERTICES][MAX_VERTICES] = {
	{ 0,3,INF,INF,INF,INF,INF,14 },
	{ 3,0,8,INF,INF,INF,INF,10 },
	{ INF,8,0,15,2,INF,INF,INF },
	{ INF,INF,15,0,INF,INF,INF,INF },
	{ INF,INF,2,INF,0,9,4,5 },
	{ INF,INF,INF,INF,9,0,INF,INF },
	{ INF,INF,INF,INF,4,INF,0,6 },
	{ 14,10,INF,INF,5,INF,6,0 }
};

typedef struct element {
	int edge;
	int vertex;
	struct element *parent;
} element;

typedef struct {
	element* heap[MAX_VERTICES + 1]; // replace dist[]
	int heap_size;
} HeapType;

element* vertices[MAX_VERTICES]; // list of vertices

void vertex_init(int num, HeapType* h) {
	element* e = (element*)malloc(sizeof(element));
	if (e) {
		if (num == 0)
			e->edge = 0;
		else
			e->edge = INF;

		e->vertex = num;
		e->parent = NULL;

		vertices[num] = e;
		h->heap[num + 1] = e;
	}
}

void build_min_heap(HeapType* h)
{
	int parent, child;
	element* temp;
	for (int i = h->heap_size / 2; i > 0; i--) {
		parent = i, child = 2 * i;

		if ((child + 1 <= h->heap_size) && (h->heap[child]->edge > h->heap[child + 1]->edge))
			child++;
		if ((child <= h->heap_size) && (h->heap[child]->edge < h->heap[parent]->edge)) {
			temp = h->heap[parent];
			h->heap[parent] = h->heap[child];
			h->heap[child] = temp;
			build_min_heap(h);
		}
	}
}

element* delete_min_heap(HeapType* h) {
	int parent, child;
	element* item;
	element* temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// Find a smaller child node
		if ((child < h->heap_size) && (h->heap[child]->edge) > h->heap[child + 1]->edge)
			child++;
		if (temp->edge <= h->heap[child]->edge) break;
		// Move down one level
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void decrease_key_min_heap(HeapType* h, int i, int key) {
	element* temp;

	if (key >= h->heap[i]->edge) {
		printf("error : e key is not smaller than current key");
	}
	
	h->heap[i]->edge = key;
	while ((i != 1) && (h->heap[i]->edge < h->heap[i / 2]->edge)) {
		temp = h->heap[i];
		h->heap[i]= h->heap[i / 2];
		h->heap[i / 2]= temp;
		i /= 2;
	}
}

int check(HeapType* h, int v) {
	for (int i = 1; i < MAX_VERTICES + 1; i++) {
		if (h->heap[i]->vertex == v)
			return TRUE;
	}
	return FALSE;
}

int find_index(HeapType* h, int v) {
	for (int i = 1; i < MAX_VERTICES + 1; i++) {
		if (h->heap[i]->vertex == v)
			return i;
	}
	return -1;
}

void print_prim() {
	for (int i = 1; i < MAX_VERTICES; i++) {
		printf("Vertex %d -> %d \t edge: %d\n", vertices[i]->parent->vertex, vertices[i]->vertex, vertices[i]->edge);
	}
}

void prim(int s, int n) {
	HeapType* q = (HeapType*)malloc(sizeof(HeapType));
	if (q) {
		q->heap_size = 0;
		element* min;

		for (int i = 0; i < n; i++) {
			vertex_init(i, q);
			q->heap_size++;
		}
		build_min_heap(q);

		for (int i = 0; i < n; i++) {
			min = delete_min_heap(q); // Extract Min
			if (min->edge == INF)
				return;

			int u = min->vertex;
			for (int v = 0; v < n; v++) {
				if (weight[u][v] != INF) {
					if ((check(q, v) == 1) && (weight[u][v] < vertices[v]->edge) && (vertices[v] != min)) {
						vertices[v]->parent = min;//v.parent=u;
						int index = find_index(q, vertices[v]->vertex);
						decrease_key_min_heap(q, index, weight[u][v]);//dist[v]<-weight[u][v]
					}
				}
			}
		}
	}
	free(q);
}

void main() {
	prim(0, MAX_VERTICES);
	print_prim();
	for (int i = 0; i < MAX_VERTICES; i++) {
		free(vertices[i]);
	}
}