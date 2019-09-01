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
 * @input root : Root pointer of the tree 
 * @input k : Integer
 * 
 * @Return Integer
 */

int retval;

int inorder(treenode* temp, int k, int count)
{
	if (temp != NULL)
	{
		count = inorder(temp->left, k, count);
		count++;
		if (count == k)
		{
			retval = temp->val;
		}
		count = inorder(temp->right, k, count);
	}
	return count;
}

int kthsmallest(treenode* root, int k) {
	int count = 0;
	retval = 0;
	count = inorder(root, k, count);
	return retval;
}