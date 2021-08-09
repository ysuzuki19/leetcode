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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int idx = 0;
    function<void(TreeNode*, int, int)> builder;
    builder = [&](TreeNode* node, int low, int high){
      if( idx == preorder.size() ) return;
      if( low < preorder[idx] && preorder[idx] < node->val ){
        node->left = new TreeNode(preorder[idx++]);
        builder(node->left, low, node->val);
      }
      if( idx == preorder.size() ) return;
      if( node->val < preorder[idx] && preorder[idx] < high ){
        node->right = new TreeNode(preorder[idx++]);
        builder(node->right, node->val, high);
      }
    };
    TreeNode* root = new TreeNode(preorder[idx++]);
    builder(root, INT_MIN, INT_MAX);
    return root;
  }
};