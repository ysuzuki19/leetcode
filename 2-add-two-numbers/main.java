/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  public ListNode addTwoNumbers(ListNode l1, ListNode l2) { //java learn
    return this.addTwoNumbers(l1, l2, false);
  }
    
  public ListNode addTwoNumbers(ListNode l1, ListNode l2, boolean isCarry) { //java learn
    if (l1 != null || l2 != null) { //java learn is null
      int sum_val = 0;
      if (l1 != null) sum_val += l1.val;
      if (l2 != null) sum_val += l2.val;
      
      if (isCarry) { //java learn int + boolean
        sum_val ++;
      }
      isCarry = false;
      
      if (sum_val > 9) {
        sum_val -= 10;
        isCarry = true;
      }
      
      ListNode l1_next = l1!=null? l1.next: null; // java learn
      ListNode l2_next = l2!=null? l2.next: null;
      
      ListNode node = new ListNode(sum_val);
      node.next = addTwoNumbers(l1_next, l2_next, isCarry);
      return node;
    }
    if (isCarry) return new ListNode(1);
    return null;
  }
}