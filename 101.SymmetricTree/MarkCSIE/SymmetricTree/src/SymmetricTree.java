
import java.util.ArrayList;
import java.util.List;

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class SymmetricTree {

    public static void main(String[] args) {
        SymmetricTree test = new SymmetricTree();

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

        System.out.println(test.isSymmetric(root3));
    }

    public boolean isSymmetric(TreeNode root) {
        List<TreeNode> nodes = new ArrayList<>();
        if (root != null) {
            nodes.add(root.left);
            nodes.add(root.right);
        }
        while (!nodes.isEmpty()) {
            List<TreeNode> nextNodes = new ArrayList<>();
            int length = nodes.size();
            for (int j = 0; j < length; j++) {
                TreeNode rightNode = nodes.get(j);
                if (j >= length / 2) {
                    TreeNode leftNode = nodes.get(length - j - 1);
                    if ((leftNode == null && rightNode != null) || (leftNode != null && rightNode == null)) {
                        return false;
                    } else if (leftNode != null && rightNode != null && leftNode.val != rightNode.val) {
                        return false;
                    }
                }
                if (rightNode != null) {
                    nextNodes.add(rightNode.left);
                    nextNodes.add(rightNode.right);
                }
            }
            nodes = nextNodes;
        }
        return true;
    }
}
