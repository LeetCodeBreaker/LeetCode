/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
   struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode *result_head = result;
	result->val = (l1->val + l2->val) % 10;
	int carry = (l1->val + l2->val) / 10 ;
	result->next = NULL;
	//add
	while(true)
	{
		if(l1->next==NULL && l2->next==NULL)
			break;

		int n1=0, n2=0;
		if(l1->next != NULL)
		{
			l1 = l1->next;
			n1 = l1->val;
		}

		if(l2->next != NULL)
		{
			l2 = l2->next;
			n2 = l2->val;
		}

		result->next = (struct ListNode *) malloc(sizeof(struct ListNode));
		result = result->next;
		result->next = NULL;
		result->val = (n1 + n2 + carry) % 10;
		carry = (n1 + n2 + carry) / 10;
	}
	if(carry != 0)
	{
		result->next = (struct ListNode *) malloc(sizeof(struct ListNode));
		result = result->next;
		result->val = carry;
		result->next = NULL;
	}
	return result_head;
}