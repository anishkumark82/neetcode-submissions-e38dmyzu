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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* l3 = dummy;
        while(l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            l3->next = new ListNode(sum%10);
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr)
        {
            int sum = l1->val + carry;
            carry = sum/10;
            l3->next = new ListNode(sum%10);
            l3 = l3->next;
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            int sum = l2->val + carry;
            carry = sum/10;
            l3->next = new ListNode(sum%10);
            l3 = l3->next;
            l2 = l2->next;
        }

        if(carry != 0)
            l3->next = new ListNode(carry);

        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};
