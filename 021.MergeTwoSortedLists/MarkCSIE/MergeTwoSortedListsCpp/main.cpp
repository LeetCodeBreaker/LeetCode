#include <iostream>


// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
  {
    ListNode dummy_head(0);
    ListNode* tail = &dummy_head;

    while (l1 && l2)
    {
      if (l1->val <= l2->val)
      {
        appendNode(&tail, &l1);
      }
      else
      {
        appendNode(&tail, &l2);
      }
    }

    tail->next = l1 ? l1 : l2;

    return dummy_head.next;
  }

protected:
  void appendNode(ListNode** tail, ListNode** node)
  {
    (*tail)->next = *node;
    *node = (*node)->next;
    *tail = (*tail)->next;
  }
};

int main()
{
  std::cout << "Hello World!" << std::endl;
  return 0;
}
