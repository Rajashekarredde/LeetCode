/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) 
    {
        if( !root )
            return "";
        
        queue<TreeNode*> q;
        q.push( root );
        string s = "";
        while( !q.empty() )
        {
            int n = q.size();
            for( int i = 0; i<n; ++i )
            {
                TreeNode *temp = q.front();
                q.pop();
                if( temp )
                    s.append( to_string(temp->val)+',' );
                else
                    s.append("#,");
                
                if( temp )
                {
                    q.push( temp->left );
                    q.push( temp->right );
                }
            }
        }
                                     
        return s;
    }

    TreeNode* deserialize(string data) 
    {
        TreeNode *root = nullptr;
        
        if( data.size() == 0 )
            return root;
        
        std::queue< TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        root = new TreeNode( stoi(str) );
        q.push( root );
        while( !q.empty() )
        {
            TreeNode *temp = q.front();
            q.pop();
            
            getline(s, str, ',');
            if( str == "#" )
                temp->left = nullptr;
            else
            {
                TreeNode *left = new TreeNode( stoi(str) );
                q.push( left );
                temp->left = left;
            }
            
            getline(s, str, ',');
            if( str == "#" )
                temp->right = nullptr;
            else
            {
                TreeNode *right = new TreeNode( stoi(str) );
                q.push( right );
                temp->right = right;
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;