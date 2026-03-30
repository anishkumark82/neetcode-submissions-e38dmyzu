struct TreeNode{
    TreeNode()
    {
        children.clear();
        endWord = false;
    }
    unordered_map<char, TreeNode *>children;
    bool endWord;
};
class WordDictionary {
public:
    WordDictionary() {
        head = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode *temp = head;
        for(auto &ch : word)
        {
            if(temp->children.find(ch) == temp->children.end())
                temp->children[ch] = new TreeNode();
            temp = temp->children[ch];
        }
        temp->endWord = true;
    }
    bool searchDFS(int i, string &word, TreeNode *temp)
    {
        if(i == word.size())
            return temp->endWord;
        
        if(temp == nullptr)
            return false;
        char ch = word[i];
        if(ch != '.') 
        {
            if(temp->children.find(ch) != temp->children.end())
                return searchDFS(i+1, word, temp->children[ch]);
        }
        else
        {
            for(auto itr = temp->children.begin(); itr != temp->children.end(); ++itr)
                if(searchDFS(i+1, word, itr->second))
                    return true;
        }
        return false;
    }

    bool search(string word) {
        return searchDFS(0, word, head);
        
    }
private:
    TreeNode *head;
};
