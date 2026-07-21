class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>scores;
        for(auto &op : operations)
        {
            if(op == "+")
            {
                int s2 = scores.back();
                int s1 = *(scores.rbegin()+1);
                scores.push_back(s1+s2);
            }
            else if (op == "D")
                scores.push_back(scores.back() * 2);
            else if (op == "C")
                scores.pop_back();
            else
                scores.push_back(stoi(op));
        }
        int sum = accumulate(scores.begin(), scores.end(), 0);
        return sum;
    }
};