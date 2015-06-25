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
    public TreeNode invertTree(TreeNode root) {
        if(root == null){
            return null;
        }
        if(root.left == null){
            root.left = root.right;
            root.right = null;
        }else if(root.right == null){
            root.right = root.left;
            root.left = null;
        }else{
            TreeNode temp = root.left;
            root.left = root.right;
            root.right = temp;
        }
        
        invertTree(root.left);
        invertTree(root.right);
      
        return root;
    }
}
