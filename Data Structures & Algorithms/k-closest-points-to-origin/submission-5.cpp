class Solution {
public:
    int partition(vector<pair<int,int>>&dPair, int low, int high)
    {
        int pivot = dPair[high].first;
        int left = low;

        for(auto i = low; i < high; ++i)
        {
            if(dPair[i].first < pivot)
            {
                swap(dPair[i], dPair[left]);
                left++;
            }
        }
        swap(dPair[left], dPair[high]);
        return left;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>> dPair(points.size());
        for(auto i = 0; i < points.size(); ++i)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1]; 
            dPair[i] = {dist, i};
        }

        int p = -1;
        int low = 0;
        int high = dPair.size()-1;
        while(p != k - 1)
        {
            p = partition(dPair, low, high);
            if(p == k - 1)
                break;
            else if(p > k - 1)
                high = p-1;
            else
                low = p+1;
        }
        vector<vector<int>> out;
        for(auto i = 0; i < k; ++i)
            out.push_back(points[dPair[i].second]);
        return out;
    }
};
