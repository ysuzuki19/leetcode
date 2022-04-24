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
  public ListNode partition(ListNode head, int x) {
    if (head == null) return null;
    ListNode head_less = new ListNode(); // dummy-node
    ListNode head_greater = new ListNode(); // dummy-node
    ListNode less = head_less;
    ListNode greater = head_greater;
    
    while (head != null) {
      ListNode node = head;
      head = head.next;
      node.next = null;

      if (node.val < x) {
        less.next = node;
        less = less.next;
      } else {
        greater.next = node;
        greater = greater.next;
      }
    }
    
    head_greater = head_greater.next;
    if (head_greater != null) less.next = head_greater;
    
    return head_less.next;
  }
}