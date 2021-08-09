class UndergroundSystem {
  struct CustomerIO {
    int time = 0;
    CustomerIO (int in, int out) : time{out-in} {}
    ~CustomerIO () {}
  };
  
  map<string,list<CustomerIO>> checkIOs_;
  map<int, pair<string, int>> checked_; // (id, (stationName, inTime))
public:
  UndergroundSystem() {
  }

  void checkIn(int id, string stationName, int t) {
    auto pos = checked_.find(id);
    if (pos == checked_.end()) {
      checked_.emplace(id, make_pair(stationName, t));
    } else {
      pos->second.first = stationName;
      pos->second.second = t;
    }
  }

  void checkOut(int id, string stationName, int t) {
    auto pos = checked_.find(id);
    auto checkIO = checkIOs_.find(pos->second.first + stationName);
    if (checkIO == checkIOs_.end()) {
      checkIOs_.emplace(pos->second.first + stationName, list<CustomerIO>());
      checkIO = checkIOs_.find(pos->second.first + stationName);
    }
    CustomerIO cio (pos->second.second, t);
    checkIO->second.push_back(cio);
  }

  double getAverageTime(string startStation, string endStation) {
    int sum = 0;
    auto checkIO = checkIOs_.find(startStation + endStation);
    
    if (checkIO == checkIOs_.end()) return 0.0;
    
    for (const auto& io: checkIO->second) sum += io.time;
    
    return (double)sum / (double)checkIO->second.size();
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */