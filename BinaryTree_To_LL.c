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
 * @Output root pointer of tree.
 */
typedef treenode tree;
tree *next = NULL;
tree *prev = NULL;
tree *head = NULL;
void preFlat(tree *A)
{
    if(A == NULL)
        return;
    prev = A;
    tree *templ = A->left;
    tree * tempr = A->right;
    
    if(!templ && ! tempr)
    {
        return;
    }
    
    if(templ)
    {
        next = templ;
        prev->left = NULL;
        prev->right = next;
        preFlat(next);
    }
    if(tempr)
    {
        next = tempr;
        prev->left = NULL;
        prev->right = next;
        preFlat(next);
    }
    
}
treenode* flatten(treenode* A) {
    next = NULL;
    prev = A;
    head = A;
    preFlat(A);
    return head;
}