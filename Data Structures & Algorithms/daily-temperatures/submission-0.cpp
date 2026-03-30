class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int,int>> monoS;

        for(int i = temperatures.size()-1; i >= 0; --i)
        {
            int cur = temperatures[i];
            while(!monoS.empty() && monoS.top().first <= cur)
                monoS.pop();

            result[i] = (monoS.empty()) ? 0 : monoS.top().second - i;
            monoS.push({cur, i});
        }
        return result;
    }
};
