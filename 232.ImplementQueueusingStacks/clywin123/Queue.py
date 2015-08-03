class Queue:
    def __init__(self):
        self.list1 = []
        self.list2 = []
        return
    def push(self, x):
        self.list1.append(x)
        return
    def pop(self):
        if(self.list2):
            self.list2.pop()
            return
        else:
            while(self.list1):
                num = self.list1.pop()
                self.list2.append(num)
            self.list2.pop()
            return
    def peek(self):
        if(self.list2):
            num = self.list2.pop()
            self.list2.append(num)
            return num
        else:
            while(self.list1):
                num = self.list1.pop()
                self.list2.append(num)
            num = self.list2.pop()
            self.list2.append(num)
            return num
        
    def empty(self):
        #if(not self.list1 and not self.list2):
        if(len(self.list1)==0 and len(self.list2)==0):
            return True
        else:
            return False
