class Solution {
  bool isPolish(string s) {
    if (s == "+") return true;
    if (s == "-") return true;
    if (s == "*") return true;
    if (s == "/") return true;
    return false;
  }
  int apply(int a, int b, string polish) {
    if (polish == "+") return b + a;
    if (polish == "-") return b - a;
    if (polish == "*") return b * a;
    return b / a;
  }
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for (const auto &t: tokens) {
      if (isPolish(t)) {
        int num = nums.top();
        nums.pop();
        int num_2 = nums.top();
        nums.pop();
        nums.push(apply(num, num_2, t));
      } else {
        nums.push(stoi(t));
      }
    }
    return nums.top();
  }
};