#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};


// 1 2 3 4 -> 1 4 2 3
// 1 2 3 4 5 -> 1 5 2 4 3
class Solution
{
public:
  void reorderList(ListNode* head)
  {
    unsigned int list_length = getListSize(head);
    if (list_length <= 2)
    {
      return;
    }

    // split into two lists
    ListNode* latter = splitList(head, list_length / 2);

    // reverse the latter half
    ListNode* reversed_list = reverseList(latter);

    // merge the two lists
    mergeList(head, reversed_list);
  }

private:
  unsigned int getListSize(ListNode* head)
  {
    unsigned int list_length = 0;
    ListNode* current = head;
    while (current != nullptr)
    {
      current = current->next;
      list_length++;
    }
    return list_length;
  }

  ListNode* splitList(ListNode* head, unsigned int break_point)
  {
    ListNode* current = head;
    ListNode* prev = nullptr;
    for (unsigned int i = 0; i < break_point; i++)
    {
      prev = current;
      current = current->next;
    }
    prev->next = nullptr;
    return current;
  }

  ListNode* reverseList(ListNode* head)
  {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr)
    {
      ListNode* temp = current->next;
      current->next = prev;
      prev = current;
      current = temp;
    }
    return prev;
  }

  void mergeList(ListNode* head1, ListNode* head2)
  {
    ListNode* current = head1;
    ListNode* latter = head2;
    while (current != nullptr && latter != nullptr)
    {
      ListNode* temp = current->next;
      current->next = latter;
      ListNode* temp2 = latter->next;
      if (temp != nullptr)
      {
        latter->next = temp;
      }
      current = temp;
      latter = temp2;
    }
  }

};

void printList(ListNode* head)
{
  while (head != nullptr)
  {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main()
{
  Solution solution;
  ListNode *test = new ListNode(1);
  test->next = new ListNode(2);
  test->next->next = new ListNode(3);
  test->next->next->next = new ListNode(4);
  test->next->next->next->next = new ListNode(5);

  solution.reorderList(test);
  printList(test);

  delete test->next->next->next->next;
  delete test->next->next->next;
  delete test->next->next;
  delete test->next;
  delete test;
  return 0;
}
