public class BinarySearchTree {
    public static class Node {
        int value;
        Node left, right;

        Node(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    Node root;

    public Node search(Node node, int value) {
        if (node == null || node.value == value) {
            return node;
        }
        if (value < node.value) {
            return search(node.left, value);
        }
        return search(node.right, value);
    }

    public Node insert(int value) {
        root = insertValue(root, value);
        return root;
    }

    public Node insertValue(Node node, int value) {
        if (node == null) {
            node = new Node(value);
            return node;
        }

        if (value < node.value) {
            node.left = insertValue(node.left, value);
        } else {
            node.right = insertValue(node.right, value);
        }

        return  node;
    }

    public void inorderTraversal() {
        inorderTraversal(root);
    }

    private void inorderTraversal(Node root) {
        if (root != null) {
            inorderTraversal(root.left);
            System.out.print(root.value + " ");
            inorderTraversal(root.right);
        }
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();

        bst.insert(50);
        bst.insert(30);
        bst.insert(20);
        bst.insert(40);
        bst.insert(70);
        bst.insert(60);
        bst.insert(80);

        System.out.println("Inorder traversal:");
        bst.inorderTraversal();
    }
}
