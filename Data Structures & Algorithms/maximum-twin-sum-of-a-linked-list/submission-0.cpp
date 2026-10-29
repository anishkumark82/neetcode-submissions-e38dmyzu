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
    int pairSum(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr;
        // head=[  5->4->2->1 ]
        //         s
        //         f
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        int maxSum = 0;
        // slow pointer will reach the n/2 + 1 th node -- prev i
        while(prev != nullptr && slow != nullptr)
        {
            maxSum = max(maxSum, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }
        return maxSum;

    }
};