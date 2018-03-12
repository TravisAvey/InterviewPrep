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
    
    def push_back(self, data):
        node = Node(data)
        current = self.head

        while current.nextNode != None:
            current = current.nextNode
        
        current.nextNode = node
        self.size += 1

    def front(self):
        if self.head == None:
            return None
        return self.head.data

    def back(self):
        if self.head == None:
            return None
        current = self.head
        while current.nextNode != None:
            current = current.nextNode
        return current.data

    def pop_back(self):
        if self.head == None:
            return None

        current = self.head
        prev = current
        while current.nextNode != None:
            prev = current
            current = current.nextNode
        self.size -= 1
        value = current.data
        prev.nextNode = None
        return value

    def pop_front(self):
        if self.head == None:
            return None
        value = self.head.data
        self.head = self.head.nextNode
        self.size -= 1
        return value
        
        

    
    def is_empty(self):
        return self.size == 0

    def front(self):
        if self.head != None:
            return self.head.data

    def length(self):
        return self.size

    def search(self, key):
        current = self.head
        if current != None:
            while current.nextNode != None:
                if (current.data == key):
                    return True
                current = current.nextNode
            if current.data == key:
                return True
        return False

    def __str__(self):
        string = ""
        current = self.head
        if current != None:
            while current.nextNode != None:
                string += str(current.data) + "->"
                current = current.nextNode
            string += str(current.data)
        return string


# testing methods:
list = LinkedList()
if list.is_empty():
    print("List is empty!")
list.push_front(12)
print("{}".format(list.front()))
list.push_front(1)
list.push_front(99)
list.push_back(100)
list.push_back(77)
print("No. items in list {}".format(list.length()))
print("back: {}".format(list.back()))
print("front: {}".format(list.front()))
print("poping back {}".format(list.pop_back()))
print(list)
print("poping front: {}".format(list.pop_front()))
print(list)
print("list size {}".format(list.length()))
