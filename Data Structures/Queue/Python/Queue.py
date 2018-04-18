# The queue ADT
# First In / First Out
class Queue:

    # The constructor
    def __init__(self):
        self.queue = []
        self.front = -1
        self.back  = -1
        self.count = 0

    # This method adds an item to the queue
    def enQueue(self, item):
        # if we are empty
        if self.empty():
            # set front and back to 0
            self.back = 0
            self.front = 0
        else:
            # else, increment the back pointer
            self.back += 1
        # add the item to the queue
        self.queue.append(item)
        #increment the count
        self.count += 1
    
    # This method removes an item from the queue
    def deQueue(self):
        # if empty, throw error?
        if self.empty():
            return "The queue is empty"
        # grab item from the front
        item = self.queue[self.front]
        
        # if front and back are equal
        if self.front == self.back:
            # reset the queue (empty)
            self.front = self.back = -1
        else:
            # else, move to next item in the queue
            self.front += 1
        # decrement the count
        self.count -= 1
        # return the item
        return item

    # thie method returns the size of queue
    def size(self):
        return self.count
            
    # this method returns true if empty
    def empty(self):
        return self.back == -1 and self.front == -1
