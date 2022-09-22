class Trie {
public:
    
    struct node
    {
        node *child[26];
        bool isEnd = false;
    };
    
    node *root;
    
    Trie() 
    {
        root = new node();
    }
    
    void insert(string word) 
    {
        node *cur = root;
        for( auto it : word )
        {
            int i = it - 'a';
            if( cur->child[i] == nullptr )
                cur->child[i] = new node();
            cur = cur->child[i];
        }
        cur->isEnd = true;
    }
    
    bool solve( string &word, int idx, node *cur )
    {
        if( idx == word.size() ) return cur->isEnd;
        
        int i = word[idx] - 'a';
        if( cur->child[i] && solve( word, idx+1, cur->child[i] ) )
            return true;
        
        return false;
    }
    
    bool start( string &word, int idx, node *cur )
    {
        if( idx == word.size() )
        {
            return true;
        }
        
        int i = word[idx] - 'a';
        if( cur->child[i] && start( word, idx+1, cur->child[i] ) )
            return true;
        
        return false;
    }
    
    bool search(string word) 
    {
        return solve( word, 0, root );
    }
    
    bool startsWith(string prefix) 
    {
         return start( prefix, 0, root );
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */