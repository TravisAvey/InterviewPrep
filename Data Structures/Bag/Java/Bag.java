import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * This class is an ADT like queue, Vector, or Stack
 * But the Bag ADT doesn't keep track of order nor
 * does it allow for removal of items
 */
public class Bag<T> implements Iterable<T> {
    
    private Node<T> first;  // the first item
    private int N;          // the count

    /**
     * Private helper class that keeps
     * the Bag ADT as a linked list
     * @param <T> generic type
     */
    private static class Node<T> {
        private T item;
        private Node<T> next;
    }

    /**
     * Public constructor
     * initiates all necessary
     * values
     */
    public Bag() {
        first = null;
        N = 0;
    }

    /**
     * This method
     * @return true if bag is empty
     */
    public boolean isEmpty() {
        return first == null;
    }

    /**
     * This method will
     * @return the number of elements in bag
     */
    public int size() {
        return N;
    }

    /**
     * This method will add the item
     * @param item to add to bag
     */
    public void add(T item) {
        // cache the old first node
        Node<T> old = first;
        // create a new node for the first
        first = new Node<T>();
        // set the param item as first's item
        first.item = item;
        // set first's next to old (old is now second)
        first.next = old;
        // increment the count
        N++;
    }

    /**
     * @return the iterator to be used in looping, etc
     */
    @Override
    public Iterator<T> iterator() {
        return new BagIterator<T>(first);
    }

    /**
     * Private helper class for iterating over the elements
     * inside the Bag ADT
     * @param <T>
     */
    private class BagIterator<T> implements Iterator<T> {

        private Node<T> current;    // The current node

        /**
         * constructor
         * @param first node in the bag
         */
        public BagIterator(Node<T> first) {
            current = first;
        }

        /**
         * @return true if there is a next in bag
         */
        @Override
        public boolean hasNext() {
            return current != null;
        }

        /**
         * @return the next item in the bag
         */
        @Override
        public T next() {
            // if no next, throw exception
            if (!hasNext()) throw new NoSuchElementException();
            // get the current item
            T item = current.item;
            // move to next node
            current = current.next;
            // return the item
            return item;
        }

        /**
         * Not supported in this Bag ADT
         */
        @Override
        public void remove() {
            // remove items from bag not supported
            throw new UnsupportedOperationException();
        }
    }
}