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
    Node* _dfs(Node* node)
    {
        if(visited.find(node->val) != visited.end())
            return visited[node->val];
        
        Node* newNode = new Node(node->val);
        visited[node->val] = newNode;
        for(auto i = 0; i < node->neighbors.size(); ++i)
            newNode->neighbors.push_back(_dfs(node->neighbors[i]));
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;
        return _dfs(node);
    }
private:
    unordered_map<int, Node *>visited;

};
