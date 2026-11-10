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
        ListNode *dummy = new ListNode(0);
        ListNode *l3 = dummy;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            ListNode *tmp = new ListNode(sum % 10);
            carry = sum / 10;
            l3->next = tmp;
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }
        while(l1)
        {
            int sum = l1->val + carry;
            ListNode *tmp = new ListNode(sum % 10);
            l3->next = tmp;
            carry = sum / 10;
            l1 = l1->next;
            l3 = l3->next;
        }

        while(l2)
        {
            int sum = l2->val + carry;
            ListNode *tmp = new ListNode(sum % 10);
            l3->next = tmp;
            carry = sum / 10;
            l2 = l2->next;
            l3 = l3->next;
        }

        if(carry)
        {
            ListNode *tmp = new ListNode(carry % 10);
            l3->next = tmp;
            l3 = l3->next;
        }
        l3 = dummy->next;
        delete dummy;
        return l3;
    }
};
