import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

public class Heap<T extends Comparable<T>> {

    public enum Type { MAX, MIN };  // Type if Max/Min heap

    private List<T> heap;   // The heap structure to hold heap
    private int count;      // The count of items in heap
    private Type type;      // The type of heap

    /**
     * Default constructor
     * Initialize values
     */
    @SuppressWarnings("unchecked")
    public Heap() {
        heap = new ArrayList<>();
        count = 0;
        type = Type.MAX;
    }

    /**
     * Constructor to set type
     * @param type min or max heap
     */
    public Heap(Type type) {
        this(); // call default constructor first
        this.type = type; // set type
    }


    /**
     * Checks if heap is empty
     * @return true if empty
     */
    public boolean isEmpty() { return count == 0; }

    // No longer in use, because will always return
    // true.. bc array list..
    @Deprecated
    public boolean isFull() { return count == heap.size(); }

    /**
     * Gets the length of the heap
     * @return the length
     */
    public int length() { return count; }

    /**
     * Gets the parent index of passed index
     * @param index of child
     * @return parent index
     */
    private int parent(int index) {
        return (index-1) / 2;
    }

    /**
     * Gets the left child index
     * @param index parent index
     * @return left child index
     */
    private int leftChild(int index) {
        int left = 2 * index + 1;
        if (left >= count)
            return -1;
        return left;
    }

    /**
     * Gets the right child index
     * @param index parent index
     * @return right child index
     */
    private int rightChild(int index) {
        int right = 2 * index + 2;
        if (right >= count)
            return -1;
        return right;
    }

    /**
     * Gets the max of the heap
     * @return the max from heap
     */
    public T getMax() {
        // if empty return null
        if (isEmpty()) return null;
        // if Max heap, return first item
        if (type == Type.MAX)
            return heap.get(0);
        else {
            // get the first value in heap
            T val = heap.get(0);
            // loop through heap and check if greater
            for (int i = 1; i< heap.size(); i++)
                if (val.compareTo(heap.get(i)) < 0)
                    val = heap.get(i);
            // return greatest in heap
            return val;
        }
    }

    /**
     * Method removes the min or max from the heap
     * @return the min/max value
     */
    public T remove() {
        if (count == 0)
            throw new NoSuchElementException("Heap is empty, no values to remove");

        T val = heap.get(0);

        heap.set(0, heap.get(count-1));
        count--;
        // TODO: create a percolate down method for removing
        // the heapify doesn' work properly when removing...
        heapify();
        return val;
    }

    /**
     * Gets the smallest item in heap
     * @return min
     */
    public T getMin() {
        // if empty return null
        if (isEmpty()) return null;

        // if type is min, return first item
        if (type == Type.MIN)
            return heap.get(0);
        else {
            // store first val
            T val = heap.get(0);
            // loop through checking val against all
            // to find smallest value
            for (int i = 1; i< heap.size(); i++)
                if (val.compareTo(heap.get(i)) > 0)
                    val = heap.get(i);
            // return the value
            return val;
        }
    }

    /**
     * This method inserts a value into the heap
     * @param val to insert into heap
     */
    public void insert(T val) {
        // add the value to array list
        heap.add(val);
        // call heapify to put in correct position
        heapify();
        // increment the count in the heap
        count++;
    }

    /**
     * creates string of heap
     * @return string
     */
    @Override
    public String toString() {
        // init a string builder
        StringBuilder sb = new StringBuilder();

        // for each value in heap
        for (T val : heap) {
            // append value
            sb.append(val);
            // append a comma and space
            sb.append(", ");
        }
        //remove the last to chars : ',' and ' '
        sb.setLength(sb.length()-2);
        // return the string
        return sb.toString();
    }

    /**
     * This method sets the heap correctly
     * with the max at the root (if max heap)
     * or the min at the root (if min heap)
     */
    private void heapify() {
        // get the index (last in heap)
        int index = count;
        // if min heap
        if (type == Type.MIN) {
            // while the parent is greater than child, swap
            while(heap.get(parent(index)).compareTo(heap.get(index)) > 0) {
                swap(index, parent(index));
                // set index to parent
                index = parent(index);
            }
        // else, max heap
        } else {
            // while the parent is less than the child, swap
            while (index > 0 && heap.get(parent(index)).compareTo(heap.get(index)) < 0) {

                swap(index, parent(index));
                // set the index to parent
                index = parent(index);

            }
        }
    }

    /**
     * Private helper method to swap values in heap
     * @param aPos index of a
     * @param bPos index of b
     */
    private void swap(int aPos, int bPos) {
        // store a in temp
        T temp = heap.get(aPos);
        // set b at a's index
        heap.set(aPos, heap.get(bPos));
        // set a at b's index
        heap.set(bPos, temp);
    }
}