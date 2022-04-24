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
  int maxPathSum(TreeNode* root) {
    int maximumPath = INT_MIN;
    auto updateMax = [&maximumPath](int num){
      if(maximumPath < num) maximumPath = num;
    };
    function<int(TreeNode* node)> recurser;
    recurser = [&recurser, &updateMax](TreeNode* node){
      if(!node) return 0;
      updateMax(node->val);
      int leftPath = recurser(node->left);
      int rightPath = recurser(node->right);
      int longerPath = max(leftPath, rightPath);
      if(leftPath>0 && rightPath>0) updateMax(node->val + leftPath + rightPath);
      else updateMax(node->val + longerPath);
      return max(0, node->val + longerPath);
    };
    recurser(root);
    return maximumPath;
  }
};
