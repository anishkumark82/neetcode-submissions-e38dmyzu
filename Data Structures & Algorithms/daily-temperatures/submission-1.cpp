class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // next greatest problem
        // monotonic stack
        // store the index of the next highest temperature
        stack<int> monoS;
        vector<int> out(temperatures.size(), 0);
        for(int i = temperatures.size()-1; i >=0; --i)
        {
            while(!monoS.empty() && temperatures[monoS.top()] <= temperatures[i])
                monoS.pop();

            out[i] = (monoS.empty()) ? 0 : monoS.top()-i;
            monoS.push(i);
        }
        return out;
    }
};
