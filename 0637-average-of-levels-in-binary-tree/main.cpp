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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> averages;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      double sum_val = 0.0;
      int n = q.size();
      for (int i=n; i; i--) {
        TreeNode* node = q.front();
        q.pop();
        sum_val += node->val;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      averages.push_back(sum_val / n);
    }
    return averages;
  }
};