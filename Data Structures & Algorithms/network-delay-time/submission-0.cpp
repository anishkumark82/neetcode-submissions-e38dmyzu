using PAIRINT = pair<int,int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Djikstra's Algorithm

        vector<vector<PAIRINT>> adjList(n+1); // {dest, dist}
        for(auto &t : times)
            adjList[t[0]].push_back({t[1], t[2]});
        
        vector<int> shortestPath(n+1, -1);
        priority_queue<PAIRINT, vector<PAIRINT>, greater<PAIRINT>> minHeap;
        minHeap.push({0, k});

        while(!minHeap.empty())
        {
            PAIRINT p = minHeap.top();
            minHeap.pop();
            if(shortestPath[p.second] != -1) // already visited
                continue;
            
            shortestPath[p.second] = p.first;
            vector<PAIRINT> &neighbors = adjList[p.second];
            for(auto &neighbor : neighbors)
                minHeap.push({p.first + neighbor.second, neighbor.first});
        }
        int connected = *min_element(shortestPath.begin()+1, shortestPath.end()); 
        int maxTime = *max_element(shortestPath.begin()+1, shortestPath.end());

        return (connected != -1)  ? maxTime : -1;
    }
};
