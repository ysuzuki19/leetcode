/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> nodes;
    if (!root) return nodes;
    queue<TreeNode*> onsearch;
    onsearch.push(root);
    while (!onsearch.empty()) {
      int n = onsearch.size();
      vector<int> level;
      level.reserve(n);
      while (n) {
        auto node = onsearch.front();
        onsearch.pop();
        level.push_back(node->val);
        if (node->left) onsearch.push(node->left);
        if (node->right) onsearch.push(node->right);
        n--;
      }
      nodes.push_back(level);
    }
    return nodes;
  }
};