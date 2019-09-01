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
listnode* rotateRight(listnode* A, int B) {
	listnode *temp, *temp1, *temp2;
	int size = 0;
	int size1;
	temp = A;
	while(temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	size++;
	temp1 = temp;
	B %= size;
	size1 = size - B - 1;
	temp = A;
	while(size1 > 0)
	{
		size1--;
		temp = temp->next;
	}
	//printf("tempval = %d \n", temp->val);
	temp2 = temp->next;
	temp1->next = A;
	A = temp2;
	temp->next = NULL;
	return A;
}