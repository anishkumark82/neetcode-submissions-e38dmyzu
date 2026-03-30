struct TrieNode{
    vector<TrieNode *>chMap;
    bool word;
    TrieNode():chMap(26, nullptr), word(false){}
};
class Solution {
public:
    void _constructTrie(vector<string> &words)
    {
        head = new TrieNode();        
        for(auto &word : words)
        {
            auto itr = head;
            for(auto &w : word)
            {
                if(itr->chMap[w-'a'] == nullptr)
                    itr->chMap[w-'a'] = new TrieNode();
                itr = itr->chMap[w-'a'];
            }
            itr->word = true;
        }

    }
    void _dfs(vector<vector<char>> &board, int r, int c, string &cur, unordered_set<string> &sOut, TrieNode* root)
    {
        bool rInBounds = r >= 0 && r < rMax;
        bool cInBounds = c >= 0 && c < cMax;

        if(root->word) // found a match
            sOut.insert(cur);

        if(!rInBounds || !cInBounds)
            return;

        if(visited[r][c])
            return;


        visited[r][c] = true;

        char ch = board[r][c];
        cur.push_back(ch);
        if(root->chMap[ch-'a'] != nullptr)
        {
            //for(auto dr = 0; dr < lMove.size(); ++dr)
            //    for(auto dc = 0; dc < lMove[0].size(); ++dc)
            //        _dfs(board, r+lMove[dr], c+lMove[dc], cur, sOut, root->chMap[ch]);
            _dfs(board, r+1, c, cur, sOut, root->chMap[ch-'a']);
            _dfs(board, r-1, c, cur, sOut, root->chMap[ch-'a']);
            _dfs(board, r, c+1, cur, sOut, root->chMap[ch-'a']);
            _dfs(board, r, c-1, cur, sOut, root->chMap[ch-'a']);
        }
        cur.pop_back();
        visited[r][c]= false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // construct a trie
        _constructTrie(words);
        rMax = board.size();
        cMax = board[0].size();
        visited.resize(rMax, vector<bool>(cMax, false));
        unordered_set<string> sOut;
        string cur;
        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
                _dfs(board, r, c, cur, sOut, head);

        vector<string> out(sOut.begin(), sOut.end());
        return out;
    }
private:
    TrieNode *head;
    int rMax;
    int cMax;
    vector<vector<bool>> visited;
    //vector<vector<int>> lMove = {{-1, 0}, {1, 0}, {0,-1}, {0,1}};
};
