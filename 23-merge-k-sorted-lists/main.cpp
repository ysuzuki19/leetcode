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
ListNode* mergeKLists(vector<ListNode*>& lists) {
  ListNode* mergedList = new ListNode;
  auto mergingTail = mergedList;
  if( !lists.empty() ){
	while( true ){
	  int minimum = INT_MAX;
	  int targetIdx = 0;
	  for(int i=0; i<lists.size(); ++i){
		if( !lists[i] ) continue;
		if( lists[i]->val <= minimum ){
		  minimum = lists[i]->val;
		  targetIdx = i;
		}
	  }
	  if( !lists[targetIdx] ) break;
	  mergingTail->next = lists[targetIdx];
	  mergingTail = mergingTail->next;
	  lists[targetIdx] = lists[targetIdx]->next;
	}
  }
  auto dummy = mergedList;
  mergedList = mergedList->next;
  delete dummy;
  return mergedList;
}
};