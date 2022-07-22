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
    Node* cloneGraph(Node* node) 
    {
       unordered_map< Node*, Node*> store;
       if( !node ) return nullptr;
       
        if( node->neighbors.size() == 0 )
        {
            Node * root = new Node(node->val);
            return root;
        }
        return dfs( node, store);
    }
    
    Node * dfs( Node *cur, unordered_map<Node*, Node*> &store )
    {
        vector<Node*> ele;
        Node *clone = new Node( cur->val );
        store[cur] = clone;
        for( auto it : cur->neighbors )
        {
            if( store.find(it) != store.end() )
               ele.push_back( store[it] );
            else
               ele.push_back( dfs(it, store) );
        }
        clone->neighbors = ele;
        return clone;
    }
};