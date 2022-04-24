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
  bool isCousins(TreeNode* root, int x, int y) {
    queue<TreeNode*> onTask;
    onTask.push(root);

    auto hasXY = [&](TreeNode* node){
      if(node->left == nullptr) return false;
      if(node->right == nullptr) return false;
      if(node->left->val==x && node->right->val==y) return true;
      if(node->left->val==y && node->right->val==x) return true;
      return false;
    };

    while( !onTask.empty() ){
      queue<TreeNode*> buf(onTask);

      bool hasX = false;
      bool hasY = false;
      while( !onTask.empty() ){
        if( onTask.front()->val == x ) hasX = true;
        if( onTask.front()->val == y ) hasY = true;
        onTask.pop();
      }
      if( hasX && hasY ) return true;

      while( !buf.empty() ){
        auto node = buf.front();
        if( hasXY(node) ) return false;
        if(node->left != nullptr) onTask.push(node->left);
        if(node->right != nullptr) onTask.push(node->right);
        buf.pop();
      }

    }
    return false;
  }
};