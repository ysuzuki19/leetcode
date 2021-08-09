class Solution {
public:
  string parseEmail(string const& email) {
    string localname;
    int i = 0;
    for(; i<email.length(); ++i ){
      if( email[i] == '.' ) continue;
      if( email[i] == '+' ) while( email[i] != '@' ) i++;
      if( email[i] == '@' ) break;
      localname += email[i];
    }
    return localname + email.substr(i);
  }
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;
    for(const auto& email : emails) st.insert( parseEmail(email) );
    return st.size();
  }
};