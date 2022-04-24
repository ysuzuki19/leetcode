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
  bool isPalindrome(ListNode* head) {
    deque<ListNode*> dq;
    while (head) {
      dq.push_back(head);
      head = head->next;
    }
    while (dq.size() > 1) {
      if (dq.front()->val != dq.back()->val) {
        return false;
      }
      dq.pop_front();
      dq.pop_back();
    }
    return true;
  }
};