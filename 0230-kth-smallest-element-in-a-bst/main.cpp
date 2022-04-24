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
  tuple<TreeNode*, int> helper(TreeNode* root, int k) {
    if (!root) return { nullptr, k };
    TreeNode* node;
    int next;
    tie(node, next) = helper(root->left, k);
    if (!node) {
      if (next == 1) return { root, 0 };
      else return helper(root->right, next - 1);
    } else {
      return { node, 0 };
    }
  }
public:
  int kthSmallest(TreeNode* root, int k) {
    return get<0>(helper(root, k))->val;
  }
};