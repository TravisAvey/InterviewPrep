// TODO: look at making this a generic class
public class Vector
{
    private int size;
    private int length;
    private int[] array;

    // Constructor, with size
    public Vector(int size)
    {
        this.size = size;
        this.array = new int[this.size];
        this.length = 0;

    }

    // default constructor
    public Vector()
    {
        this.array = new int[16];
        this.length = 0;
    }

    // push an item onto the vector
    public void push(int item)
    {
        if (this.length == this.size)
        {
            resize(2);
        }
        this.array[length] = item;
        this.length++;

    }

    // removes last item from vector and returns it
    public int pop()
    {
        int item = array[this.length-1];
        if (this.length > 0)
        {
            this.length--;

            if (this.length < this.size / 4)
                resize(0.5);

            return item;
        }
        else
            return -1;
    }

    public int at(int index)
    {
        if (index >= this.length)
            throw new IndexOutOfBoundsException();
        else
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
    public int find(int item)
    {
        for (int i=0; i<this.length; i++)
        {
            if (this.array[i] == item)
                return i;
        }

        return -1;
    }

    // insert item at the index supplied
    public void insert(int item, int index)
    {
        // if the index is out of range, throw error
        if (index >= this.length)
            throw new IndexOutOfBoundsException();
        else
        {
            // if the current length is the size of array
            // resize the array by a factor of 2
            if (this.length == this.size)
                resize(2);

            // increment the length of the array
            this.length++;

            // everything from index to the right copy
            int[] temp = new int[this.size];

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
    public void prepend(int item)
    {
        insert(item, 0);
    }

    // deletes item at index supplied
    public void delete(int index)
    {
        // from the index supplied, shift vector left
        for (int i=index; i<this.length-1; i++)
            this.array[i] = this.array[i+1];
        // decrement the length of the vector
        this.length--;
    }

    public void remove(int item)
    {
        while (true)
        {
            int i = find(item);
            if (i == -1)
                break;
            delete(i);
        }
    }

    // print out the vector
    public void print()
    {
        for (int i=0;i<this.length;i++)
            System.out.println(this.array[i]);
    }

    // resize the vector by the factor supplied
    // TODO: make sure resizing by 1/2 works!
    private void resize(double factor)
    {
        this.size *= factor;

        int[] temp = this.array.clone();
        this.array = new int[size];
        System.arraycopy(temp, 0, this.array, 0, temp.length);
    }

}
