public class BinaryTree<T extends Comparable<T>> {

    private int N;
    Node<T> root;

    public BinaryTree() {
        N = 0;
        root = null;
    }

    public void insert(T item) {
        root = insert(root, item);
        N++;
    }

    private Node<T> insert(Node<T> node, T item) {
        if (node == null) {
            return newNode(item);
        }

        if (item.compareTo(node.data) < 0)
            node.left = insert(node.left, item);
        else if (item.compareTo(node.data) > 0)
            node.right = insert(node.right, item);

        return node;
    }


    private Node<T> newNode(T item) {
        Node<T> node = new Node<T>();
        node.data =item;
        node.left = node.right = null;

        return node;
    }

    public int size() { return N; }

    // TODO: implement algorithm to find height of tree
    public int height() { return 0;}

    public boolean find(T item) {
        return find(root, item);
    }

    private boolean find(Node<T> node, T item) {
        if (node == null) return false;

        while (node != null) {
            if (item == node.data) return true;
            else if (item.compareTo(node.data) < 0)
                node = node.left;
            else
                node = node.right;
        }
        return false;
    }

    // TODO: this will throw null pointer exception below..
    public T findMax() {
        if (root == null)
            throw new IllegalArgumentException("Cannot be an empty tree");
        return findMax(root);
    }
    // TODO: possibly make this static method out of class
    private T findMax(Node<T> node) {
        T max = null;
        if (node != null) {
            T root = node.data;
            // null pointer exception here
            T left = findMax(node.left);
            T right = findMax(node.right);


            // null pointer exception here
            if (left.compareTo(right) > 0)
                max = left;
            else
                max = right;

            if (root.compareTo(max) > 0)
                max = root;
        }
        return max;
    }

    public void inOrderTraversal() {
        inOrderTraversal(root);
        System.out.println();
    }
    private void inOrderTraversal(Node<T> node) {
        if (node != null) {
            inOrderTraversal(node.left);
            System.out.print(node.data + " ");
            inOrderTraversal(node.right);
        }
    }

    public void postOrderTraversal() {
        postOrderTraversal(root);
        System.out.println();
    }

    private void postOrderTraversal(Node<T> node) {
        if (node != null) {
            postOrderTraversal(node.left);
            postOrderTraversal(node.right);
            System.out.print(node.data + " ");
        }
    }


    public void preOrderTraversal() {
        preOrderTraversal(root);
        System.out.println();
    }

    private void preOrderTraversal(Node<T> node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preOrderTraversal(node.left);
            preOrderTraversal(node.right);
        }
    }


    private class Node<T extends Comparable<T>> implements Comparable<T> {
        T data;
        Node<T> left;
        Node<T> right;

        @Override
        public int compareTo(T t) {
            return this.data.compareTo(t);
        }
    }
}