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
  public ListNode removeNthFromEnd(ListNode head, int n) {
    Stack<ListNode> stk = new Stack<ListNode>();
    ListNode node = head;
    while (node != null) {
      stk.push(node);
      node = node.next;
    }
    while (n != 0) {
      node = stk.pop();
      n--;
    }
    
    if (stk.isEmpty()) {
      return node.next;
    }
    stk.peek().next = node.next;
    return head;
  }
}
