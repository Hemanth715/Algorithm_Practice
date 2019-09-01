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
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
listnode* removeNthFromEnd(listnode* A, int B) {
	listnode *temp;
	temp = A;
	int size = 0;
	while(temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	if (B >= size)
	{
		A = A->next;
		return A;
	}
	temp = A;
	int size1 = size - B - 1;
	while(size1 > 0)
	{
		temp = temp->next;
		size1--;
	}
	temp->next = temp->next->next;
	return A;
}