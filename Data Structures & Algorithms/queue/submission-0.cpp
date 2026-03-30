struct ListNode{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0),next(nullptr), prev(nullptr) {};
    ListNode(int value) : val(value),next(nullptr), prev(nullptr) {};
};
class Deque {
public:
    Deque() {

    }

    bool isEmpty() {
        return (qHead == nullptr);
    }

    void appendleft(int value) {
        ListNode *t = new ListNode(value);
        if(qHead == nullptr)
        {
            qHead = t;
            qTail = t;
        }
        else
        {
            qTail->next = t;
            t->prev = qTail;
            qTail = t;
        }
    }

    void append(int value) {
        ListNode *t = new ListNode(value);
        if(qHead == nullptr)
        {
            qHead = t;
            qTail = t;
        }
        else
        {
            t->next = qHead;
            qHead->prev = t;
            qHead = t;
        }
    }

    int pop() {
        if(qHead == nullptr)
            return -1;
        ListNode *t = qHead;
        int val = t->val;

        qHead = qHead->next;
        delete t;

        if(qHead == nullptr)
            qTail = nullptr; // clear the queue
        else
            qHead->prev = nullptr;
        return val;
    }

    int popleft() {
        if(qTail == nullptr)
            return -1;
        ListNode *t = qTail;
        int val = qTail->val;
        
        qTail = qTail->prev;
        delete t;

        if(qTail == nullptr)
            qHead = nullptr; // clear the queue;
        else
            qTail->next = nullptr;
        return val;
    }
    ListNode *qHead = nullptr;
    ListNode *qTail = nullptr;
};
