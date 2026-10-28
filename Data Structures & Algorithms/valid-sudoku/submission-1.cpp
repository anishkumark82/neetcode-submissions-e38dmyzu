class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rSet(9);
        vector<unordered_set<char>> cSet(9);
        vector<vector<unordered_set<char>>> rcSet(3, vector<unordered_set<char>>(3));
        

        for(auto r = 0; r < 9; ++r)
            for(auto c = 0; c < 9; ++c)
            {
                if(board[r][c] < '1' || board[r][c] > '9')
                    continue;
                if(rSet[r].count(board[r][c]) || cSet[c].count(board[r][c]) || rcSet[r/3][c/3].count(board[r][c]))
                    return false;
                rSet[r].insert(board[r][c]);
                cSet[c].insert(board[r][c]);
                rcSet[r/3][c/3].insert(board[r][c]);
            }
        return true;
    }
};
