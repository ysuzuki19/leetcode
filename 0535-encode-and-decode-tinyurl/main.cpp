class Solution {
  vector<string> urls_;
public:
  string encode(string longUrl) {
    urls_.push_back(longUrl);
    return to_string(urls_.size() - 1);
  }

  string decode(string shortUrl) {
    return urls_[stoi(shortUrl)];
  }
};