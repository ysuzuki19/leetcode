/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
  public int deepestLeavesSum(TreeNode root) {
    Queue<TreeNode> queue = new LinkedList<TreeNode>();
    queue.add(root);
    
    int sumval = 0;
    
    while(!queue.isEmpty()) {
      int n = queue.size();
      
      sumval = 0;
      while (n != 0) {
        TreeNode node = queue.poll();
        sumval += node.val;
        
        if (node.left != null) queue.add(node.left);
        if (node.right != null) queue.add(node.right);
        
        n--;
      }
    }
    
    return sumval;
    
  }
}