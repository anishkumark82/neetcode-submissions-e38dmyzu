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
private:
    Node* _dfs(Node *node, unordered_map<Node *, Node *>& visited)
    {
        if(node == nullptr)
            return nullptr;
        
        if(visited.count(node)) // Already visited
            return visited[node];

        Node *newNode = new Node(node->val);
        visited[node] = newNode;

        for(Node* &n : node->neighbors)
            newNode->neighbors.push_back(_dfs(n, visited));
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node *, Node *> visited;
        return _dfs(node, visited);
    }
};
