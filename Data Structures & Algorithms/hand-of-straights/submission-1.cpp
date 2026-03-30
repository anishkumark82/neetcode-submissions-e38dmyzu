class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Greedy
        // hand=[1,2,3,3,4,5,6,7]
        //.      i
        //    j=1
        // groupSize = 4
        // 8 % 4 = 0
        // [1:0, 2:0, 3:1, 4:0, 5:1, 6:1, 7:1]
        if(hand.size() % groupSize  != 0) // It should be divisible
            return false;
        
        sort(hand.begin(), hand.end());

        unordered_map<int,int> hMap;
        for(auto i = 0; i < hand.size(); ++i)
            hMap[hand[i]]++;

        int numGps = hand.size() / groupSize;
        int cnt = 0;
        for(auto i = 0; i < hand.size() && cnt != numGps; ++i)
        {
            int cur = hand[i];
            if(hMap[cur] == 0) // Number already part of earlier groups
                continue;
            
            // Determine if it is the left most element
            if(hMap.find(cur-1) == hMap.end() || hMap[cur-1] == 0)
            {
                // Left most element
                for(auto j = cur; j < cur+groupSize; ++j)
                {
                    if(hMap.find(j) != hMap.end() && hMap[j] != 0)
                        hMap[j]--;
                    else
                        return false;
                }
                cnt++;
            }
        }
        return true;
    }
};
