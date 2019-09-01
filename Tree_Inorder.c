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
int* inorderTraversal(treenode* A, int *len1) {
    if(A== NULL){
        *len1 = 0;
        return NULL;
    }
    else{
        int i=0,done=0,top=-1;
        int *out=(int*)malloc(sizeof(int)*100000);
        treenode *stack[10000];
        treenode *current = A,*temp;
        
        while(!done){
            if(current!=NULL){
                stack[++top] = current;
                current = current->left;
            }else{
                if(top!=-1){
                    temp = stack[top--];
                    out[i++] = temp->val;
                    current = temp->right;
                }else{
                    done = 1;
                }
            }
        }
        *len1 = i;
        return out;
    }
    
}