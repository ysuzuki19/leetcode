class Solution {
  vector<int> decomposition(int num) {
    vector<int> digits;
    while (num) {
      digits.push_back(num%10);
      num /= 10;
    }
    return digits;
  }
  int join(vector<int> digits) {
    if (digits.front()==0) return 0;
    int power = 1;
    int joined = 0;
    for (int i=digits.size()-1; i!=-1; --i) {
      joined += digits[i]*power;
      power *= 10;
    }
    return joined;
  }
    
  queue<int> permutation(vector<int> digits) {
    sort(digits.begin(), digits.end());
    queue<int> all_permutation;
    do {
      int joined = join(digits);
      if (joined) all_permutation.push(joined);
    } while (next_permutation(digits.begin(), digits.end()));
    return all_permutation;
  }
public:
  bool reorderedPowerOf2(int N) {
    queue<int> permuted = permutation(decomposition(N));
    int num = 1;
    while (!permuted.empty()) {
      if (permuted.front() == num) return true;
      if (permuted.front() > num) {
        num = num << 1;
      } else {
        permuted.pop();
      }
    }
    return false;
  }
};