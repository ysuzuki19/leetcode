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
  ListNode* partition(ListNode* head, int x) {
    if (!head) return nullptr;
    ListNode* head_less = new ListNode(); // dummy-node
    ListNode* head_greater = new ListNode(); // dummy-node
    ListNode* less = head_less;
    ListNode* greater = head_greater;
    
    while (head) {
      ListNode* node = head;
      head = head->next;
      node->next = nullptr;

      if (node->val < x) {
        less->next = node;
        less = less->next;
      } else {
        greater->next = node;
        greater = greater->next;
      }
    }
    
    head_greater = head_greater->next;
    if (head_greater) less->next = head_greater;
    
    return head_less->next;
  }
};