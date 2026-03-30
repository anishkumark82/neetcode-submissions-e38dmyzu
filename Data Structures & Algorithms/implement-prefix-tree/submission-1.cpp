struct TrieNode{
    unordered_map<char, TrieNode*> chMap;
    bool word;
    TrieNode(){word = false;}
};

class PrefixTree {
public:
    PrefixTree() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        auto itr = head;
        for(auto &w : word)
        {
            if(itr->chMap.find(w) == itr->chMap.end())
                itr->chMap[w] = new TrieNode();
            itr = itr->chMap[w];
        }
        itr->word = true;
    }
    
    bool search(string word) {
        auto itr = head;
        for(auto &w : word)
        {
            if(itr->chMap.find(w) == itr->chMap.end())
                return false;
            itr = itr->chMap[w];
        }
        return (itr->word);
    }
    
    bool startsWith(string prefix) {
        auto itr = head;
        for(auto &w : prefix)
        {
            if(itr->chMap.find(w) == itr->chMap.end())
                return false;
            itr = itr->chMap[w];
        }
        return true;
    }
    TrieNode *head;
};
