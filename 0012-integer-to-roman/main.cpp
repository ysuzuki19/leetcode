class Solution {
public:
  string intToRoman(int num) {
    auto digitConverter = [](char c1, char c5, char c10, int num){
      string part;
      switch(num){
        case 3: part += c1;
          [[fallthough]]
        case 2: part += c1;
          [[fallthough]]
        case 1: part += c1;
          return part;
        case 4: part += c1;
          [[fallthough]]
        case 5: part += c5;
          return part;
        case 8: part += c1;
          [[fallthough]]
        case 7: part += c1;
          [[fallthough]]
        case 6: part += c1;
          return c5 + part;
        case 9:
          part += c1;
          part += c10;
          return part;
        default:
          return part;
      }
    };
    string roman;
    roman += digitConverter('M',' ',' ',num/1000%10);
    roman += digitConverter('C','D','M',num/100%10);
    roman += digitConverter('X','L','C',num/10%10);
    roman += digitConverter('I','V','X',num%10);
    return roman;
  }
};