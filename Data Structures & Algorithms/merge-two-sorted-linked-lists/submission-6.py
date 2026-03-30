# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Recursive Solution
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        # Termination Condition
        if list1 == None:
            return list2
        if list2 == None:
            return list1
        
        ret = None
        if list1.val <= list2.val:
            ret = list1
            ret.next = self.mergeTwoLists(list1.next, list2)
        else:
            ret = list2
            ret.next = self.mergeTwoLists(list1, list2.next)
        
        return ret
