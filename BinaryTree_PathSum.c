/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * @input B : Integer
 * 
 * @Output Integer
 */

int retval;

void inorder(treenode* temp, int sum, int B)
{
	if (temp != NULL)
	{
		sum += temp->val;
		if (sum == B && temp->left == NULL && temp->right == NULL)
		{
			retval = 1;
			return;
		}
		inorder(temp->left, sum, B);
		inorder(temp->right, sum, B);
	}
}

int hasPathSum(treenode* A, int B) {
	retval = 0;
	inorder(A, 0, B);
	return retval;
}