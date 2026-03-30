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
        // Use 2 pointer approach
        // find the middle element 
        // break into 2 lists
        // reverse the second list

        // 0->1->2->3->4->5->6

        // 0 1 2 3 4 5 6
        // |           |
        // T->O(n), S->O(n) ? S->O(1)

        // 0->1->2->3->nullptr     4->5->6 --> 6->5->4
        // --->-->-->         
        // ------->---->----->

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *cur = slow->next;
        slow->next = nullptr;
        // reverse the second list
        ListNode *prev = nullptr;
        while(cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // Time to merge the 2 link lists
        fast = prev;
        slow = head;

        while(slow != nullptr && fast != nullptr)
        {
            ListNode *slow2 = slow->next;
            ListNode *fast2 = fast->next;
            slow->next = fast;
            slow = slow2;
            fast->next = slow2;
            fast = fast2;
        }
    }
};
