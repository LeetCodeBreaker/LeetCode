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
  ListNode* removeNthFromEnd(ListNode* head, const int& n)
  {
    ListNode* first = head;
    for (int i = 0; i < n; i++)
    {
      first = first->next;
    }
    ListNode dummy(1);
    dummy.next = head;
    ListNode* second = &dummy;
    while (first)
    {
      first = first->next;
      second = second->next;
    }

    second->next = second->next->next;
    return dummy.next;
  }
};

int main()
{
  Solution solution;
  ListNode node1(1);
  ListNode node2(2);
  ListNode node3(3);
  ListNode node4(4);
  ListNode node5(5);
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;

  ListNode* head = solution.removeNthFromEnd(&node1, 2);
  while (head)
  {
    std::cout << head->val << std::endl;
    head = head->next;
  }

  return 0;
}
