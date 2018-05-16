#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};


// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  TreeNode* sortedListToBST(ListNode* head)
  {
    return recursive(head, nullptr);
  }
protected:
  TreeNode* recursive(ListNode* head, ListNode* tail)
  {
    if (head == tail)
    {
      return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != tail && fast->next != tail)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    TreeNode* root = new TreeNode(slow->val);
    root->left = recursive(head, slow);
    root->right = recursive(slow->next, tail);
    return root;
  }
};

int main()
{

  return 0;
}
