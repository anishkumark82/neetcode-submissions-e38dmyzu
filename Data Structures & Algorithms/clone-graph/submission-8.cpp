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
        unordered_map<Node *, Node *> visited;
        queue<Node *>Q;
        Q.push(node);
        Node *newNode = new Node(node->val);
        visited[node] = newNode;

        while(!Q.empty())
        {
            int qSize = Q.size();
            for(auto i = 0; i < qSize; ++i)
            {
                Node *cur = Q.front();
                Q.pop();
                Node *dup = visited[cur];

                // Now add the unvisited neighbors
                for(auto &n : cur->neighbors)
                {
                    if(visited.find(n) == visited.end())
                    {
                        Node *qNode = new Node(n->val);
                        visited[n] = qNode;
                        Q.push(n);
                    }
                    dup->neighbors.push_back(visited[n]);
                }
            }
            
        }
        return newNode;
    }
};
