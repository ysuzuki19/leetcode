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
  vector<int> preorder(Node* root) {
    if (!root) return {};
    vector<int> arr (1, root->val);
    for (const auto& child : root->children) {
      vector<int> sub_arr = preorder (child);
      copy (sub_arr.begin (), sub_arr.end (), std::back_inserter (arr));
    }
    return arr;
  }
};