/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Recursive Solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Termination condition
        if(!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *ret = nullptr;
        if(list1->val <= list2->val)
        {
            ret = list1;
            ret->next = mergeTwoLists(list1->next, list2);
        }
        else
        {
            ret = list2;
            ret->next = mergeTwoLists(list1, list2->next);
        }
        return ret;
    }
};
