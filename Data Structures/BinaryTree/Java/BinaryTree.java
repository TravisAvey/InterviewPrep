
public class BinaryTree<T extends Comparable<T>> {

    private int N;
    Node<T> root;

    public BinaryTree() {
        N = 0;
        root = null;
    }

    public void insert(T item) {
        root = insert(root, item);
    }

    private Node<T> insert(Node<T> node, T item) {
        if (root == null) {
            return newNode(item);
        }

        if (item.compareTo(node.getT()) < 0)
            node.left = insert(node.left, item);
        else
            node.right = insert(node.right, item);

        return node;
    }


    private Node<T> newNode(T item) {
        Node<T> node = new Node<T>();
        node.data =item;
        node.left = node.right = null;

        return node;
    }


    private class Node<T extends Comparable<T>> implements Comparable<Node <T>> {
        T data;
        Node<T> left;
        Node<T> right;
        public T getT() {
            return this.data;
        }
        @Override
        public int compareTo(Node<T> node) {
            return this.data.compareTo(node.getT());
        }
    }
}