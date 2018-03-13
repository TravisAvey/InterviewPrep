
class Stack:

    def __init__(self):
        self.stack = []
        self.top = -1
        self.size = 0
    

    def push(self, data):
        self.top += 1
        self.size += 1
        self.stack[self.top] = data

    def pop(self):
        value = self.stack[self.top]
        self.top -= 1
        self.size -= 1
        return value
    
    def peek(self):
        return self.stack[self.top]

    def is_empty(self):
        return self.top == -1

    def length(self):
        return self.size
