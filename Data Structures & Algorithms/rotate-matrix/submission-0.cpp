class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Take a transpose of the matrix 
        for(auto i = 0; i < matrix.size(); ++i)
            for(auto j = i+1; j < matrix[0].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
            
        // then swap the columns across the center line
        for(auto i = 0; i < matrix.size(); ++i)
        {
            int L = 0;
            int R = matrix[0].size()-1;
            while(L < R)
            {
                swap(matrix[i][L], matrix[i][R]);
                ++L;
                --R;
            }
        }
    }
};
