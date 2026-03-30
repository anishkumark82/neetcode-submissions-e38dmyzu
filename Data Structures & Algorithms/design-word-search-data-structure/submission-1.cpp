struct TrieNode{
    unordered_map<char, TrieNode*> chMap;
    bool word;
};
class WordDictionary {
public:
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        auto itr = head;
        for(auto &w : word)
        {
            if(itr->chMap.find(w) == itr->chMap.end())
                itr->chMap[w] = new TrieNode();
            itr = itr->chMap[w];
        }
        itr->word = true;
    }
    bool _dfs(TrieNode* root, int i, string& word)
    {
        if(i == word.length())
        {
            if(root->word == true)
                return true;
        }

        if(word[i] != '.')
        {
            if(root->chMap.find(word[i]) != root->chMap.end())
                return _dfs(root->chMap[word[i]], i+1, word);
            else
                return false;
        }
        // Can be any letter
        if(root->chMap.size() == 0) // Assume empty is not acceptable.
            return false;
        
        for(auto itr = root->chMap.begin(); itr != root->chMap.end(); ++itr)
            if(_dfs(itr->second, i+1, word) == true)
                return true;
        return false;    
    }
    bool search(string word) {
        return _dfs(head, 0, word);
    }
    TrieNode *head;
};
