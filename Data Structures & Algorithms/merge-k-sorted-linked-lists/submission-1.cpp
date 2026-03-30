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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //lists = [[1,2,4],[1,3,5],[3,6], [4,5]]
        // merge List 1<->2 [1,2,4],[1,3,5], 3<->4 [3,6], [4,5]
        // merge List [1,2,3,4,5] and [3,4,5,6]
        // merge above List [1,2,3,3,4,4,5,5,6] 
        // if their are k lists then the time complexity will be log k * n = nlogk
        int n = lists.size();
        if(n == 0)
            return nullptr;
        while(n > 1)
        {
            for(auto i = 0; i < n / 2; i++)
            {
                lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
            }
            n = (n+1)/2;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if(l1 != nullptr)
            tail->next = l1;
        else if(l2 != nullptr)
            tail->next = l2;

        tail = dummy->next;
        delete dummy;

        return tail;
    }
};
