/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* deleteDuplicates(listnode* A) {
    listnode* ptr=A,*temp;
    while(ptr->next!=NULL){
        if(ptr->val==ptr->next->val){
            temp=ptr->next->next;
            free(ptr->next);
            ptr->next=temp;
        }
        else ptr=ptr->next;
    }
    return A;
}