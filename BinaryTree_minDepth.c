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
 * 
 * @Output Integer
 */

int retval;

void inorder(treenode* temp, int count)
{
	if (temp != NULL)
	{
		count++;
		if (count < retval && temp->left == NULL && temp->right == NULL)
		{
			retval = count;
			return;
		}
		inorder(temp->left, count);
		inorder(temp->right, count);
	}
}

int minDepth(treenode* A) {
	retval = INT_MAX;
	inorder(A, 0);
	return retval;
}