class ListNode:
    def __init__(self, val: int):
        self.value = val
        self.next = None
        self.prev = None
class Deque:
    
    def __init__(self):
        self.head = None
        self.tail = None

    def isEmpty(self) -> bool:
        return True if self.head == None else False

    def append(self, value: int) -> None:
        node = ListNode(value)
        if self.isEmpty(): # Empty list
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node

    def appendleft(self, value: int) -> None:
        node = ListNode(value)
        if self.isEmpty(): #Empty queue        
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node

    def pop(self) -> int:
        if self.isEmpty():
            return -1
        
        ret = self.tail.value
        self.tail = self.tail.prev
        if self.tail:
            self.tail.next = None
        else:
            self.head = None
        return ret

    def popleft(self) -> int:
        if self.isEmpty():
            return -1
        
        ret = self.head.value
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        else:
            self.tail = None
        return ret
