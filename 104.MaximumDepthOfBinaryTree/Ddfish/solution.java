public class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        
        if(root.left == null && root.right == null){
            return 1;
        }
        int left = 0;
        int right = 0;
        if (root.left != null){
            left = maxDepth(root.left) +1 ;
        }
        if (root.right != null){
            right = maxDepth(root.right) +1 ;
        }
        
        if(left > right){
            return left;
        }else{
            return right;
        }
        
    }
}
