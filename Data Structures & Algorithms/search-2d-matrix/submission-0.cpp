class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Identify the row containing the element using binary search of the row
        int TOP = 0;
        int BOTTOM = matrix.size()-1;
        int cMax = matrix[0].size();
        int MID = -1;
        while(TOP <= BOTTOM)
        {
            MID = (TOP + BOTTOM) / 2;
            if(target > matrix[MID][cMax-1])
                TOP = MID+1;
            else if(target < matrix[MID][0])
                BOTTOM = MID-1;
            else
                break;
        }
        if(TOP > BOTTOM)
            return false;
        int s = 0;
        int e = cMax-1;

        while(s <= e)
        {
            int mid = (s + e) / 2;
            if(target > matrix[MID][mid])
                s = mid+1;
            else if(target < matrix[MID][mid])
                e = mid-1;
            else 
                return true;
        }
        return false;



    }
};
