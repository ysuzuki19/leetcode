class Solution {
  bool isMatch(string const& str, string const& query) {
    for (int i=0; i<query.length(); ++i) {
      if (str[i] != query[i]) return false;
    }
    return true;
  }
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> suggests;
    for (int i=0; i<searchWord.length(); ++i) {
      string query = searchWord.substr(0, i+1);
      vector<string> subsuggests;
      for (const auto& product: products) {
        if (isMatch(product, query)) subsuggests.push_back(product);
        if (subsuggests.size() == 3) break;
      }
      suggests.push_back(subsuggests);
    }
    return suggests;
  }
};