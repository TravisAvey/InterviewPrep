// Linked List class
public class LinkedList<T>
{
    private int size;
    private Node head;
    private Node tail;

    // constructor
    public LinkedList()
    {
        // initialize values
        this.size = 0;
        this.head = null;
        this.tail = null;
    }

    public LinkedList(T data)
    {
        this.size = 1;
        this.head = new Node(data, null);
        this.tail = this.head;
    }

    // returns the size of the linked list
    public int size() { return this.size; }

    // returns true if the list is empty, false if not empty
    public boolean isEmpty() { return this.head == null; }

    // returns the front node's data from the linked list
    public T front() { return (T) this.head.getData(); }

    // returns the back node's data from the linked list
    public T back() { return (T) this.tail.getData(); }

    // pushes a new node to front of the linked list
    public void pushFront(T data)
    {
        // increment the size
        this.size++;

        // create a node pointer
        Node<T> ptr = new Node<>(data, null);

        // set the next node pointer to what the head is pointing at
        ptr.setNext(this.head);

        // point the head to this node
        this.head = ptr;
    }

    // removes the front node and retuns its value
    public T popFront()
    {
        // get the value of the head's node
        T data = (T) head.getData();

        // set the head to the head's next node
        this.head = this.head.getNext();

        // decrement the size of the linked list
        this.size--;

        return data;
    }

    // pushes a new node to the back of the linked list
    public void pushBack(T data)
    {
        // increment the linked list by one
        this.size++;
        // create a new node with the data
        Node<T> ptr = new Node<>(data, null);

        // if this list is empty
        if (this.head == null)
        {
            // point the head to the new node
            head = ptr;
            // set the new nodes->next to null
            this.tail = this.head;
        }
        // else not empty, add to end of list
        else
        {
            // set the tail's next to this Node
            this.tail.setNext(ptr);
            // point the tail to this Node
            this.tail = ptr;
        }
    }

    // this method removes the last item from the
    // linked list and returns that value
    public T popBack()
    {

        // grab the value from the last item
        T data = (T) this.tail.getData();

        // create a node pointer; point at the head
        Node ptr = this.head;

        // traverse to the node pointing to the tail
        while (ptr.getNext() != this.tail)
            ptr = ptr.getNext();

        // make the last point to null
        ptr.setNext(null);

        // set the tail to the new last item
        this.tail.setNext(ptr);
        this.tail = ptr;
        // decrement the size of the linked list
        this.size--;

        return data;
    }

    // returns the value at the index
    public T valueAt(int index)
    {
        // create a pointer at the head
        Node ptr = this.head;

        // traverse the list
        for (int i=0;ptr.getNext() != null;i++)
        {
            ptr = ptr.getNext();
            
            // loop until we get the index
            if (i == index)
                break;
        }
        
        // return the value at the index
        // if user supplies out of range,
        // return last in list
        return (T) ptr.getData();
    }

    public void reverse()
    {
        System.out.println("TODO: Implement");

        // head -> 1 -> 2 -> 3 -> 4 -> tail
        // tail <- 1 <- 2 <- 3 <- 4 <- head
        Node ptr = this.head;
    }

    // prints out the linked list as T->T->T
    public void print()
    {
        // if the head is null, print out empty list
        if (this.head == null)
            System.out.println("Empty List");
        // else if only one node, print out that one data
        else if (this.head.getNext() == null)
            System.out.println(this.head.getData());
        // else we have at least 2 nodes
        else
        {
            // print out the first
            System.out.print(this.head.getData() + "->");
            // create a node pointer at the next node
            Node ptr = this.head.getNext();

            // traverse the list; while the next is not null
            while (ptr.getNext() != null)
            {
                // print out the current node's data
                System.out.print(ptr.getData() + "->");
                // move to the next node
                ptr = ptr.getNext();
            }
            // print out the last node's data and a new line
            System.out.print(ptr.getData() + "\n");
        }
    }


}

// Node structure
class Node <T>
{
    
    private T data;     // The data of the node
    private Node next;  // The next node of current

    // constructor
    public Node()
    {
        next = null;
    }

    // constructor
    Node(T data, Node node)
    {
        this.data = data;
        this.next = node;
    }

    void setNext(Node node)
    {
        next = node;
    }

    // sets the data of the node
    void setData(T data)
    {
        this.data = data;
    }

    // returns the next node of current
    Node getNext()
    {
        return this.next;
    }

    // returns the data of current node
    T getData()
    {
        return this.data;
    }
}

