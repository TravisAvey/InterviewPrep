public class Vector<T> {
    
    private static final int SIZE = 16;
    private int size;
    private int length;
    private T[] array;

    // default constructor
    public Vector() {
        this.array = (T[]) new Object[SIZE];
        this.length = 0;
    }


    // Constructor, with size
    public Vector(int size) {
        // only if size is greater than 0
        if (size > 0) {
            // set the size, init array and length
            this.size = size;
            this.array = (T[]) new Object[this.size];
            this.length = 0;
        } else {
            // error! can't be less than 1
            System.out.println("Error: size cannot be less than 1");
            throw new ArrayIndexOutOfBoundsException();
        }

    }


    // push an item onto the vector
    public void push(T item) {
        // if we are full, resize array
        if (this.length == this.size) {
            resize(2);
        }
        // set item at current position
        this.array[length] = item;
        // increment to next
        this.length++;

    }

    // removes last item from vector and returns it
    public T pop() {
        // get the last item in vector
        T item = array[this.length-1];
        // as long as length is greater than 0
        if (this.length > 0) {
            // decrement length
            this.length--;
            // if len is less than 1/4 size
            if (this.length < this.size / 4)
                // resize the array
                resize(0.5);
            // return item
            return item;
        }
        else
            // return null, b/c no items
            return null;
    }

    // This method returns the object at the index
    public T at(int index) {
        // if out of range, throw exception
        if (index >= this.length)
            throw new IndexOutOfBoundsException();
        else
            // return the object at the index
            return this.array[index];
    }

    // returns the current length of the vector
    public int length() { return this.length; }

    // returns true if the vector is empty
    public boolean isEmpty() { return this.length == 0; }

    // returns the size of the vector
    public int capacity() { return this.size; }

    /**
     * Method returns the index of the element find
     * @param item, the element to find in the vector
     * @return the index of the item, -1 if not found
     */
    public int find(T item) {
        // loop over the array
        for (int i=0; i<this.length; i++) {
            // if item is current
            if (this.array[i] == item)
                // return the index
                return i;
        }
        // fall off array? return -1 for not found
        return -1;
    }

    // insert item at the index supplied
    public void insert(T item, int index) {
        // if the index is out of range, throw error
        if (index >= this.length)
            throw new IndexOutOfBoundsException();
        else {
            // if the current length is the size of array
            // resize the array by a factor of 2
            if (this.length == this.size)
                resize(2);

            // increment the length of the array
            this.length++;

            // everything from index to the right copy
            T[] temp = (T[]) new Object[this.size];

            // init a pointer j, to start at the index supplied
            int j = index;

            // from the index to end, copy array to temp
            for (int i=0; i<temp.length && j<this.array.length; i++)
                temp[i] = this.array[j++];

            // set the new item to the index
            // then increment the index
            this.array[index++] = item;

            // copy back over
            for (int i=0; index<this.array.length; index++)
                this.array[index] = temp[i++];

        }
    }

    // prepends the vector at index 0 with item supplied
    public void prepend(T item) {
        insert(item, 0);
    }

    // deletes item at index supplied
    public void delete(int index) {
        // from the index supplied, shift vector left
        for (int i=index; i<this.length-1; i++)
            this.array[i] = this.array[i+1];
        // decrement the length of the vector
        this.length--;
    }
    
    // removes the object from the vector
    public void remove(T item) {
        
        // while true ??
        // TODO: is this while loop necessary??
        while (true) {
            // find the item
            int i = find(item);
            // if item is not found, break;
            if (i == -1)
                break;
            // delete the item
            delete(i);
        }
    }

    // print out the vector
    public void print() {
        for (int i=0;i<this.length;i++)
            System.out.println(this.array[i]);
    }

    // resize the vector by the factor supplied
    private void resize(double factor) {
        // multiply the size by factor
        this.size *= factor;
        // create a temp array copying over the current array
        T[] temp = this.array.clone();
        // set array to a new array with new size
        this.array = (T[]) new Object[size];
        // copy the temp array into the this.array with it's new size
        System.arraycopy(temp, 0, this.array, 0, temp.length);
    }

}