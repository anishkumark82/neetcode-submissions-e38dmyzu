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
    ListNode* _mergeDivide(vector<ListNode*>& lists, int s, int e)
    {
        if( e < s)
            return nullptr;
        if(e == s)
            return lists[s];

        int m = (e+s)/2;
        ListNode *left = _mergeDivide(lists, s, m);
        ListNode *right = _mergeDivide(lists, m+1, e);
        return merge2Lists(left, right);
        
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        return _mergeDivide(lists, 0, lists.size()-1);
    }
};
