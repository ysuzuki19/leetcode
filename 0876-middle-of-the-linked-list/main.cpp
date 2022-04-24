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
  ListNode* middleNode(ListNode* head) {
    ListNode* middle;
    size_t size = 0;
    function<void(ListNode*, int)> searchMiddle = [&](ListNode* node, int idx){
      size++;
      if( node->next ) searchMiddle(node->next, idx+1);
      if( size/2 == idx ) middle = node;
    };
    searchMiddle(head, 0);
    return middle;
  }
};