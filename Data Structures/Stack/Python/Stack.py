
'''
    Stack ADT
    Last In First Out
'''
class Stack:
    
    # constructor
    def __init__(self):
        # init the stack
        self.stack = []
        self.top = -1
    
    # This method pushes an item
    # to the top of the stack
    def push(self, data):
        # increment the top
        self.top += 1
        # add item to top of stack
        self.stack.append(data)

    # This method pops an item
    # from the top of the stack
    def pop(self):
        # if top isn't -1
        if self.top >= 0:
            # store the value
            value = self.stack[self.top]
            # decrement the top
            self.top -= 1
            # remove the value
            return value
        # if top is below 0, stack is empty
        # return error statement
        return "The Stack is empty!"
    
    # This method returns the top item
    # from the stack without removing it
    def peek(self):
        return self.stack[self.top]

    # This method checks if the stack 
    # is empty, returns true if top is -1
    def is_empty(self):
        return self.top == -1
    
    # returns the length of the stack
    def length(self):
        return len(self.stack)

# Testing
stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
print("pop:", stack.pop())
print("length:", stack.length())
print("pop", stack.pop())
print("peek", stack.peek())
print("pop", stack.pop())
print("pop", stack.pop())
print("empty", stack.is_empty())
stack.push(4)
stack.push(7)
print("empty", stack.is_empty())