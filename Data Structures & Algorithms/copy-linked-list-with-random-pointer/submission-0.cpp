/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 2 Pass approach
        Node *dummy = new Node(0);
        Node *nHead = nullptr;

        // first copy over only the next nodes and cache the old and new pointers in a map
        auto temp1 = head;
        auto temp2 = dummy;
        unordered_map<Node *, Node *> nodeMap;
        while(temp1 != nullptr)
        {
            Node *copyN = new Node(temp1->val);
            temp2->next = copyN;
            temp2 = copyN;
            nodeMap[temp1] = temp2;
            temp1 = temp1->next;
        }

        nHead = dummy->next;
        delete dummy;
        temp1 = head;
        temp2 = nHead;

        while(temp1 != nullptr)
        {
            if(temp1->random != nullptr)
                temp2->random = nodeMap[temp1->random];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return nHead;
    }
};
