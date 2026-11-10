struct TrieNode{
    vector<TrieNode *> chMap{26, nullptr};
    bool endWord{false};
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto itr = root;
        for(auto &ch: word)
        {
            if(itr->chMap[ch-'a'] == nullptr)
                itr->chMap[ch-'a'] = new TrieNode();
            itr = itr->chMap[ch-'a'];
        }
        itr->endWord = true;
    }
    bool _recursiveSearch(string &word, TrieNode* itr, int i)
    {
        if(i == word.size())
            return itr->endWord;

        auto ch = word[i];
        if(ch != '.')
        {
            if(itr->chMap[ch-'a'] == nullptr)
                return false;
            return _recursiveSearch(word, itr->chMap[ch-'a'], i+1);
        }
        // ch == '.'
        for(auto idx = 0; idx < 26; ++idx)
        {
            if(itr->chMap[idx] != nullptr)
                if(_recursiveSearch(word, itr->chMap[idx], i+1))
                    return true;
        }
        return false;
    }
    bool search(string word) {
        return _recursiveSearch(word, root, 0);        
    }
    TrieNode *root;
};
