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
listnode* insertionSortList(listnode* A) {
    listnode *res=A,*nxt,*a=A->next,*i;
    res->next=NULL;
    while(a)
    {
        nxt=a->next;
        if(a->val<=res->val)
        {
            a->next=res;
            res=a;
        }
        else
        {
            i=res;
            while(i->next && i->next->val<a->val)
            i=i->next;
            a->next=i->next;
            i->next=a;
        }
        a=nxt;
    }
    return res;
}
