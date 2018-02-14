public class BinaryTree<T extends Comparable<T>> {

    private int N;          // count of items in tree
    private Node<T> root;   // the root of the tree

    /**
     * The constructor
     *  initialize the private variables
     */
    public BinaryTree() {
        N = 0;
        root = null;
    }

    /**
     * This method inserts a new node
     * into the tree
     * @param item, the value to input into the tree
     */
    public void insert(T item) {
        // call private method to insert node
        root = insert(root, item);
        // increment the count of items in tree
        N++;
    }

    /**
     * This is the private method to handle inserting
     * a new node into the tree
     * @param node the current node (recursive)
     * @param item the value to input into tree
     * @return the node
     */
    private Node<T> insert(Node<T> node, T item) {
        // if current node is null
        if (node == null) {
            // return the new node with value
            return newNode(item);
        }

        // if item is less than current data
        if (item.compareTo(node.data) < 0)
            // insert to the left
            node.left = insert(node.left, item);
        // else the item is greater
        else if (item.compareTo(node.data) > 0)
            // insert to the right
            node.right = insert(node.right, item);
        // finally return the node
        return node;
    }

    /**
     * Private helper method to create
     * a new node
     * @param item value for new node
     * @return the new node
     */
    private Node<T> newNode(T item) {
        // initialize a new node
        Node<T> node = new Node<T>();
        // set the value
        node.data =item;
        // set left and right to null
        node.left = node.right = null;
        // return the new node
        return node;
    }

    /**
     * @return the size of nodes in the tree
     */
    public int size() { return N; }


    /**
     * Public interface to the height of the tree
     * @return the height of the tree
     */
    public int height() { return height(root);}

    /**
     * Private method to hanlde calculating
     * the height of the tree
     * @param node current node (recursive)
     * @return the height of the tree
     */
    private int height(Node<T> node) {
        // if the node is null, return 0
        if (node == null) return 0;
        else
            // get the max of the recursive calls of left and right side
            // we are getting the height of the tree, the most is the height
            // add one for the root
            return 1 + Math.max(height(node.left), height(node.right));
    }

    /**
     * Public interface to find the item
     * in the tree
     * @param item trying to find
     * @return true if in tree
     */
    public boolean find(T item) {
        return find(root, item);
    }

    /**
     * Private method to find the item in tree
     * @param node root node
     * @param item item searching for
     * @return true if found
     */
    private boolean find(Node<T> node, T item) {
        // if node is null, not in tree
        if (node == null) return false;
        
        // traverse tree as long as not null
        while (node != null) {
            // if we found, return true
            if (item == node.data) return true;
            // if less than, go left
            else if (item.compareTo(node.data) < 0)
                node = node.left;
            // otherwise, greater and go right
            else
                node = node.right;
        }
        // fall out of while loop, not in tree return false
        return false;
    }

    /**
     * Public method to traverse the tree in order
     */
    public void inOrderTraversal() {
        // call private method on root
        inOrderTraversal(root);
        // output new line
        System.out.println();
    }

    /**
     * Private method to traverse the tree in order
     * @param node current node
     */
    private void inOrderTraversal(Node<T> node) {
        // if node not null
        if (node != null) {
            // traverse to the left
            inOrderTraversal(node.left);
            // output the data and a space
            System.out.print(node.data + " ");
            // traverse to the right
            inOrderTraversal(node.right);
        }
    }

    /**
     * Public method for post order traversal
     */
    public void postOrderTraversal() {
        // call private method on root
        postOrderTraversal(root);
        // output new line
        System.out.println();
    }

    /**
     * Private method for post order traversal
     * @param node current node
     */
    private void postOrderTraversal(Node<T> node) {
        // if node isn't null
        if (node != null) {
            // traverse left and right, then output data
            postOrderTraversal(node.left);
            postOrderTraversal(node.right);
            System.out.print(node.data + " ");
        }
    }

    /**
     * Public method for pre order traversal
     */
    public void preOrderTraversal() {
        // call private method on the root
        preOrderTraversal(root);
        // output new line
        System.out.println();
    }

    /**
     * Private method for pre order traversal
     * @param node current node
     */
    private void preOrderTraversal(Node<T> node) {
        // if node isn't null
        if (node != null) {
            // output the data first, then traverse left and right
            System.out.print(node.data + " ");
            preOrderTraversal(node.left);
            preOrderTraversal(node.right);
        }
    }


    /**
     * Helper class Node with generic type
     * @param <T>
     */
    private class Node<T extends Comparable<T>> implements Comparable<T> {
        
        T data;         // the data
        Node<T> left;   // left node pointer
        Node<T> right;  // right node pointer

        /**
         * Helper method to compare the param
         * and current data
         * @param t data comparing to current
         * @return -1, 0, 1 depending on equality
         */
        @Override
        public int compareTo(T t) {
            return this.data.compareTo(t);
        }
    }
}

