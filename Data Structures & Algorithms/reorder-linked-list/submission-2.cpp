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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;

        ListNode *fast = head->next;
        ListNode *slow = head;
        // Reach the middle of the list
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        } 

        // Split into 2 list and reverse the second list
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;

        // Reverse second Linklist
        while(second != nullptr)
        {
            ListNode *next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        second = prev; // reversed list
        ListNode *first = head;

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
