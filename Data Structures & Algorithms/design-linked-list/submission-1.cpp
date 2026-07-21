struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr){}
    ListNode(int value):val(value), next(nullptr){}
};
class MyLinkedList {
public:
    MyLinkedList(): head(nullptr), tail(nullptr), len(0) {
        
    }
    
    int get(int index) {
        ListNode *itr = head;
        for(auto i = 0; i < index && itr != nullptr; ++i)
            itr = itr->next;
        return (itr != nullptr) ? itr->val : -1;
    }
    
    void addAtHead(int val) {
        ListNode *n = new ListNode(val);
        if(head == nullptr) // empty list 
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
        len++;
    }
    
    void addAtTail(int val) {
        ListNode *n = new ListNode(val);
        if(head == nullptr) // empty List
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        len++;
    }
    
    void addAtIndex(int index, int val) {

        if(index == 0)
            return addAtHead(val);

        if(index == len)
            return addAtTail(val);

        if(index > len)
            return;

        auto itr = head;
        for(auto i = 0; i < index-1; ++i)
            itr = itr->next;
        
        ListNode *n = new ListNode(val);
        n->next = itr->next;
        itr->next = n;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= len)
            return;
        ListNode *tmp;        
        if(index == 0) // delete Head
        {
            tmp = head;
            head = head->next;
            
            if(head == nullptr)
                tail = nullptr;
        }
        else
        {
            auto itr = head;
            for(auto i = 0; i < index-1; ++i)
                itr = itr->next;
            tmp = itr->next;
            itr->next = tmp->next;
            if(tail == tmp)
                tail = itr; 
        }
        delete tmp;
        len--;
    }
private:
    ListNode *head;
    ListNode *tail;
    int len;
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