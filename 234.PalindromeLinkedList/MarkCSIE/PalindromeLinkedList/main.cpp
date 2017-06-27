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

protected:
  ListNode* reverseList(ListNode* const head)
  {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr)
    {
      ListNode* temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
  }

public:
  bool isPalindrome(ListNode* const head)
  {
    // find the first half
    ListNode* prev = nullptr;
    ListNode* p1 = head;
    ListNode* p2 = head;

    ListNode* second = nullptr;
    while (p2 != nullptr)
    {
      second = p1->next;
      if (p2->next == nullptr)
      {
        break;
      }
      prev = p1;
      p1 = p1->next;
      p2 = p2->next->next;
    }

    // if there are more than 1 element
    if (prev != nullptr)
    {
      prev->next = nullptr;
    }

    // reverse the first half
    ListNode* first = reverseList(head);

    // compare the first half and the second half
    while (second != nullptr)
    {
      if (second->val != first->val)
      {
        return false;
      }
      second = second->next;
      first = first->next;
    }
    return true;
  }
};

int main()
{
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(1);
  n1.next = &n2;
  n1.next->next = &n3;

  Solution solution;
  std::cout << solution.isPalindrome(&n1) << std::endl;

  return 0;
}
