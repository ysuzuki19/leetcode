class BrowserHistory {
private:
  list<string> history_;
  std::list<string>::iterator currentPage_;
public:
  BrowserHistory(string homepage) {
    history_.push_back(homepage);
    currentPage_ = history_.begin();
  }

  void visit(string url) {
    {
      auto pos = currentPage_;
      pos++;
      history_.erase(pos, history_.end());
    }
    history_.push_back(url);
    currentPage_++;
  }

  string back(int steps) {
    for(int i=0; i<steps; ++i){
      if( currentPage_ == history_.begin() ){
        break;
      }
      currentPage_--;
    }
    return *currentPage_;
  }

  string forward(int steps) {
    for(int i=0; i<steps; ++i){
      currentPage_++;
      if( currentPage_ == history_.end() ){
        currentPage_--;
        break;
      }
    }
    return *currentPage_;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */