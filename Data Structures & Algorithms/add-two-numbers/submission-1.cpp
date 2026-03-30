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
        ListNode* dummy = new ListNode(0);
        ListNode* l3 = dummy;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);
            l3->next = temp;
            l3 = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr)
        {
            int sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);
            l3->next = temp;
            l3 = temp;
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            int sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);
            l3->next = temp;
            l3 = temp;
            l2 = l2->next;
        }
        if(carry != 0)
        {
            ListNode *temp = new ListNode(carry);
            l3->next = temp;
            l3 = temp;
        }
        l3 = dummy->next;
        delete dummy;
        return l3;
    }
};
