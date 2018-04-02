#include <iostream>


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution
{
public:
  ListNode* reverseKGroup(ListNode* const head, const int& k)
  {
    // Calculate list length
    ListNode* curr_node = head;
    unsigned int length = 0;
    while (curr_node != nullptr)
    {
      ++length;
      curr_node = curr_node->next;
    }

    ListNode* prev_head_node = new ListNode(-1);
    prev_head_node->next = head;
    ListNode* prev_node = prev_head_node;
    while (length >= k)
    {
      ListNode* curr_node = prev_node->next;
      ListNode* next_node = curr_node->next;
      for (unsigned int i = 1; i < k; i++)
      {
        curr_node->next = next_node->next;
        next_node->next = prev_node->next;
        prev_node->next = next_node;
        next_node = curr_node->next;
      }
      prev_node = curr_node;
      length -= k;
    }

    return prev_head_node->next;
  }
};

int main()
{
  Solution solution;

  ListNode *test = new ListNode(1);
  test->next = new ListNode(2);
  test->next->next = new ListNode(3);
  test->next->next->next = new ListNode(4);
  test->next->next->next->next = new ListNode(5);

  ListNode *answer = solution.reverseKGroup(test, 3);
  while (answer != nullptr) {
    std::cout << answer->val << std::endl;
    ListNode *temp = answer;
    answer = answer->next;
    delete temp;
  }
  return 0;
}
