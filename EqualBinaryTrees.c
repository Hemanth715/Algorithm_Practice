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
 * @input B : Root pointer of the tree 
 * 
 * @Output Integer
 */

int i = 0;

void checksametree(treenode* node1, treenode* node2)
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
    checksametree(node1->left, node2->left);
    checksametree(node1->right, node2->right);
    if (node1->val != node2->val)
    {
    	i++;
    }
}

int isSameTree(treenode* A, treenode* B) {
    i = 0;
    checksametree(A, B);
    if (i == 0)
    {
    	return 1;
    }
    return 0;
}
