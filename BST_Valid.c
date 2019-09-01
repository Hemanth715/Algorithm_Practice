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
int bstutil(treenode* A,int min,int max)
{
    if(A==NULL)     return 1;
    return (A->val>min && A->val<max && 
        bstutil(A->left,min,A->val)&&
        bstutil(A->right,A->val,max));
}
int isValidBST(treenode* A) {
    return bstutil(A,INT_MIN,INT_MAX);
}
