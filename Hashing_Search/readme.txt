#2076016 곽서진
[hash_chain.c]
Hash table에서 chaining을 활용한 delete 함수를 구현한 프로그램

1. typedef struct element
-char key[KEY_SIZE]

2. typedef struct ListNode
-element item
-struct ListNode* link

3. int transform(char* key)
: ASCII code를 더해 string key를 integer로 변환하는 함수
-parameter
	char* key: 변환할 key

4. int hash_function(char* key)
: key mod TABLE_SIZE를 수행하는 division 함수
-parameter
	char* key: division operand

5. void hash_chain_add(element item, ListNode* ht[])
: chaining을 활용하여 hash table의 끝에 item을 삽입하는 함수
-parameter
	element item: hash table에 삽입할 item
	ListNode* ht[]: item을 삽입할 hash table

6. void hash_chain_delete(element item, ListNode* ht[])
: chaining을 활용하여 hash table에서 item을 제거하는 함수
-parameter
	element item: hash table에서 제거할 item
	ListNode* ht[]: item을 제거할 hash table

7. void hash_chain_search(element item, ListNode* ht[])
: hash table에서 item을 찾는 함수
-parameter
	element item: 찾을 item
	ListNode* ht[]: item을 찾을 hash table

8. void hash_chain_print(ListNode* ht[])
: hash table을 출력하는 함수
-parameter
	ListNode* ht[]: 출력할 hash table

9. void init_table(ListNode* ht[])
: hash table을 초기화하는 함수
-parameter
	ListNode* ht[]: 초기화할 hash table

10. void main()
: test code

--------------------------------------------------------------------------------
[bst_sort.c]
Binary Search Tree를 활용하여 정렬하는 프로그램

1. typedef struct TreeNode
-int key
-struct TreeNode* left, *right

2. void insert_node(TreeNode** root, int key)
: bst에 key node를 삽입하는 함수
-parameter
	TreeNode** root: bst의 root node
	int key: 삽입할 node

3. void inorder(TreeNode* root)
: bst를 inorder로 정렬하여 print하는 함수
-parameter
	TreeNode* root: bst의 root node

4. int random(int n)
: 난수 생성 함수
-parameter
	int n: 난수 생성 max값

5. void main()
: test code