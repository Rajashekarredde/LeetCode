class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
       unordered_map< char, char> store;
       unordered_map< char, bool> visited; 
       
       int m = s.size();
        
       int n = t.size();
        
        if( m != n ) return false;
        
       for( int i = 0; i<m; ++i )
       {
          if( store.find( s[i]) == store.end() && visited[ t[i] ] == false )
          {
              store[ s[i] ] = t[i];
              visited[ t[i] ] = true;
          }
           
          if( store[ s[i]] != t[i] ) return false; 
       }
       return true;
    }
};