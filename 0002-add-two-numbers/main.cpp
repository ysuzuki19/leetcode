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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, bool isCarry=false) {
    if (!l1 && !l2) return isCarry? new ListNode(1): nullptr;
    int sumed = l1? l2? l1->val + l2->val + isCarry: l1->val + isCarry: l2->val + isCarry;
    return new ListNode(sumed>9?sumed-10:sumed, addTwoNumbers(l1?l1->next:l1, l2?l2->next:l2, sumed>9?true:false));
  }
};

/* Explanation
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, bool isCarry=false) {
    if (!l1 && !l2) {
      if (isCarry) return new ListNode(1);
      return nullptr;
    }
    int sumed = l1? l2? l1->val + l2->val : l1->val : l2->val;
    if (isCarry) {
      sumed++;
      isCarry = false;
    }
    if (sumed > 9) {
      isCarry = true;
      sumed -= 10;
    }

    auto sum_l = new ListNode(sumed);

    auto next_l1 = l1? l1->next: l1;
    auto next_l2 = l2? l2->next: l2;
    sum_l->next = addTwoNumbers(next_l1, next_l2, isCarry);
    return sum_l;
  }
*/