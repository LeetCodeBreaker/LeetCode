class Stack:
    def __init__(self):
        self.queue = []
    def push(self, x):
        self.queue.append(x)
        return
    def pop(self):
        for i in range(len(self.queue)-1):
            tmp = self.queue.pop(0)
            self.queue.append(tmp)
        self.queue.pop(0)
    def top(self):
        return self.queue[-1]
    def empty(self):
        if(len(self.queue)==0):
            return True
        else:
            return False
