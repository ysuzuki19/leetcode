class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<pair<string,size_t>> sortedStrs(strs.size());
    for(size_t i=0; i<sortedStrs.size(); ++i){
      sortedStrs[i] = make_pair(strs[i],i);
      sort(sortedStrs[i].first.begin(),sortedStrs[i].first.end());
    }
    sort(sortedStrs.begin(), sortedStrs.end(), [](auto a, auto b){ return a.first < b.first; });

    vector<vector<string>> vecs(1,vector<string>(1, strs[sortedStrs[0].second]));
    size_t j = 0;
    for(size_t i=1; i<sortedStrs.size(); ++i){
      if(sortedStrs[i-1].first == sortedStrs[i].first){
        vecs[j].push_back(strs[sortedStrs[i].second]);
      }else{
        j++;
        vecs.emplace_back(1, strs[sortedStrs[i].second]);
      }
    }
    return vecs;
  }
};