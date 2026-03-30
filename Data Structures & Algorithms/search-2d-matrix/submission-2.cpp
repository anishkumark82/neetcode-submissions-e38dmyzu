class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Corner case
        int rMax = matrix.size()-1;
        int cMax = matrix[0].size()-1; 
        if ((target < matrix[0][0]) || (target > matrix[rMax][cMax]))
            return false;
        
        int search_row = -1;

        if (target > matrix[rMax][0])
            search_row = rMax;

        else
        {
            int low = 0;
            int high = rMax;

            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(target < matrix[mid][0])
                    high = mid - 1;
                else if(target > matrix[mid][0])
                {
                    if(target < matrix[mid+1][0]) // Check if in the current row..
                    {
                        search_row = mid;
                        break;
                    }
                    low = mid + 1;
                }
                else
                    return true; // Element in the first row
            }
        }

        int low = 0;
        int high = cMax;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if (target < matrix[search_row][mid])
                high = mid - 1;
            else if(matrix[search_row][mid] < target)
                low = mid + 1;
            else
                return true;
        }
        return false;
    }
};
