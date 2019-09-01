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

int i = 0;

void checkmirrortree(treenode* node1, treenode* node2)
{
	if ((node1 == NULL && node2 == NULL))
	{
		return;
	}
    if((node1 == NULL && node2 != NULL) || (node2 == NULL && node1 != NULL))
    {
    	i++;
    	return;
    }
    checkmirrortree(node1->left, node2->right);
    checkmirrortree(node1->right, node2->left);
    if (node1->val != node2->val)
    {
    	i++;
    }
}

int isSymmetric(treenode* A) {
	i = 0;

	if (A->left == NULL && A->right == NULL)
		return 1;

	if (A->left != NULL && A->right != NULL)
	{
		if (A->left->val != A->right->val)
			return 0;
		if (i == 0)
	    {
	    	return 1;
	    }
	    return 0;
	}
	return 0;
}