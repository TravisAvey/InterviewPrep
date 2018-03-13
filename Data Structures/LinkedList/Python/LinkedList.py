from Node import Node
'''
The linked list class is a collection
of nodes that are linked together in
a list.
'''
class LinkedList:

    # basic constructor
    def __init__(self):
        # point head to none
        self.head = None
        # init size to 0
        self.size = 0

    # this method pushes a new item
    # to the front of the list
    def push_front(self, data):
        # init the node with the data
        node = Node(data)
        # if the head is pointing to none
        if self.head == None:
            # set the head point to new node
            self.head = node
        else:
            # set next node of what head is
            # pointing to
            node.nextNode = self.head
            # point head to node
            self.head = node
        # increment size of linked list
        self.size += 1
    
    # Pushes a new item to the back
    # of the linked list
    def push_back(self, data):
        # init a new node
        node = Node(data)
        # init a pointer to the head
        current = self.head

        # while next node isn't None
        while current.nextNode != None:
            # move to next node
            current = current.nextNode
        # after fall out of loop
        # push last node onto linked list
        current.nextNode = node
        # increment the number of items
        self.size += 1

    # returns the front item from
    # the linked list
    def front(self):
        # if the head is none, return none
        if self.head == None:
            return None
        # return what the head is pointing to
        return self.head.data

    # returns the back item from the
    # linked list
    def back(self):
        # if the head is none, return none
        if self.head == None:
            return None
        # init a pointer to the head
        current = self.head
        # while the next node isn't none
        while current.nextNode != None:
            # traverse to next node
            current = current.nextNode
        # return the last node's data
        return current.data

    # Removes and returns the last item
    # from the linked list
    def pop_back(self):
        # if head is none, return none
        if self.head == None:
            return None
        # init a pointer to the head
        current = self.head
        # init a pointer to current
        prev = current
        # while next isn't none
        while current.nextNode != None:
            # set the prev to current
            prev = current
            # then move current to next
            current = current.nextNode
        # decrement the no. of items
        self.size -= 1
        # cache the data
        value = current.data
        # set the prev's next to none
        prev.nextNode = None
        # return the data
        return value

    # Removes and returns the first item
    # from the linked list
    def pop_front(self):
        # if the head is none, return none
        if self.head == None:
            return None
        # cache the value from first item
        value = self.head.data
        # set the head to head's next
        # essentially removing the first
        # from the list
        self.head = self.head.nextNode
        # decrement the count
        self.size -= 1
        # return the value
        return value
        
    # returns True if empty, false otherwise
    def is_empty(self):
        return self.size == 0

    # returns the length of the
    # linked list
    def length(self):
        return self.size

    # searches the linked list for
    # the key, if found returns True
    def search(self, key):
        # if head is none, nothing in list
        if self.head == None:
            # return false
            return False
        # init a pointer to the head
        current = self.head
        # while the next node isn't none
        while current.nextNode != None:
            # if we found the key, return True
            if current.data == key:
                return True
            # move to next node
            current = current.nextNode
        # after loop check last node for key
        if current.data == key:
            return True
        # if not in list, return false
        return False

    # override __str__ method
    def __str__(self):
        # if empty, return empty string
        if self.head == None:
            return ""
        # init the string
        string = ""
        # set a pointer to the head
        current = self.head
        # while next node isn't none
        while current.nextNode != None:
            # append current and a link to next
            string += str(current.data) + "->"
            # traverse to next node
            current = current.nextNode
        # append last to string
        string += str(current.data)
        # return the string
        return string