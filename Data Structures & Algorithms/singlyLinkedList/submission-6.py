class ListNode:
    def __init__(self):
        self.value = 0;
        self.next = None
    def __init__(self, value, next_node = None):
        self.value = value
        self.next = next_node

class LinkedList:
    
    def __init__(self):
        self.head = None
        self.tail = None
    
    def get(self, index: int) -> int:
        tmp = self.head
        i = 0
        while i < index and tmp != None:
            tmp = tmp.next
            i += 1
        
        return tmp.value if tmp != None else -1

    def insertHead(self, val: int) -> None:
        node = ListNode(val)
        node.next = self.head
        if self.head == None:
            self.tail = node
        self.head = node

    def insertTail(self, val: int) -> None:
        # Empty list
        if self.tail == None:
            return self.insertHead(val)
        
        node = ListNode(val)
        self.tail.next = node
        self.tail = node


    def remove(self, index: int) -> bool:
        cur = self.head
        prev = None
        i = 0
        while i < index and cur != None:
            prev = cur
            cur = cur.next
            i += 1
        
        if cur == None:
            return False

        if prev == None: #head node
            if self.head == None:
                self.tail = None
            self.head = self.head.next
        else :
            prev.next = cur.next

        if cur == self.tail: # change the tail
            self.tail = prev

        return True

    def getValues(self) -> List[int]:
        out = []
        tmp = self.head
        while tmp:
            out.append(tmp.value)
            tmp = tmp.next
        return out
