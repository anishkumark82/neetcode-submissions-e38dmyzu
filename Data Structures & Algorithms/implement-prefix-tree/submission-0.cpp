struct TreeNode{
    TreeNode()
    {
        charSet.clear();
        endWord = false;
    }
    unordered_map<char, TreeNode *> charSet;
    bool endWord;
    
};
class PrefixTree {
public:
    PrefixTree() {
        head = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode *temp = head;
        for(auto &ch : word)
        {
            if(temp->charSet.find(ch) == temp->charSet.end())
                temp->charSet[ch] = new TreeNode();
            temp = temp->charSet[ch];
        }
        temp->endWord = true;    
    }
    
    bool search(string word) {
        TreeNode *temp = head;
        for(auto &ch : word)
        {
            if(temp->charSet.find(ch) == temp->charSet.end())
                return false;
            temp = temp->charSet[ch];
        }
        return (temp->endWord);
    }
    
    bool startsWith(string prefix) {
        TreeNode *temp = head;
        for(auto &ch : prefix)
        {
            if(temp->charSet.find(ch) == temp->charSet.end())
                return false;
            temp = temp->charSet[ch];
        }
        return true;        
    }
    TreeNode *head;
};
