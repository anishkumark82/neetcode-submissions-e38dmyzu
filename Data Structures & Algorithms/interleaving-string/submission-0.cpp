class Solution {
    bool _dfs(int i1, int i2, int i3, string &s1, string &s2, string &s3)
    {
        if(i1 == s1.size() && i2 == s2.size() && i3 == s3.size())
            return true;
            
        bool isTrue = false;
        if(i1 != s1.size() && s1[i1] == s3[i3] && i2 != s2.size() && s2[i2] == s3[i3])
        {
            isTrue = _dfs(i1+1, i2, i3+1, s1, s2, s3);
            if(isTrue)
                return isTrue;
            isTrue = _dfs(i1, i2+1, i3+1, s1, s2, s3);
        }
        else if(i1 != s1.size() && s1[i1] == s3[i3])
            isTrue = _dfs(i1+1, i2, i3+1, s1, s2, s3);
        else if(i2 != s2.size() && s2[i2] == s3[i3])
            isTrue = _dfs(i1, i2+1, i3+1, s1, s2, s3);

        return isTrue;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        return _dfs(0,0, 0, s1, s2, s3);
    }
};
