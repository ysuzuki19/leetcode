class Solution {
public:
  int myAtoi(string str) {
    try {
      return stoi(str);
    }
    catch(std::invalid_argument& e){
      return 0;
    }
    catch(std::out_of_range& e){
      if( str[str.find_first_not_of(' ')] == '-') return INT_MIN;
      else return INT_MAX;
    }
  }
};