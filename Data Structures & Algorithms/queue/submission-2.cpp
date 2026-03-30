class ListNode {
public:
    ListNode():val(0), next(nullptr), prev(nullptr){}
    ListNode(int value):val(value), next(nullptr), prev(nullptr){}
public:
    int val;
    ListNode *next;
    ListNode *prev;
};
class Deque {
public:
    Deque(): head(nullptr), tail(nullptr) {
        
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    void append(int value) {
        // Tail insertion
        ListNode *node = new ListNode(value);
        if(isEmpty())
        {           
            head = node;
            tail = head;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void appendleft(int value) {
        ListNode *node = new ListNode(value);
        // Push at the front
        if(isEmpty())
        {
            head = node;
            tail = head;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    int pop() {
        // Pop at the end
        if(isEmpty())
            return -1;

        int val = tail->val;
        ListNode *tmp = tail;
        tail = tail->prev;
        if(tail)
            tail->next = nullptr;
        else
            head = nullptr;
        //delete tmp;
        return val;
    }

    int popleft() {
        // Pop from the front
        if(isEmpty())
            return -1;
        
        ListNode *tmp = head;
        int val = head->val;
        
        //delete tmp;
        
        head = head->next;

        if(head)
            head->prev = nullptr;
        else
            tail = nullptr;

        return val;
        //return -1;    
    }
    ListNode *head;
    ListNode *tail;    
};
