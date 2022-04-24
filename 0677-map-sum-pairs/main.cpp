class MapSum {
  map<string,int> data;
public:
  /** Initialize your data structure here. */
  MapSum() = default;

  void insert(string key, int val) {
    data[key] = val;
  }

  int sum(string prefix) {
    int matched = 0;
    for (const auto& [key, val]: data) {
      if (key.substr(0, prefix.length()) == prefix) {
        matched += val;
      }
    }
    return matched;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */