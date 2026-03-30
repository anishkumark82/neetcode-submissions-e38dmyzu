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
// recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        if(head->next == nullptr) // reached the last node
            return head; // this will be the new head
        
        ListNode *newHead = reverseList(head->next); 
        // on backtracking
        head->next->next = head; // set the next nodes next as current node
        head->next = nullptr;

        return newHead;
    }
};
