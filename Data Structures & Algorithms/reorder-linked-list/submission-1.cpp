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

class Solution {
public:
    // head=[2,4,6,8]
    //.            f
    //.        s  
    //       l1 - 2->4
    //       l2 - 8->6
    //        l3-     
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return;
        ListNode *fast = head->next; // to take care of even nodes.
        ListNode *slow = head;
        while(fast != nullptr && fast->next != nullptr)
        { 
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse list from next node of slow
        ListNode *prev = nullptr;
        ListNode *second = slow->next;
        slow->next = nullptr;

        while(second != nullptr)
        {
            ListNode *next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // merge 2 linklist
        ListNode* first = head;
        second = prev;
        while(second != nullptr)
        {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};