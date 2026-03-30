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
        // take a dummy node
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        int val = INT_MAX;
        int idx = -1;
        do
        {
            for(auto i = 0; i < lists.size(); ++i)
            {
                if(lists[i] == nullptr)
                    continue;
                if(lists[i]->val < val)
                {
                    val = lists[i]->val;
                    idx = i;
                }
            }
            if(idx != -1)
            {
                tail->next = lists[idx];
                lists[idx] = lists[idx]->next;
                tail = tail->next;
            }
            else
                break;
            idx = -1;
            val = INT_MAX;
        }while(1);
        return dummy->next;
    }
};
