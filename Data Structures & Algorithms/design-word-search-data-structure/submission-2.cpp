struct TrieNode{
    unordered_map<char, TrieNode*> chMap;
    bool word;

    TrieNode(){word = false;};
};
class WordDictionary {
public:
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *t = head;
        for(auto &w : word)
        {
            if(!t->chMap.count(w))
                t->chMap[w] = new TrieNode();
            t = t->chMap[w];
        }
        t->word = true;
    }
    
    bool _searchUtl(TrieNode* t, int i, string& w)
    {
        if(i == w.size())
            return t->word;
        
        if(w[i] == '.')
        {
            for(auto itr = t->chMap.begin(); itr != t->chMap.end(); ++itr)
                if(_searchUtl(itr->second, i+1, w) == true)
                    return true;
        }
        else //(w[i] != '.')
        {
            if(!t->chMap.count(w[i]))
                return false;
            return _searchUtl(t->chMap[w[i]], i+1, w);
        }
        return false;
    }
    bool search(string word) {
        return _searchUtl(head, 0, word); // _dfs
    }
    TrieNode *head;
};
