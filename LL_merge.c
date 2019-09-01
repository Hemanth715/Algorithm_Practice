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
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* mergeTwoLists(listnode* A, listnode* B) {
	listnode *temp, *temp1, *temp2;
	listnode *C;
	temp = A;
	temp1 = B;
	if (temp->val <= temp1->val)
	{
		C = listnode_new(temp->val);
		temp = temp->next;
	}
	else
	{
		C = listnode_new(temp1->val);
		temp1 = temp1->next;
	}
	temp2 = C;
	while(temp != NULL && temp1 != NULL)
	{
		if(temp->val <= temp1->val)
		{
			temp2->next = listnode_new(temp->val);
			temp = temp->next;
		}
		else
		{
			temp2->next = listnode_new(temp1->val);
			temp1 = temp1->next;
		}
		temp2 = temp2->next;
	}
	if (temp1 == NULL)
	{
		while(temp != NULL)
		{
			temp2->next = listnode_new(temp->val);
			temp = temp->next;
			temp2 = temp2->next;
		}
	}
	else
	{
		while(temp1 != NULL)
		{
			temp2->next = listnode_new(temp1->val);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	return C;
}