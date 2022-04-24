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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  auto comp = [](ListNode* a, ListNode* b){ return a->val > b->val; };
  priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq{comp};
  for(; l1; l1=l1->next ) pq.push(l1);
  for(; l2; l2=l2->next ) pq.push(l2);
  
  ListNode* sorted = new ListNode;
  ListNode* sortHead = sorted;
  while( !pq.empty() ){
    sorted->next = pq.top();
    pq.pop();
    sorted = sorted->next;
  }
  sorted->next = nullptr;
  sorted = sortHead->next;
  delete sortHead;
  return sorted;
}
};