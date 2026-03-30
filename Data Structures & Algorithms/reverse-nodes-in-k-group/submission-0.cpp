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
    ListNode* reverse(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // prevTail = nullptr
        //next = 3->next
        // 3->next = nullptr
        // reverse(3)
        // prevTail = 1;
        // next-> until k
        // reverse(6);
        // prevTail->next = curHead;
        //
        //1->2->3 4->5->6
        //      k

        ListNode* prevTail = nullptr;
        ListNode* curHead = head; // 1
        ListNode* cur = head; // 1
        int cnt = 0;
        while(cur != nullptr)
        {
            cnt++;
            if(cnt == k) // 1 2 3 [4, 5 6]
            {
                ListNode* next = cur->next;
                cur->next = nullptr; // 3-nullptr
                // Return the tail in cur node
                cur = reverse(curHead); // cur now contains the head // 3 // 6

                if(prevTail == nullptr) // 3 is head //
                    head = cur; 
                else
                    prevTail->next = cur; // since it is reversed (now curHead should be the tail. //1->6
                prevTail = curHead; // 4
                cnt = 0; 
                curHead = next; // 4
                cur = next; // 4
            }
            else
                cur = cur->next;
        }

        if(curHead != nullptr)
            prevTail->next = curHead;

        return head;
    }
};
