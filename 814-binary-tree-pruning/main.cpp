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
  TreeNode* pruneTree(TreeNode* root) {
    if (root->left) root->left = pruneTree(root->left);
    if (root->right) root->right = pruneTree(root->right);
    if (!root->left && !root->right) return root->val? root: nullptr;
    return root;
  }
};