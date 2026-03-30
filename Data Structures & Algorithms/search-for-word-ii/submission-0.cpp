struct TreeNode{
    TreeNode()
    {
        children.clear();
        endWord = false;
    }
    unordered_map<char, TreeNode *> children;
    bool endWord;
};
class WordDict
{
private:
    void _insert(string word)
    {
        TreeNode *temp = head;
        for(auto &ch : word)
        {
            if(temp->children.find(ch) == temp->children.end())
                temp->children[ch] = new TreeNode();
            temp = temp->children[ch];
        }
        temp->endWord = true;
    }
public:
    WordDict()
    {
        head = new TreeNode();
    }
    WordDict(vector<string>& words)
        : WordDict()
    {
        for(auto &word : words)
            _insert(word);
    }

public:
    TreeNode *head;
};

class Solution {
private:
    void _dfs(vector<vector<char>>& board, TreeNode *node, int r, int c, 
              string &curWord, vector<vector<bool>>visited, unordered_set<string> &out)
    {
        if(node->endWord)
            out.insert(curWord);

        bool rInBounds = r >= 0 && r < board.size();
        bool cInBounds = c >= 0 && c < board[0].size();

        if(!rInBounds || !cInBounds)
            return;
        
        if(visited[r][c] == true)
            return;
        
        visited[r][c] = true;
        char ch = board[r][c];
        if(node->children.find(ch) != node->children.end())
        {
            curWord += ch;
            _dfs(board, node->children[ch], r+1, c, curWord, visited, out);
            _dfs(board, node->children[ch], r-1, c, curWord, visited, out);
            _dfs(board, node->children[ch], r, c+1, curWord, visited, out);
            _dfs(board, node->children[ch], r, c-1, curWord, visited, out);
            curWord.pop_back();
        }
        visited[r][c] = false;

    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        WordDict dict(words);
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        unordered_set<string> out;
        for(auto r = 0; r < board.size(); ++r)
            for(auto c = 0; c < board[0].size(); ++c)
            {
                string curWord = "";
                _dfs(board, dict.head, r, c, curWord, visited, out);
            }
        return {out.begin(), out.end()};
    }
};
