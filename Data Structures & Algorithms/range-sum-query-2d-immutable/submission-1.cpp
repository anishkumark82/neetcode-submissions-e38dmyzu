class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rMax = matrix.size();
        int cMax = matrix[0].size();
        preSum.resize(rMax+1,vector<int>(cMax+1, 0));
        
        for(auto r = 0; r < rMax; ++r)
        {
            int prefix = 0;
            for(auto c = 0; c < cMax; ++c)
            {
                prefix += matrix[r][c];
                preSum[r+1][c+1] = prefix + preSum[r][c+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // match the preSum array
        row1++;
        col1++;
        row2++;
        col2++;
        
        int above = preSum[row1 - 1][col2];
        int left = preSum[row2][col1-1];

        return preSum[row2][col2] - above - left+ preSum[row1-1][col1-1];
    }
    vector<vector<int>> preSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */