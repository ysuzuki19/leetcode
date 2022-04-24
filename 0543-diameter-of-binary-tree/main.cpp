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
  int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    function<int(TreeNode*)> recurser;
    recurser = [&recurser, &diameter](TreeNode* node) {
      if (!node) return 0;
      int left = recurser(node->left);
      int right = recurser(node->right);
      diameter = max(diameter, left+right);
      return max(left, right) + 1;
    };
    recurser(root);
    return diameter;
  }
};