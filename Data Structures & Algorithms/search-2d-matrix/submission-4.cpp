class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target < matrix[0][0] || target > matrix.back().back())
            return false;

        int l = 0;
        int h = matrix.size()-1;
        int result = -1;
        while(l <= h)
        {
            int m = (l + h) / 2;
            if(matrix[m][0] == target)
                return true;
            if(matrix[m][0] < target)
            {
                result = m;
                l = m+1;
            }
            else
                h = m-1;
        }
        
        l = 0; 
        h = matrix[0].size()-1;
        while(l <= h)
        {
            int m = (l + h) / 2;
            if(matrix[result][m] == target)
                return true;
            else if(matrix[result][m] > target)
                h = m-1;
            else
                l = m+1;
        } 
        return false;
    }
};
