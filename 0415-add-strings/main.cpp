class Solution {
  int atoi(char c) {
    switch (c) {
      case '0':
        return 0;
      case '1':
        return 1;
      case '2':
        return 2;
      case '3':
        return 3;
      case '4':
        return 4;
      case '5':
        return 5;
      case '6':
        return 6;
      case '7':
        return 7;
      case '8':
        return 8;
      case '9':
        return 9;
      default:
        return 0;
    }
  }
public:
  string addStrings(string num1, string num2) {
    queue<int> q1, q2;
    for (int i=num1.length()-1; i!=-1; i--) {
      q1.push(atoi(num1[i]));
    }
    for (int i=num2.length()-1; i!=-1; i--) {
      q2.push(atoi(num2[i]));
    }
    
    string sumstr;
    bool up = false;
    while (!q1.empty() && !q2.empty()) {
      int sum = (up? 1: 0);
      up = false;
      sum += q1.front() + q2.front();
      q1.pop();
      q2.pop();
      if (sum > 9) {
        up = true;
        sum -= 10;
      }
      sumstr += to_string(sum);
    }
    while (!q1.empty()) {
      int sum = (up? 1: 0);
      up = false;
      sum += q1.front();
      q1.pop();
      if (sum > 9) {
        up = true;
        sum -= 10;
      }
      sumstr += to_string(sum);
    }
    while (!q2.empty()) {
      int sum = (up? 1: 0);
      up = false;
      sum += q2.front();
      q2.pop();
      if (sum > 9) {
        up = true;
        sum -= 10;
      }
      sumstr += to_string(sum);
    }
    if (up) {
      sumstr += '1';
    }
    
    reverse(sumstr.begin(), sumstr.end());
    return sumstr;
  }
};