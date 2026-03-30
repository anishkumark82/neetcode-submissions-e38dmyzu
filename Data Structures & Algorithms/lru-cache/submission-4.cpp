class ListNode {
public:
    ListNode(): key(-1), val(-1), next(nullptr), prev(nullptr){}
    ListNode(int k, int v, ListNode* np = nullptr, ListNode* pp = nullptr): key(k), val(v), next(np), prev(pp){}
public:
    int key; // for reverse access on LRU full
    int val;
    ListNode *next;
    ListNode *prev;
};

class LRUCache {
private:
    ListNode *insertNode(int key, int val)
    {
        ListNode *node = new ListNode(key, val);

        if(head == nullptr) // List is empty
        {
            head = node;
            tail = node;
            return node;
        }

        tail->next = node;
        node->prev = tail;
        tail = node;
        return node;
    }
    void updateNode(ListNode* node, int val)
    {
        node->val = val;
        // Move it to the tail
        if(head == tail || node == tail) // Only one node
            return;
        
        if(node->prev == nullptr) // node is head
            head = head->next;
        else
            node->prev->next = node->next;

        if(node->next) // will take care of the head node use case
            node->next->prev = node->prev;

        node->next = nullptr;

        tail->next = node;
        node->prev = tail;

        tail = node;
        return;
    }
    int deleteLRUNode()
    {
        int key = head->key;
        ListNode *tmp = head;
        head = head->next;
        if(head == nullptr)
            tail = nullptr;
        else 
            head->prev = nullptr;

        delete tmp;
        
        return key;
    }

public:
    LRUCache(int capacity) {
        mCapacity = capacity;
        mKeys.clear();
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(mKeys.find(key) == mKeys.end())
            return -1;
        updateNode(mKeys[key], mKeys[key]->val);
        return mKeys[key]->val;
    }
    
    void put(int key, int value) {
        if(mKeys.find(key) != mKeys.end())
        {
            updateNode(mKeys[key], value);
            return;
        }

        if(mKeys.size() == mCapacity)
        {
            int delKey = deleteLRUNode();
            mKeys.erase(delKey);
        }

        mKeys[key] = insertNode(key, value);
    }

    int mCapacity;
    unordered_map<int, ListNode *>mKeys;
    ListNode *head;
    ListNode *tail;
};
