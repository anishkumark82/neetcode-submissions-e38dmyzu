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
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        
        ListNode *dummy = new ListNode(0);
        ListNode *l3 = dummy;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            ListNode *tmp = new ListNode(sum % 10);
            l3->next = tmp;
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }

        while(l1 != nullptr)
        {
            int sum = l1->val + carry;
            ListNode *tmp = new ListNode(sum%10);
            carry = sum / 10;
            l3->next = tmp;
            l3 = l3->next;
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            int sum = l2->val + carry;
            ListNode *tmp = new ListNode(sum%10);
            carry = sum / 10;
            l3->next = tmp;
            l3 = l3->next;
            l2 = l2->next;
        }
        if(carry)
        {
            ListNode *tmp = new ListNode(carry);
            l3->next = tmp;
        }

        l3 = dummy->next;
        delete dummy;
        return l3;
    }

};
