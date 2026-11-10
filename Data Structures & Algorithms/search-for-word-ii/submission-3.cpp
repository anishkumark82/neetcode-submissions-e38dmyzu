struct TrieNode{
    unordered_map<char, TrieNode *> chMap;
    bool endWord{false};
};

class Trie
{
private:
    void insert(string &word)
    {
        auto itr = root;
        for(auto &ch: word)
        {
            if(!itr->chMap.count(ch) )
                itr->chMap[ch] = new TrieNode();
            itr = itr->chMap[ch];
        }
        itr->endWord = true;
    }


public:
    Trie()
    {
        root = new TrieNode();
    }
    void insertAll(vector<string>& words)
    {
        for(auto &word : words)
            insert(word);
    }
    
    TrieNode *root;
};

class Solution {
private:
    void _dfs(vector<vector<char>> & board, int r, int c, TrieNode *root, 
              unordered_set<string> &out, string &cur)
    {
        if(root == nullptr)
            return;

        if(root->endWord == true) // Found a word
            out.insert(cur);

        bool rInBounds = r >=0 && r < board.size(); 
        bool cInBounds = c >= 0 && c < board[0].size();
        if (!rInBounds || !cInBounds)
            return;
        if(board[r][c] == '*') // already visited node
            return;

        char ch = board[r][c];
        board[r][c] = '*';
        if(root->chMap.count(ch))
        {
            cur.push_back(ch);
            _dfs(board, r+1, c,root->chMap[ch], out, cur);
            _dfs(board, r, c+1,root->chMap[ch], out, cur);
            _dfs(board, r-1, c,root->chMap[ch], out, cur);
            _dfs(board, r, c-1,root->chMap[ch], out, cur);
            cur.pop_back();
        }
        board[r][c] = ch;
        return;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> out;
        string cur = "";
        Trie t;
        t.insertAll(words);

        for(auto r = 0; r < board.size(); ++r)
            for(auto c = 0; c < board[0].size(); ++c)
                _dfs(board, r, c, t.root, out, cur);
            
        vector<string> ret{out.begin(), out.end()};
        return ret;
    }
};
