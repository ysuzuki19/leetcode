class Solution {
public:
  string toGoatLatin(string S) {
    vector<string> vs;
    vs.reserve(count(S.begin(), S.end(), ' ') + 1);
	
    while (!S.empty()) {
      size_t found = S.find_first_of(' ');
      if (found!=std::string::npos) {
        vs.push_back(S.substr(0, found));
        S = S.substr(found+1);
      } else {
        vs.push_back(S);
        S.clear();
      }
    }
    
	// function to check char is vowell or not
    auto isVoin = [](char c) {
      if (c=='a' || c=='A') return true;
      if (c=='i' || c=='I') return true;
      if (c=='u' || c=='U') return true;
      if (c=='e' || c=='E') return true;
      if (c=='o' || c=='O') return true;
      return false;
    };
    
    string tail = "ma";
    for (int i=0; i<vs.size(); ++i) {
      if (!isVoin(vs[i][0])) vs[i] = vs[i].substr(1) + vs[i][0];
      S += " " + vs[i] + (tail+='a');
    }
    return S.substr(1);
  }
};