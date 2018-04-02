#include <iostream>
#include <vector>


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
  ListNode* mergeKLists(std::vector<ListNode*>& lists)
  {
    if (lists.size() == 0)
    {
      return nullptr;
    }

    size_t interval = 1;
    while (interval < lists.size())
    {
      for (size_t i = 0; i + interval < lists.size(); i += interval * 2)
      {
        lists[i] = merge2ListsRecursive(lists[i], lists[i + interval]);
      }
      interval *= 2;
    }
    return lists.front();
  }
private:
  ListNode *merge2ListsRecursive(ListNode *l1, ListNode *l2)
  {
    if (l1 == nullptr)
    {
      return l2;
    }
    if (l2 == nullptr)
    {
      return l1;
    }

    if (l1->val <= l2->val)
    {
      l1->next = merge2ListsRecursive(l1->next, l2);
      return l1;
    }
    else
    {
      l2->next = merge2ListsRecursive(l1, l2->next);
      return l2;
    }
  }

  ListNode* merge2ListsIterative(ListNode* l1, ListNode* l2)
  {
    // 1 3 5
    // 2 4 6
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (l1 != nullptr && l2 != nullptr)
    {
      if (l1->val < l2->val)
      {
        tail->next = l1;
        l1 = l1->next;
      }
      else
      {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
    if (l1 == nullptr)
    {
      tail->next = l2;
    }
    else
    {
      tail->next = l1;
    }
    return dummy.next;
  }
};

int main()
{
  Solution solution;
  ListNode node1(1);
  ListNode node2(3);
  ListNode node3(5);
  node1.next = &node2;
  node2.next = &node3;

  ListNode node4(2);
  ListNode node5(4);
  ListNode node6(6);
  node4.next = &node5;
  node5.next = &node6;

  std::vector<ListNode*> lists;
  lists.push_back(&node1);
  lists.push_back(&node4);
  lists.push_back(nullptr);

  ListNode* answer = solution.mergeKLists(lists);

  while (answer != nullptr)
  {
    std::cout << answer->val << " ";
    answer = answer->next;
  }
  return 0;
}
