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
  TreeNode* buildSubTree(
    std::vector<int>::const_iterator preorder_first, std::vector<int>::const_iterator preorder_last,
    std::vector<int>::const_iterator inorder_first, std::vector<int>::const_iterator inorder_last) {
    vector<int> sub_preorder (preorder_first, preorder_last);
    vector<int> sub_inorder (inorder_first, inorder_last);
    return buildTree (sub_preorder, sub_inorder);
  }
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty () || inorder.empty ()) return nullptr;
    
    int root_val = preorder[0];
    auto pos = find (begin (inorder), end (inorder), root_val) - begin (inorder);

    return new TreeNode (
      root_val,
      buildSubTree(
        begin (preorder) + 1, begin (preorder) + 1 + pos,
        begin (inorder), begin (inorder) + pos),
      buildSubTree (
        begin (preorder) + pos + 1, end (preorder),
        begin (inorder) + pos + 1, end (inorder))
    );
  }
};