#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};


class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (head == nullptr)
    {
      return false;
    }
    ListNode *current1 = head;
    ListNode *current2 = head->next;

    while (current1 != nullptr && current2 != nullptr)
    {
      if (current1 == current2)
      {
        return true;
      }
      current1 = current1->next;
      if (current2->next == nullptr)
      {
        break;
      }
      current2 = current2->next->next;
    }
    return false;
  }
};

int main()
{
  Solution solution;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);

  std::cout << solution.hasCycle(head) << std::endl;

  delete head->next;
  delete head;
  return 0;
}
