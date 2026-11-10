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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head;
        for(auto i = 1; i <= n; ++i)
            front = front->next;

        ListNode *prev = nullptr;
        ListNode *slow = head;        
        while(front != nullptr)
        {
            front = front->next;
            prev = slow;
            slow = slow->next;
        }

        // Slow will be the node to be deleted
        if(prev == nullptr)
            head = slow->next;
        else
            prev->next = slow->next;
        delete slow;
        return head;
    }
};
