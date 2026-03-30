struct ListNode{
    int key;
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int k, int v): key(k), val(v), next(nullptr), prev(nullptr){}
};

//["LRUCache", [2], "put", [1, 1], "put", [2, 2], "get", [1], "put", [3, 3], "get", [2], "put", [4, 4], "get", [1], "get", [3], "get", [4]]
// List:   [1,1]->[2,2]
// head = [1,1]
// tail = [2,2]
// hashMap:[1 :[1,1], 2:[2,2], ]
// capacity = 2

class LRUCache {
public:
    ListNode *createNode(int key, int val)
    {
        return new ListNode(key, val);
    }
    void insertNode(ListNode *node)
    {
        if(head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void updateNode(ListNode *n)
    {
        if(tail == n)
            return;

        if(head == n)
            head = head->next;

        if(n->prev)
            n->prev->next = n->next;
        if(n->next)
            n->next->prev = n->prev;
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    int deleteLRU()
    {
        int ret = -1;
        // Always tail deletion
        ListNode *n = head;
        ret = n->key;
        head = head->next;
        if(head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete n;
        return ret;
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(hashMap.find(key) == hashMap.end())    
            return -1;
        int ret = hashMap[key]->val;
        updateNode(hashMap[key]);
        return ret;
    }
    
    void put(int key, int value) {
        // Check if it is an update
        if(hashMap.find(key) != hashMap.end())
        {
            // update the value in the link list
            hashMap[key]->val = value;
            updateNode(hashMap[key]);
        }
        else
        {
            if(hashMap.size() == capacity)
            {
                int delKey = deleteLRU();
                hashMap.erase(delKey);
            }
            // Create a new Node and hashmap update
            ListNode *node = createNode(key, value);
            insertNode(node);
            hashMap[key] = node;
        }
    }
    unordered_map<int, ListNode *> hashMap;
    int capacity;
    // Take care of link list
    ListNode *head;
    ListNode *tail;
};
