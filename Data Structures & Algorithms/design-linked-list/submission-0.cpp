struct ListNode{
    int val;
    ListNode *prev;
    ListNode *next;

    ListNode(): val(0), prev(nullptr), next(nullptr){};
    ListNode(int value): val(value), prev(nullptr), next(nullptr){};
};
class MyLinkedList {
public:
    MyLinkedList(): head(nullptr), tail(nullptr) {
    }
    // 0, 1, 2, 3
    int get(int index) {
        // Zero indexed
        ListNode *itr = head;
        for(auto i = 0; i < index && itr != nullptr; ++i)
            itr = itr->next;
        return (itr != nullptr) ? itr->val : -1;
    }
    
    void addAtHead(int val) {
        ListNode *t = new ListNode(val);

        if(head == nullptr)
        {
            head = t;
            tail = head;
            return;
        }
        t->next = head;
        head->prev = t;
        head = t;
    }
    
    void addAtTail(int val) {
        ListNode *t = new ListNode(val);
        if(tail == nullptr)
        {
            head = t;
            tail = head;
            return;
        }
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
    
    void addAtIndex(int index, int val) {
        ListNode *t = head;
        auto i = 0;
        for(; i < index && t != nullptr; ++i)
            t = t->next;
        if(i != index)
            return;
        ListNode *temp = new ListNode(val);

        temp->next = t;
        if(!t)
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        else
        {
            if(t->prev)
                t->prev->next = temp;
            else
                head = temp;
            temp->prev = t->prev;
            t->prev = temp;
        }
    }
    
    void deleteAtIndex(int index) {
        ListNode *t = head;
        auto i = 0;
        for(; i < index && t != nullptr; ++i)
            t = t->next;
        if(t == nullptr)
            return;
        
        ListNode *temp = t;
        if(!t->prev)
            head = head->next;            
        else
            t->prev->next = t->next;

        if(!t->next) // tail node
            tail = tail->prev;
        else
            t->next->prev = t->prev;
        
    }
    ListNode* head;
    ListNode* tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */