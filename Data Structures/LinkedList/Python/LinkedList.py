from Node import Node

class LinkedList:

    def __init__(self):
        self.head = None

    def add(self, data):
        node = Node(data)
        if self.head == None:
            self.head = node
        else:
            node.nextNode = self.head
            self.head = node

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


# test:
list = LinkedList()

list.add(12)
list.add(1)
list.add(99)
if list.search(99):
    print("{} is in the list".format(99))
if not list.search(100):
    print("{} is not in the list".format(100))

print(list)
