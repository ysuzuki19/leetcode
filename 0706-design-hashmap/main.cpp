class MyHashMap {
  int* table_;
public:
  /** Initialize your data structure here. */
  MyHashMap() {
    table_ = new int[1000000];
    for (int i=0; i<1000000; ++i) {
      table_[i] = -1;
    }
  }

  /** value will always be non-negative. */
  void put(int key, int value) {
    table_[key] = value;
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    return table_[key];
  }

  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    table_[key] = -1;
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */