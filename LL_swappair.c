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
listnode* swapPairs(listnode* A) {
	listnode *temp, *temp1, *temp2;
	temp = A;
	if (temp->next != NULL)
	{
		A = temp->next;
		temp->next = A->next;
		A->next = temp;
		temp2 = temp;
		temp = temp->next;
	}
	while(temp != NULL && temp->next != NULL)
	{
		temp1 = temp->next;
		temp2->next = temp1;
		temp->next = temp1->next;
		temp1->next = temp;
		temp2 = temp;
		temp = temp->next;
	}
	return A;
}