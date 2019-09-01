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
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output root pointer of tree.
 */
treenode *BST(const int *A,int start, int end)
{
    if(start>end)
    return NULL;

    int mid=(start+end)/2;
    treenode *root=treenode_new(A[mid]);
    root->left=BST(A,start,mid-1);
    root->right=BST(A,mid+1,end);
    return root;
}
treenode* sortedArrayToBST(const int* A, int n1) {
    return BST(A,0,n1-1);
}
