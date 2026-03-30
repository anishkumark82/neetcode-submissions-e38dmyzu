class ListNode {
public:
    ListNode(int k, int v, ListNode *np = nullptr): key(k), val(v), next(np){}

public:
    int key;
    int val;

    ListNode *next;
};

class HashTable {
private:
    int _hashFunc(int key)
    {
        return key % hashTable.size();
    }

    bool insertNode(int key, int val)
    {
        // returns true if new element added else returns false in case of update.

        int hkey = _hashFunc(key);
        ListNode *node = nullptr;
        if(hashTable[hkey] != nullptr) // Check for duplicates
        {
            node = findNode(key);
            if(node != nullptr)
            {
                node->val = val;
                return false;
            }
        }
        
        node = new ListNode(key, val);
        node->next = hashTable[hkey];
        hashTable[hkey] = node;

        return true;
    }

    bool deleteNode(int key)
    {
        int hkey = _hashFunc(key);
        
        ListNode *tmp = hashTable[hkey];
        ListNode *prev = nullptr;
        while(tmp != nullptr && tmp->key != key)
        {
            prev = tmp;
            tmp = tmp->next;
        }

        if(tmp == nullptr)
            return false;

        if (prev == nullptr) // deleting head node
            hashTable[hkey] = tmp->next;
        else 
            prev->next = tmp->next;
        
        delete tmp;
        return true;
    }

    ListNode *findNode(int key)
    {
        int hkey = _hashFunc(key);
        ListNode *tmp = hashTable[hkey];
        
        while(tmp != nullptr && tmp->key != key)
            tmp = tmp->next;

        return tmp;
    }

public:
    HashTable(int capacity) {
        hashTable.resize(capacity, nullptr);
        mEntries = 0;
    }

    void insert(int key, int value) {
        if(insertNode(key, value))
            mEntries++;

        double loadFactor = static_cast<double>(mEntries)/hashTable.size();
        if(loadFactor >= 0.5)
            resize();
    }

    int get(int key) {
        ListNode *tmp = findNode(key);

        return (tmp != nullptr) ? tmp->val : -1;
    }

    bool remove(int key) {
        bool success = deleteNode(key);
        if(success)
            mEntries--;
        return success;
    }

    int getSize() const {
        return mEntries;
    }

    int getCapacity() const {
        return hashTable.size();
    }

    void resize() {
        vector<ListNode *> oldHashTable = hashTable;
        int capacity = oldHashTable.size();
        mEntries = 0;
        hashTable.clear();        
        hashTable.resize(capacity*2, nullptr);

        for(auto i = 0; i < capacity; ++i)
        {
            ListNode *tmp = oldHashTable[i];
            while(tmp != nullptr)
            {
                insertNode(tmp->key, tmp->val);
                mEntries++;
                ListNode *del = tmp;
                tmp = tmp->next;
                delete del;
                
            }
        }
    }

    vector<ListNode *> hashTable;
    int mEntries;
};
