class ListNode {
public:
    ListNode():
        value(0),
        next(nullptr) 
    {}
    ListNode(int val):
        value(val),
        next(nullptr){} 
public:
    int value;
    ListNode *next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        ListNode *tmp = head;
        for(auto i = 0; i < index && tmp != nullptr; ++i)
            tmp = tmp->next;
        return (tmp != nullptr) ? tmp->value : -1;
    }

    void insertHead(int val) {
        // insert to the front
        ListNode *node = new ListNode(val);
        node->next = head;
        if(head == nullptr)
            tail = node;
        head = node;
        
    }
    
    void insertTail(int val) {
        // insert to the back
        ListNode *node = new ListNode(val);
        // Empty list
        if(tail == nullptr)
            insertHead(val);
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    bool remove(int index) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        for(auto i = 0; i < index && cur != nullptr; ++i)
        {
            prev = cur;
            cur = cur->next;
        }

        if(cur == nullptr)
            return false;
        
        if(prev == nullptr) // cur is head
            head = cur->next;
        else
            prev->next = cur->next;
        
        if(cur == tail) // cur node is tail
            tail = prev;

        delete cur;
        return true;
    }

    vector<int> getValues() {
        ListNode *tmp = head;
        vector<int> out;
        while(tmp != nullptr)
        {  
            out.push_back(tmp->value);
            tmp = tmp->next;
        }
        return out;
    }
    ListNode *head;
    ListNode *tail;
};
