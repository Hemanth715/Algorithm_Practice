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
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row
 * For each row i, A[i][0] should indicate the number of columns in row i.
 * Then A[i][1] to A[i][col] should have the values in those columns.
 */
 void fillLevel(treenode **t, int n, int **ret, int *idx) {
     int i, cnt = 0;
     treenode **t2 = (treenode ** )malloc(sizeof(treenode *) * n);
     int *ret2 = malloc(sizeof(int) * (n + 1));
     memcpy(t2, t, sizeof(treenode *) * n);
     for (i = 0; i < n; i++ ) {
         ret2[i+1] = t2[i]->val;
     }
     ret2[0] = n;
     ret[*idx] = ret2;
     *idx = *idx + 1;
     for (i = 0; i < n; i++) {
         if (t2[i]->left) {
             t[cnt++] = t2[i]->left;
         }
         if (t2[i]->right)
            t[cnt++] = t2[i]->right;
     }
     free(t2);
     if (cnt == 0)
        return;
     fillLevel(t, cnt, ret, idx);
 }
int ** levelOrder(treenode* A, int *len1) {
    int **ret = (int **)malloc(sizeof(int *) * 1000000);
    int idx = 0;
    treenode **t;
    if (A == NULL) {
        *len1 = 0;
        return ret;
    }
    t = (treenode **)malloc(sizeof(treenode *) * 1000000);
    t[0] = A;
    fillLevel(t, 1, ret, &idx);
    *len1 = idx;
    free(t);
    return ret;
}