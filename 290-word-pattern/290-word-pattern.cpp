class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        string a;
        vector< string > store;
        
        unordered_map< char, string > temp;
        unordered_map< string, bool > visited;

        
        for( int i =0; i<s.size(); ++i )
        {
            if( s[i] ==  ' ' )
            {
                store.push_back( a );
                a.clear();
            }
            else
                a.push_back( s[i] );
        }
        store.push_back( a );
        
        int m = pattern.length();
        int n = store.size();
        
        if( m != n ) return false;
        
        for( int i =0; i<store.size(); ++i )
        {
            if( temp.find( pattern[i] ) == temp.end() && 
                visited[ store[i] ] == false )
            {
                temp[ pattern[i] ] = store[i];
                visited[ store[i] ] = true;
            }
            
            if( temp[ pattern[i]] != store[i] )
                return false;
        }
        return true;
    }
};