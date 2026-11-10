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
    // [1->2->3->4]
    //             f
    //        s
    //     p  
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head;
        for(auto i = 1; i <= n; ++i)
            front = front->next;
        
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while(front != nullptr)
        {
            front = front->next;
            prev = slow;
            slow = slow->next;
        }

        if(prev == nullptr)
            head = slow->next;
        else
            prev->next = slow->next;
        
        delete slow;

        return head;
    }
};
