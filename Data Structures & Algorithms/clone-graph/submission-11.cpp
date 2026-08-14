/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        
        // Old to new Node mapping
        unordered_map<Node*, Node*> cloneMap;
        // Node* node is an adjList
        queue<Node *> Q;
        Q.push(node);
        unordered_set<int> visited; // Do i need this ????
        visited.insert(node->val);

        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                Node *n = Q.front();
                Q.pop();
                if(!cloneMap.count(n))
                    cloneMap[n] = new Node(n->val); 
                
                for(auto &nbr : n->neighbors)
                {
                    if(!cloneMap.count(nbr))
                        cloneMap[nbr] = new Node(nbr->val);
                    cloneMap[n]->neighbors.push_back(cloneMap[nbr]);

                    if(!visited.count(nbr->val))
                    {
                        Q.push(nbr);
                        visited.insert(nbr->val);
                    }
                }
            }
        }
        return cloneMap[node];
    }
};
