/**
 * Basic Linked List class using an internal
 * List Node class for each node of linked list
 *
 * This will cover some more of the intermediate
 * algorithms, such as merge sorted linked lists,
 * reversing a sub-linked list, detecting cycles, etc.
 */
public class LinkedList {


    public static class ListNode {
        int data;
        ListNode next;
    }

    public static ListNode searchList(ListNode node, int key) {
        while (node != null && node.data != key) {
            node = node.next;
        }

        return node;
    }

    public static void insertAfter(ListNode node, ListNode newNode) {
        newNode.next = node.next;
        node.next = newNode;
    }

    public static void deleteList(ListNode node) {
        node.next = node.next.next;
    }

    public static void print(ListNode node) {
        while (node != null) {
            System.out.println(node.data);
            node = node.next;
        }
    }

    public static ListNode mergeSortedLists(ListNode L1, ListNode L2) {
        ListNode dummy = new ListNode();
        ListNode current = dummy;

        while (L1 != null & L2 != null) {
            if (L1.data <= L2.data) {
                current.next = L1;
                L1 = L1.next;
            } else {
                current.next = L2;
                L2 = L2.next;
            }

            current = current.next;
        }

        current.next = L1 != null ? L1 : L2;
        return dummy.next;
    }
}

