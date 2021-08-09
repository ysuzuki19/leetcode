class MyCircularQueue {
  list<int> vals_;
  int k_;
public:
    MyCircularQueue(int k) : k_{k} {
    }
    
    bool enQueue(int value) {
      if (vals_.size() == k_) return false;
      vals_.push_back(value);
      return true;
    }
    
    bool deQueue() {
      if (vals_.empty()) return false;
      vals_.pop_front();
      return true;
    }
    
    int Front() {
      if (vals_.empty()) return -1;
      return vals_.front();
    }
    
    int Rear() {
      if (vals_.empty()) return -1;
      return vals_.back();
    }
    
    bool isEmpty() {
      return vals_.empty();
    }
    
    bool isFull() {
      return vals_.size() == k_;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */