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
  ListNode* swapNodes(ListNode* head, int k) {
    deque<ListNode*> dq;
    ListNode* node = head;
    while (node) {
      dq.push_back(node);
      node = node->next;
    }
    if (dq.size()/2 + dq.size()%2 < k) k = dq.size() + 1 - k;
    
    for (int i=0; i<k-1; ++i) {
      dq.pop_front();
      dq.pop_back();
    }
    
    swap(dq.front()->val, dq.back()->val);
    return head;
  }
};