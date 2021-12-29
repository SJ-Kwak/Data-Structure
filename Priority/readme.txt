[heapsort.c]
heap정렬을 구현하는 프로그램

1) typedef struct element
-key: heap의 node

2) typedef struct HeapType
-heap
-heap_size: heap 크기

3) int random(int n)
: 0과 n-1 사이의 임의의 수를 발생시키는 함수
- parameter
	int n: 임의의 수의 범위

4) void init(HeapType* h)
: heap을 초기화하는 함수
- parameter
	HeapType* h: 초기화할 heap

5) void insert_max_heap(HeapType* h, element item)
: heap에 item 삽입하는 함수
- parameter
	HeapType* h: 삽입할 heap
	element item: 삽입할 item

6) element delete_max_heap(HeapType* h)
: heap의 root를 삭제하는 함수
- parameter
	HeapType* h: root를 삭제할 heap

7) void build_max_heap(HeapType* h)
: max heap을 구현하는 함수
- parameter
	HeapType* h: max heap을 구현할 heap

8) void heap_sort(HeapType* h, element* a, int n)
: heap을 정렬하는 함수
- parameter
	HeapType* h: 정렬할 heap
	element* a: output
	int n: input_size

9) bool check_sort_results(element* output, int n)
: heap_sort가 정확하게 구현되었는지 확인하는 함수
- parameter
	element* output: output
	int n: input_size

10) void main()
: test code
heap 정렬을 구현하고, runtime을 측정한다.

---------------------------------------------------------------------------------------

[huffman.c]
Huffman binary tree를 사용하여 data를 encode, decode하는 프로그램

1) typedef struct input_huff
: input data for huffman code
-char* data: character array
-int* freq: frequency array
-int size: number of characters

2) typedef struct TreeNode
: structure for huffman binary tree
-char data: character(a~f)
-int key: frequency
-int bits[MAX_BIT]: huffman codeword
-int bit_size: huffman codeword's size
-struct TreeNode* l: left child of huffman binary tree
-struct TreeNode* r: right child of huffman binary tree

3) typedef struct bits_stream
: structure for bits stream
-int* stream: bits array
-int length: bits length

4) typedef struct element
: structure for elements used in the heap
-TreeNode* ptree
-int key: frequency of each character

5) typedef struct HeapType
: structure for heap
-element heap[MAX_ELEMENT}
-int heap_size: heap size

6) int init(HeadType* h)
: heap을 초기화하는 함수
- parameter
	HeadType* h: 초기화할 heap

7) int is_empty(HeapType* h)
: heap이 비었는지 확인하는 함수
- parameter
	HeapType* h: 확인할 대상 heap

8) void insert_min_heap(HeapType* h, element item)
: new node를 삽입하는 함수
- parameter
	HeadType* h: 삽입 대상 heap
	element item: new node

9) element delete_min_heap(HeapType* h)
: root node를 삭제하는 함수
- parameter
	HeadType* h: 삭제 대상 heap

10) TreeNode* make_tree(TreeNode* left, TreeNode* right)
: binary tree에 node를 생성하는 함수
- parameter
	TreeNode *left: 생성된 node의 left child
	TreeNode *right: 생성된 node의 right child

11) void destroy_tree(TreeNode* root)
: binary tree를 제거하는 함수
- parameter
	TreeNode* root: 제거할 binary tree의 root node

12) element huffman_tree(input_huff* huff)
: huffman binary tree를 생성하는 함수
- parameter
	input_huff* huff: huffman code의 input data

13) void huffman_traversal(TreeNode* node)
: huffman binary tree에서 huffman codeword를 생성하는 함수
- parameter
	TreeNode* node: huffman binary tree의 root node

14) int** mem_2D_int(int row, int col)
: 2D array의 memory를 동적할당하는 함수
- parameter
	int row: row 개수
	int col: col 개수

15) void print_codeword()
: 각각의 char의 codeword를 출력하는 함수

16) void huffman_encoding(char* str, bits_stream* bits_str)
: character string을 bits stream으로 encoding하는 함수
- parameter
	char* str: encode할 characters
	bits_stream* bits_str: huffman binary tree에서 encoding된 bits stream을 저장하는 array

17) int huffman_decoding(bits_stream* bits_str, TreeNode* node, char* decoded_str)
: bits stream을 character string으로 decoding하는 함수
- parameter
	bits_stream* bits_str: decode할 bits stream
	TreeNode* node: huffman binary tree의 root node
	char* decoded_str: decoded된 결과

18) void main()
: test code
