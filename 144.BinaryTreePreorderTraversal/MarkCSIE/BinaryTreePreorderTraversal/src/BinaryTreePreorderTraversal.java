
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class BinaryTreePreorderTraversal {

    public static void main(String[] args) {
        BinaryTreePreorderTraversal test = new BinaryTreePreorderTraversal();
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(2);
        root1.left.left = new TreeNode(3);
        root1.left.right = new TreeNode(4);
        root1.right.left = new TreeNode(4);
        root1.right.right = new TreeNode(3);

        List<Integer> answer = test.preorderTraversal(root1);
        System.out.println(answer.toString());
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> preorder = new ArrayList<>();
        Deque<TreeNode> nodeStack = new ArrayDeque<>();
        TreeNode currentNode = root;
        while (true) {
            if (currentNode == null) {
                break;
            }
            preorder.add(currentNode.val);

            if (currentNode.right != null) {
                nodeStack.push(currentNode.right);
            }

            if (currentNode.left != null) {
                currentNode = currentNode.left;
            } else if (nodeStack.isEmpty()) {
                break;
            } else {
                currentNode = nodeStack.pop();
            }
        }
        return preorder;
    }

    public List<Integer> preorderTraversalDFS(TreeNode root) {
        List<Integer> preorder = new ArrayList<>();
        if (root != null) {
            preorder.add(root.val);
            if (root.left != null) {
                List<Integer> temp = preorderTraversalDFS(root.left);
                preorder.addAll(temp);
            }
            if (root.right != null) {
                List<Integer> temp = preorderTraversalDFS(root.right);
                preorder.addAll(temp);
            }
        }
        return preorder;
    }
}
