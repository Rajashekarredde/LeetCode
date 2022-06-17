class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<string, char> letters;
        unordered_map<char, bool> visited;
        
        string str;
        vector<string> store;
        
        for( int i = 0; i<s.length(); ++i )
        {
            if( s[i] != ' ' )
                str.push_back( s[i] );
            else
            {
                store.push_back( str );
                str.clear();
            }
        }
        
        store.push_back( str );
     
        const int sSize = pattern.size(); 
        
        if ( sSize != store.size() ) return false;
    
        for (int i = 0; i < sSize; ++i)   
        {               
            if ( letters.find( store[i]) == letters.end() && visited[ pattern[i]] ==                      false)
            {
                letters[store[i]] = pattern[i];
                visited[pattern[i]] = true;
            }
            else if (letters[store[i]] != pattern[i])
            {
                return false;
            }
        }
       return true;
        
    }
};