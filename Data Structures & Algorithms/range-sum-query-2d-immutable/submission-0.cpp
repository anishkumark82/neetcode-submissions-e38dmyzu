class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rMax = matrix.size();
        int cMax = matrix[0].size();
        rowPreSum.resize(rMax,vector<int>(cMax, 0));

        for(auto r = 0; r < rMax; ++r)
            for(auto c = 0; c < cMax; ++c)
                rowPreSum[r][c] = (c==0) ? matrix[r][c] : matrix[r][c]+rowPreSum[r][c-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int r = row1; r <= row2; ++r)
        {
            int l = (col1 == 0) ? 0 : rowPreSum[r][col1-1];
            sum += (rowPreSum[r][col2] - l);
        }
        return sum;
    }
    vector<vector<int>> rowPreSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */