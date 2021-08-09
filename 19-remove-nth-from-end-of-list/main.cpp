/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    stack<ListNode*> stk;
    ListNode* node = head;
    while (node) {
      stk.push(node);
      node = node->next;
    }
    while (n) {
      node = stk.top();
      stk.pop();
      n--;
    }
    if (stk.empty()) {
      return node->next;
    }
    stk.top()->next = node->next;
    return head;
  }
};