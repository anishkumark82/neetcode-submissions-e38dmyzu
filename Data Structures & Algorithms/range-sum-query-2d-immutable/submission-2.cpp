class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sumMat.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for(auto r = 1; r <= matrix.size(); ++r)
        {
            vector<int> preSum(matrix[0].size()+1, 0);
            for(auto c = 1; c <= matrix[0].size(); ++c)
            {
                preSum[c] = preSum[c-1] + matrix[r-1][c-1];
                sumMat[r][c] = preSum[c] + sumMat[r-1][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r1 = row1+1;
        int c1 = col1+1;
        int r2 = row2+1;
        int c2 = col2+1;

        int above = sumMat[r1-1][c2];        
        int below = sumMat[r2][c1-1];
        int topLeft = sumMat[r1-1][c1-1];
        return sumMat[r2][c2] - above - below + topLeft;
    }
    vector<vector<int>> sumMat;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */