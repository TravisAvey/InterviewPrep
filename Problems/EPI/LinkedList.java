/**
 * Basic Linked List class using an internal
 * List Node class for each node of linked list
 *
 * This will cover some more of the intermediate
 * algorithms, such as merge sorted linked lists,
 * reversing a sub-linked list, detecting cycles, etc.
 */
public class LinkedList {


    private Node head;

    public LinkedList() {
        head = null;
    }

    public LinkedList(int data) {
        head = new Node(data);
    }

    public int front() {
        return head.getData();
    }

    public void pushFront(int data) {
        Node current = new Node(data);
        current.setNext(head);
        head = current;
    }

    public int popFront() {
        int data = head.getData();

        head = head.getNext();

        return data;
    }

    public void pushBack(int data) {
        Node current = new Node(data);

        if (head == null) {
            head = current;
        } else {
            Node ptr = head;
            while (ptr.getNext() != null) {
                ptr = ptr.getNext();
            }

            ptr.setNext(current);
        }
    }

    public void print() {
        // if the head is null, print out empty list
        if (this.head == null)
            System.out.println("Empty List");
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

    // TODO: recreate this method with new implementation... may need to do outside of class? or accept only one list and merge with current object
//    public static ListNode mergeSortedLists(ListNode L1, ListNode L2) {
//        ListNode dummy = new ListNode();
//        ListNode current = dummy;
//
//        while (L1 != null & L2 != null) {
//            if (L1.data <= L2.data) {
//                current.next = L1;
//                L1 = L1.next;
//            } else {
//                current.next = L2;
//                L2 = L2.next;
//            }
//
//            current = current.next;
//        }
//
//        current.next = L1 != null ? L1 : L2;
//        return dummy.next;
//    }
}

class Node {
    private int data;
    private Node next;

    public Node() {
        next = null;
    }

    public Node(int data) {
        this.data = data;
        next = null;
    }

    void setNext(Node node) {
        next = node;
    }

    Node getNext() {
        return next;
    }

    int getData() {
        return data;
    }


}
