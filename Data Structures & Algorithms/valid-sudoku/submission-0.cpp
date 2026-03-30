class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9; // This is hard coded for the board.
        vector<unordered_set<char>> rSet(n);
        vector<unordered_set<char>> cSet(n);
        vector<vector<unordered_set<char>>> rcSet(n/3, vector<unordered_set<char>>(n/3));

        for(auto r = 0; r < n; ++r)
            for(auto c = 0; c < n; ++c)
            {
                if(board[r][c] == '.')
                    continue;

                // Larger rows and columns
                if(rSet[r].find(board[r][c]) != rSet[r].end())
                    return false;
                if(cSet[c].find(board[r][c])!= cSet[c].end())
                    return false;
                
                // Smaller 3x3 rows and columns
                if(rcSet[r/3][c/3].find(board[r][c]) != rcSet[r/3][c/3].end())
                    return false;

                rSet[r].insert(board[r][c]);
                cSet[c].insert(board[r][c]);
                rcSet[r/3][c/3].insert(board[r][c]);
            }
        return true;
    }
};


