import java.util.Iterator;
import java.util.NoSuchElementException;

/*
    This is the Queue ADT
    Using a linked list instead of a
    circular array
 */
public class Queue<T> implements Iterable<T>{

    private Node<T> first;  // the first in the queue
    private Node<T> last;   // the last in the queue
    private int N;          // the current size of the queue

    // Node ADT for linked list
    private static class Node<T> {
        // the data
        private T item;
        // pointer to next
        private Node<T> next;
    }

    // public constructor
    public Queue() {
        // init all private variables
        first = null;
        last = null;
        N = 0;
    }

    /**
     * This method returns the size of the queue
     * @return current size of the queue
     */
    public int size() {
        return N;
    }

    /**
     *
     * @return true if the queue is empty
     */
    public boolean isEmpty() {
        return first == null;
    }

    /**
     * This method peeks at the front of the queue
     * @return the data item at the front
     */
    public T peek() {
        // if empty, throw error!
        if (isEmpty())
            throw new NoSuchElementException("Queue Underflow!");
        // return the first item
        return first.item;
    }

    /**
     * This method adds an item to the queue
     * @param item of type T, added to back of queue
     */
    public void enQueue(T item) {
        // store the old last node
        Node<T> oldLast = last;
        // set the current last to a new node
        last = new Node<T>();
        // set the current last's item
        last.item = item;
        // set the next to null
        last.next = null;
        // if queue is empty, set first to last
        if (isEmpty())
            first = last;
        else
            // else set the old last point to last
            oldLast.next = last;
        // increment size counter
        N++;
    }

    /**
     * This method removes an item from the
     * front of the queue and returns it
     * @return the item from the back of the queue
     */
    public T deQueue() {
        // if empty, throw error
        if (isEmpty())
            throw new NoSuchElementException("Queue Underflow!");
        // store the item from the front of the queue
        T item = first.item;
        // set the first to the next in line
        first = first.next;
        // decrement size counter
        N--;
        // if we are now empty, set last to null
        if (isEmpty())
            last = null;
        // return the item
        return item;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (T item : this) {
            sb.append(item);
            sb.append(' ');
        }
        return sb.toString();
    }

    @Override
    public Iterator<T> iterator() {
        return new QueueIterator<T>(first);
    }

    /*
        Since implementing Iterator, we provide a private
        class that will allow the user to use a foreach loop
     */
    private class QueueIterator<T> implements Iterator<T> {

        private Node<T> current; // current node for iterating

        // public constructor
        public QueueIterator(Node<T> current) {
            this.current = current;
        }

        /**
         * 
         * @return false if current is null
         */
        @Override
        public boolean hasNext() {
            return current != null;
        }

        /**
         * This method returns the item next
         * in the queue
         * @return item of type T from next node
         */
        @Override
        public T next() {
            if (!hasNext())
                throw new NoSuchElementException();
            T item = current.item;
            current = current.next;
            return item;
        }

        /**
         * Not supporting remove, user must use
         * deQueue(). Throw error
         */
        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }
}