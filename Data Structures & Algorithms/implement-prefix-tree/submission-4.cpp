struct TrieNode
{
    vector<TrieNode *> chMap{26,nullptr};
    bool endWord{false};
    // use default constructor and destructor
};
class PrefixTree {
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto itr = root;
        for(auto &ch : word)
        {
            if(itr->chMap[ch-'a'] == nullptr)
                itr->chMap[ch-'a'] = new TrieNode();
            itr = itr->chMap[ch-'a'];
        }
        itr->endWord = true;        
    }
    
    bool search(string word) {
        auto itr = root;
        for(auto &ch : word)
        {
            if(itr->chMap[ch-'a'] == nullptr)
                return false;
            itr = itr->chMap[ch-'a'];
        }
        return itr->endWord;
    }
    
    bool startsWith(string prefix) {
        auto itr = root;
        for(auto &ch : prefix)
        {
            if(itr->chMap[ch-'a'] == nullptr)
                return false;
            itr = itr->chMap[ch-'a'];
        }
        return true;
    }
    TrieNode *root;
};
