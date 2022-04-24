class Solution {
public:
  string pushDominoes(string dominoes) {
    queue<pair<int, char>> q; // <idx, /[L|R]/>
    map<int, char> commands; // <idx, /[L|R]/>
    for (size_t i=0; i<dominoes.length(); ++i) {
      if (dominoes[i] != '.') {
        q.emplace(i, dominoes[i]);
      }
    }
    while (!q.empty()) {
      while (!q.empty()) {
        size_t idx = q.front().first;
        if (q.front().second == 'L') {
          idx --;
          if (idx == -1) {
            q.pop();
            continue;
          }
        } else {
          /* q.front().second == 'R' */
          idx ++;
          if (idx == dominoes.length()) {
            q.pop();
            continue;
          }
        }
        
        if (dominoes[idx] == '.') {
          decltype(commands)::iterator found = commands.find(idx);
          if (found == commands.end()) {
            commands.emplace(idx, q.front().second);
          } else {
            commands.erase(found);
          }
        }
        
        q.pop();
      }
      
      for (const auto& command: commands) {
        dominoes[command.first] = command.second;
        q.emplace(command);
      }
      commands.clear();
    }
    return dominoes;
  }
};