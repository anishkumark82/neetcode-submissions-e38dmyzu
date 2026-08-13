struct ListNode{
    int key;
    int value;
    ListNode *next;
    ListNode *prev;
    ListNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr){}
};

class LRUCache {
private:
    // Newest at the head and oldest at tail
    ListNode *insertNode(int key, int value)
    {
        ListNode *n = new ListNode(key, value);
        if(head == nullptr)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
        return n;
    }
    void updateNode(ListNode *n)
    {
        // move the node to the head
        if(n == head)
            return;
        
        n->prev->next = n->next;
        if(tail == n)
            tail = n->prev;
        else
            n->next->prev = n->prev;
        n->prev = nullptr;
        n->next = head;
        head->prev = n;
        head = n; 
    }    
    void updateNode(ListNode *n, int val)
    {
        n->value = val;
        updateNode(n);
    }

    int deleteNode()
    {
       // remove from the tail 
       int key = tail->key;
       ListNode *t = tail;
        if(head == tail)
        {
            tail = nullptr;
            head = nullptr;
        }
        else
        {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
        delete t;
        return key;
    }

public:
    LRUCache(int capacity) {
        head = nullptr;
        tail = nullptr;
        nMap.clear();
        nC = capacity;
    }
    
    int get(int key) {
        if(nMap.count(key))
        {
            updateNode(nMap[key]);
            return nMap[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(nMap.count(key))
            return updateNode(nMap[key], value);
        if(nMap.size() == nC)
        {
            int dKey = deleteNode();
            nMap.erase(dKey);
        }
        nMap[key] = insertNode(key, value);
    }

    // A double link list
    // a map of key to the node
    ListNode *head;
    ListNode *tail;
    unordered_map<int, ListNode *> nMap;
    int nC;
};
