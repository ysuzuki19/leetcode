// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
  vector<int> postorder(Node* root) {
    if (!root) return {};
    vector<int> posts;
    function<void(Node*)> recurser;
    recurser = [&](Node* node) {
      for (auto& child: node->children) {
        recurser(child);
      }
      posts.push_back(node->val);
    };
    recurser(root);
    return posts;
  }
};