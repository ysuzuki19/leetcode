class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    queue<int> keys;
    
    for (const auto& key: rooms[0])  keys.push(key);
    rooms[0].clear();
    
    while (!keys.empty()) {
      int key = keys.front();
      keys.pop();
      for (const auto& e: rooms[key]) keys.push(e);
      rooms[key].clear();
    }
    
    for (const auto& room: rooms) if (!room.empty()) return false;
    return true;
  }
};