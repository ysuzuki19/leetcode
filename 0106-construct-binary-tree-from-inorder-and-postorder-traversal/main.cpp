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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty()) return nullptr;
    using vi_itr = vector<int>::iterator;
    function<TreeNode*(vi_itr,vi_itr,vi_itr,vi_itr)> builder;
    builder = [&builder](vi_itr in_begin, vi_itr in_end, vi_itr post_begin, vi_itr post_end){
      if( in_begin==in_end ) return (TreeNode*)( nullptr );
      auto node = new TreeNode(*(post_end-1));

      auto in_central = in_begin;
      while( *(in_central) != node->val ) in_central++;
	  
      auto post_central = post_begin + (in_central - in_begin);
	  
      node->left  = builder(in_begin,     in_central, post_begin,   post_central);
      node->right = builder(in_central+1, in_end,     post_central, post_end-1  );
	  
      return node;
    };
    return builder(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
  }
};