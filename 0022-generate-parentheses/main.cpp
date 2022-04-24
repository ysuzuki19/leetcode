class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> parentheses;
    parentheses.reserve(100);

    function<void(string, int, int)> generator;
    generator = [&](string str, int opened, int closed){
      if( n==opened && opened==closed ){
        parentheses.push_back(str);
        return;
      }
      if( n>opened ) generator(str+'(', opened+1, closed);
      if( opened>closed ) generator(str+')', opened, closed+1);
    };

    generator("", 0, 0);
    return parentheses;
  }
};