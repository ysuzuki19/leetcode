// https://leetcode.com/problems/design-linked-list/

type Node struct {
	Val  int
	Prev *Node
	Next *Node
}

func NewNode(val int, prev, next *Node) *Node {
	return &Node{val, prev, next}
}

type MyLinkedList struct {
	head *Node
	tail *Node
	Len  int
}

/** Initialize your data structure here. */
func Constructor() MyLinkedList {
	head := NewNode(0, nil, nil)
	tail := NewNode(0, nil, nil)
	head.Next, tail.Prev = tail, head
	return MyLinkedList{head, tail, 0}
}

func (this *MyLinkedList) outOfRange(index int) bool {
	return index < 0 || this.Len <= index
}

/** Must not out of range **/
func (this *MyLinkedList) getNodeAtIndex(index int) *Node {
	node := this.head.Next
	for i := 0; i < index; i++ {
		node = node.Next
	}
	return node
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
func (this *MyLinkedList) Get(index int) int {
	if this.outOfRange(index) {
		return -1
	}
	return this.getNodeAtIndex(index).Val
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
func (this *MyLinkedList) AddAtHead(val int) {
	node := NewNode(val, this.head, this.head.Next)
	node.Prev.Next, node.Next.Prev = node, node
	this.Len++
}

/** Append a node of value val to the last element of the linked list. */
func (this *MyLinkedList) AddAtTail(val int) {
	node := NewNode(val, this.tail.Prev, this.tail)
	node.Prev.Next, node.Next.Prev = node, node
	this.Len++
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
func (this *MyLinkedList) AddAtIndex(index int, val int) {
	node := this.getNodeAtIndex(index)
	newnode := NewNode(val, node.Prev, node)
	newnode.Prev.Next, newnode.Next.Prev = newnode, newnode
	this.Len++
}

/** Delete the index-th node in the linked list, if the index is valid. */
func (this *MyLinkedList) DeleteAtIndex(index int) {
	if this.outOfRange(index) {
		return
	}
	node := this.getNodeAtIndex(index)
	node.Prev.Next, node.Next.Prev = node.Next, node.Prev
	node = nil
	this.Len--
}

func (this *MyLinkedList) Print() {
	for n := this.head.Next; n != this.tail; n = n.Next {
		fmt.Println(n)
	}
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */