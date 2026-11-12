struct ListNode{
    int key;
    int val;
    ListNode *next;
    ListNode *prev;

    ListNode():key(0),val(0), next(nullptr), prev(nullptr){};
    ListNode(int k, int v):key(k), val(v), next(nullptr), prev(nullptr){};
};
// ["LRUCache", [2], "put", [1, 1], "put", [2, 2], "get", [1], "put", [3, 3], "get", [2], "put", [4, 4], "get", [1], "get", [3], "get", [4]]
// List  {1,1}     
//       head 
//       tail        
// cache - [1, Node{1, 1}], [3, Node{3, 3}]
// capacity - 2
// size = 1
class LRUCache {
private:
    ListNode* insertNode(int key, int val)
    {
        ListNode *node = new ListNode(key, val);
        if(head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
        return node;
    }

    void accessNode(ListNode *node)
    {
        if(node == head) // already in front, also handles list of max size 1
            return;
        
        node->prev->next = node->next;
        if(node->next == nullptr) // tail
            tail = tail->prev;
        else
            node->next->prev = node->prev;

        node->next = head;
        head->prev = node;
        head = node;
        node->prev = nullptr;
    }

    // returns the key of the node to be deleted
    int deleteLRU()
    {
        ListNode *tmp = tail;
        tail = tail->prev;
        if(tail)
            tail->next = nullptr;
        else
            head = nullptr;
        
        int ret = tmp->key;
        delete tmp;
        return ret;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!cache.count(key))    
            return -1;
        
        accessNode(cache[key]);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        // check if key is already there
        if(cache.count(key))
        {
            cache[key]->val = value;
            accessNode(cache[key]);
            return;
        }
        // Check if cache is full
        if(cache.size() == capacity)
        {
            int dKey = deleteLRU();
            cache.erase(dKey);
        }    
        cache[key] = insertNode(key, value);
    }
    ListNode *head{nullptr};
    ListNode *tail{nullptr};
    unordered_map<int, ListNode *> cache;
    int capacity;
};
