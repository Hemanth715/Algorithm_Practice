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
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row
 * For each row i, A[i][0] should indicate the number of columns in row i.
 * Then A[i][1] to A[i][col] should have the values in those columns.
 *
 */
 int **a;
 int len = 0;
 
 void copy(int *t,int ctr){
     int i =0;
     a[len] = (int *)malloc(sizeof(int)*(ctr+1));
     a[len][0] = ctr;
     for(i = 1;i<=ctr;i++){
         a[len][i] = t[i-1];
     }
     len++;
 }
 void hasPathSum(treenode* A, int B, int ctr, int *t) {

   if(!A->left&&!A->right){
        if(B-A->val==0){
            t[ctr++] = A->val;
            copy(t,ctr);
        }
        return;
    }
    t[ctr++] = A->val;
    if(A->left)
        hasPathSum(A->left,B-(A->val),ctr,t);
    if(A->right)
        hasPathSum(A->right,B-(A->val),ctr,t);
}
int ** pathSum(treenode* A, int B, int *len1) {
    free(a);
    len = 0;
    a = NULL;
    a = (int **)malloc (sizeof(int*)*5000);
    int t[200];
    hasPathSum(A,B,0,t);
    *len1 = len;
    return a;
}