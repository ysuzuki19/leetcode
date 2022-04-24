// https://leetcode.com/problems/design-hashset/

type MyHashSet struct {
	keys [1000001]bool
}

/** Initialize your data structure here. */
func Constructor() MyHashSet {
	return MyHashSet{}
}

func (this *MyHashSet) Add(key int) {
	this.keys[key] = true
}

func (this *MyHashSet) Remove(key int) {
	this.keys[key] = false
}

/** Returns true if this set contains the specified element */
func (this *MyHashSet) Contains(key int) bool {
	return this.keys[key]
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */