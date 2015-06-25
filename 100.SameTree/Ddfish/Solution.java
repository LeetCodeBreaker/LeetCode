/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
      
      if( p == null && q == null){
          return true;
      }else if(p == null || q == null){
          return false;
      }
      
      if(p.left == null && q.left != null){
          return false;
      }else if(p.left != null && q.left == null){
          return false;
      }
      if(p.val != q.val){
          return false;
      }
      if(p.left != null && !isSameTree(p.left,q.left)){
          return false;
      }
      if(p.right != null && !isSameTree(p.right,q.right)){
          return false;
      }
      
      return true;
    
        
       
    }
}
