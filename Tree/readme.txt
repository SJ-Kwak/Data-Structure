#2076016_곽서진
[Successor.c]

inorder traversal에서 node의 successor를 찾는 프로그램

1) typedef struct TreeNode
-int data
-TreeNode *left: left child
-TreeNode *right: right child
-TreeNode *parent: parent

2) TreeNode* tree_successor(TreeNode *p)
: p가 가리키는 node의 successor node를 구해 return하는 함수
-parameter
	TreeNode *p: 찾고자 하는 node의 predecessor node

-----------------------------------------------------------------------
[Predecessor.c]

inorder traversal에서 node의 predecessor를 찾는 프로그램

1) typedef struct TreeNode
-int data
-TreeNode *left: left child
-TreeNode *right: right child
-TreeNode *parent: parent

2) TreeNode* tree_predecessor(TreeNode *p)
: p가 가리키는 node의 predecessor node를 구해 return하는 함수
-parameter
	TreeNode *p: 찾고자 하는 node의 sucessor node

-----------------------------------------------------------------------
[bst_insertion_deletion.cpp]

left subtree의 predecessor를 활용하여 Binary search tree의 insertion과 deletion을 구현하는 프로그램

1) typedef struct TreeNode
-int key: insert 혹은 delete할 node의 data
-TreeNode *left: left subtree
-TreeNode *right: right subtree

2) void insert_node(TreeNode** root, int key)
: insert 함수
-parameter
	TreeNode** root: insert할 tree의 root node
	int key: new node의 data

3) void delete_node(TreeNode** root, int key)
: delete 함수
-parameter
	TreeNode** root:d delete할 tree의 root node
	int key: remove할 node의 data

4) void inorder(TreeNode* root)
: inorder traversal로 node를 print하는 함수
-parameter
	TreeNode* root: print할 tree의 root node