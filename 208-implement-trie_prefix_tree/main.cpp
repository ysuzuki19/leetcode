class Trie {
  struct TrieNode {
    bool exist = false;
    unordered_map<char, TrieNode*> nexts;
  };
private:
  TrieNode* root_;
public:
  Trie() {
    root_ = new TrieNode;
  }

  void insert(string word) {
    size_t idx = 0;
    TrieNode* node = root_;
    while( node->nexts.find(word[idx]) != node->nexts.end() ){
      node = node->nexts[ word[idx] ];
      idx++;
    }
    while( idx < word.length() ){
      node->nexts[ word[idx] ] = new TrieNode;
      node = node->nexts[ word[idx] ];
      idx++;
    }
    node->exist = true;
  }

  bool search(string word) {
    size_t idx = 0;
    TrieNode* node = root_;
    while( node->nexts.find(word[idx]) != node->nexts.end() && idx < word.length() ){
      node = node->nexts[ word[idx] ];
      idx++;
    }
    if( idx < word.length() ) return false;
    return node->exist;
  }

  bool startsWith(string prefix) {
    size_t idx = 0;
    TrieNode* node = root_;
    while( node->nexts.find(prefix[idx]) != node->nexts.end() ){
      node = node->nexts[ prefix[idx] ];
      idx++;
    }
    if( idx < prefix.length() ) return false;
    return true;
  }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */