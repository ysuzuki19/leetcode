/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) return vector<vector<int>>();
    vector<vector<int>> levels;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
      vector<int> level;
      int n = q.size();
      while (n) {
        level.push_back(q.front()->val);
        for (const auto& child: q.front()->children) {
          q.push(child);
        }
        q.pop();
        n--;
      }
      levels.push_back(move(level));
    }
    return levels;
  }
};