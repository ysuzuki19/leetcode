/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	}

	node := head
	for node != nil && node.Next != nil {
		node.Val, node.Next.Val = node.Next.Val, node.Val // swap
		node = node.Next.Next
	}
	return head
}