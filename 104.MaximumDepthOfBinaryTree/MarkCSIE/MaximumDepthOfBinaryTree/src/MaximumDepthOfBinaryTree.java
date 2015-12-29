
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class MaximumDepthOfBinaryTree {

    public static void main(String[] args) {
        MaximumDepthOfBinaryTree test = new MaximumDepthOfBinaryTree();

        TreeNode root3 = new TreeNode(2);
        root3.left = new TreeNode(3);
        root3.right = new TreeNode(3);
        root3.left.left = new TreeNode(4);
        root3.left.right = new TreeNode(5);
        root3.right.left = new TreeNode(5);
        root3.right.right = new TreeNode(4);
        root3.left.right.left = new TreeNode(8);
        root3.left.right.right = new TreeNode(9);
        root3.right.left.left = new TreeNode(9);
        root3.right.left.right = new TreeNode(8);

        System.out.println(test.maxDepth(root3));
    }

    public int maxDepth(TreeNode root) {
        if (root != null) {
            return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
        } else {
            return 0;
        }
    }
}
