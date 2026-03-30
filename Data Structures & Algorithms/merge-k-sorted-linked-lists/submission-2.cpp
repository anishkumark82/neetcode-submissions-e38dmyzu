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
private:
    ListNode* merge2Lists(ListNode* l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *l3 = dummy;

        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;

        }
        if(l1 != nullptr)
            l3->next = l1;
        if(l2 != nullptr)
            l3->next = l2;

        l3 = dummy->next;
        delete dummy;

        return l3;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;

        for(int i = 1; i < lists.size(); ++i)
            lists[0] = merge2Lists(lists[0], lists[i]);
        return lists[0];
    }
};
