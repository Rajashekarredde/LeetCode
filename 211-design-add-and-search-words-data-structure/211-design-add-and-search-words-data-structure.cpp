// class WordDictionary 
// {
//     private:
//     unordered_map<  int, vector<string> >store;
    
//     bool isEquals( string &a, string &b )
//     {
//         for( int i = 0; i<a.size(); i++ )
//         {
//             if( b[i] == '.' )
//                 continue;
//             if( a[i] != b[i] )
//                 return false;
//         }
//         return true;
//     }
    
//    public:
//     WordDictionary() {
        
//     }
    
//     void addWord(string word) 
//     {
//         store[ word.size() ].push_back( word );
//     }
    
//     bool search(string word) 
//     {
        
//         for( auto it : store[word.size()] )
//         {
//             if( isEquals( it, word) )
//                 return true;
//         }
//         return false;
//     }
// };


class WordDictionary 
{
   public:
    
    struct trie
    {
        trie *child[26];
        bool isEnd = false;
    };
    
    trie *root;
    
    WordDictionary() 
    {
        root = new trie();
    }
    
    void addWord(string word) 
    {
        trie *cur = root;
        for( auto it : word )
        {
            int i = it - 'a';
            if( cur->child[i] == nullptr )
                cur->child[i] = new trie();
            cur = cur->child[i];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) 
    {
        return isFound( word, 0, root );
    }
    
    bool isFound( string &word, int idx, trie *cur )
    {
        if( idx == word.size() ) return cur->isEnd;
        
        if( word[idx] == '.')
        {
            for( int i = 0; i<26; i++ )
                if( cur->child[i] && isFound( word, idx+1, cur->child[i] ) )
                    return true;
        }
        else
        {
            int i = word[idx] - 'a';
            if( cur->child[i] && isFound( word, idx+1, cur->child[i] ) )
                return true;
        }
        return false;
    }
};



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */