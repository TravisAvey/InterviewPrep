'''
the node class
holds the data of each node
and the address of the next
node in the linked list
'''
class Node:

    def __init__(self, data):
        # the data of the node
        self.data = data
        # address of the next node
        self.nextNode = None

