class HashTable {
    // Open addressing 

    // ["HashTable", 2, "getCapacity", insert, 6, 7, "getCapacity", "insert", 1, 2, "getCapacity", "insert", 3, 4, "getCapacity", "getSize"]
private:
    int _hash(int key)
    {
        return key % cap;
    }
    void _insertTable(int key, int value, vector<pair<int,int>> &hTable)
    {
        int h = _hash(key);
        n = n+1;

        while(hTable[h].first != -1)
        {
            h = h+1;
            h = _hash(h);
        }
        hTable[h] = {key, value};
    }
    void _updateValue(int key, int newVal)
    {
        int h = _hash(key);
        while(table[h].first != key)
        {
            h = h+1;
            h = _hash(h);
        }
        table[h].second = newVal; 
    }
public:
    HashTable(int capacity) { // 2
        table.resize(capacity, {-1,-1}); // [{-1,-1}, -1,-1]
        n = 0;
        cap = capacity; // 2
    }
    
    void insert(int key, int value) {
        if(get(key) != -1)
            return _updateValue(key, value);

        if((static_cast<double>(n) + 1) / cap >= 0.5) 
            resize();

        _insertTable(key, value, table);        
    }

    int get(int key) {
        int h = _hash(key);
        int start = h;
        while(table[h].first != key)
        {
            h = h+1;
            h = _hash(h);

            if(table[h].first == -1 || h == start)
                return -1;
        }
        return table[h].second;    
    }

    bool remove(int key) {
        int h = _hash(key);
        int start = h;
        while(table[h].first != key)
        {
            h = h+1;
            h = _hash(h);
            if(table[h].first == -1 || h == start)
                return false;
        }
        table[h] = {-1,-1};
        n = n-1;
        return true;
    }

    int getSize() const {
        return n;
    }

    int getCapacity() const {
        return cap;
    }

    void resize() {
        cap = cap * 2;
        int oldN = n;
        n = 0;
        vector<pair<int,int>> newTab(cap, {-1,-1});
        for(auto i = 0; i < cap/2; ++i)
            if(table[i].first != -1)
                _insertTable(table[i].first, table[i].second, newTab);
        table = std::move(newTab);
    }

    vector<pair<int, int>> table;
    int n;
    int cap;
};
