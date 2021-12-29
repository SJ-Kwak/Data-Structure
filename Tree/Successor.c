//Assignment5(2) 2076016 °û¼­Áø

#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right, * parent;
} TreeNode;

//		G
//	C		F
//A   B   D   E

TreeNode n1 = { 'A', NULL, NULL, NULL };
TreeNode n2 = { 'B', NULL, NULL, NULL };
TreeNode n3 = { 'C', &n1, &n2, NULL };
TreeNode n4 = { 'D', NULL, NULL, NULL };
TreeNode n5 = { 'E', NULL, NULL, NULL };
TreeNode n6 = { 'F', &n4, &n5, NULL };
TreeNode n7 = { 'G', &n3, &n6, NULL };
TreeNode* exp = &n7;

TreeNode* tree_successor(TreeNode* p) {
	TreeNode* q;
	if (p->right != NULL) {//p's right subtree is not null
		q = p->right;
		while (q->left != NULL)
			q = q->left;
		return q;
	}

	//p's right subtree is null
	q = p->parent;
	while (q != NULL && p == q->right) {
		p = q;
		q = q->parent;
	}
	return q;
}

void main() {
	TreeNode* q = exp;
	n1.parent = &n3;
	n2.parent = &n3;
	n3.parent = &n7;
	n4.parent = &n6;
	n5.parent = &n6;
	n6.parent = &n7;
	n7.parent = NULL;

	//Go to leftmost node
	while (q->left)
		q = q->left;

	do {
		printf("%c\n", q->data);
		//Call the successor
		q = tree_successor(q);
	} while (q);
}

