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
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
void printpostorder(treenode* node)
{
     if (node == NULL)
          return;
     printpostorder(node->left);
     printpostorder(node->right);
     printf("%d ",node->val);
}
void postorderTraversal(treenode* node, int *len1) {
    printpostorder(node);
    return;
}