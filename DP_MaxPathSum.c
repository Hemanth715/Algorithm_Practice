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
 int max(int a,int b)
 {
     if(a>b)
     return a;
     return b;
 }
 int maxsum1(treenode* A,int *sum)
 {
     if(!A)
     return 0;
    int ls=maxsum1(A->left,sum);
    int rs=maxsum1(A->right,sum);
   
        int k=max(ls,0)+max(rs,0)+A->val;
        if(k>*sum)
        *sum=k;
   return(max(max(ls,0),max(rs,0))+A->val);
     
 }
int maxPathSum(treenode* A) {
     
int sum=INT_MIN;
   int c=maxsum1(A,&sum);
   return sum;
}
