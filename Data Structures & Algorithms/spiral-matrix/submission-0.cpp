enum class eMoves{
    L_R,
    T_B,
    R_L,
    B_T
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        eMoves next = eMoves::L_R; 
        int TOP = 0;
        int BOTTOM = matrix.size()-1;
        int LEFT = 0;
        int RIGHT = matrix[0].size()-1;
        vector<int> out;
        while(TOP <= BOTTOM && LEFT <= RIGHT)
        {
            if(next == eMoves::L_R)
            {   
                for(auto c = LEFT; c <= RIGHT; ++c)
                    out.push_back(matrix[TOP][c]);
                
                TOP++;
                next = eMoves::T_B;
            }
            else if(next == eMoves::T_B)
            {
                for(auto r = TOP; r <= BOTTOM; ++r)
                    out.push_back(matrix[r][RIGHT]);
                
                RIGHT--;
                next = eMoves::R_L;
            }
            else if(next == eMoves::R_L)
            {
                for(int c = RIGHT; c >= LEFT; --c)
                    out.push_back(matrix[BOTTOM][c]);
                
                BOTTOM--;
                next = eMoves::B_T;
            }
            else if(next == eMoves::B_T)
            {
                for(int r = BOTTOM; r >= TOP; --r)
                    out.push_back(matrix[r][LEFT]);

                LEFT++;
                next = eMoves::L_R;
            }
        }
        return out;
    }
};
