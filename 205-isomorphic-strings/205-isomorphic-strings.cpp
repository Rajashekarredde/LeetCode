class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
       unordered_map< char, char > store;
       unordered_map< char, bool > visited;
        
       for ( int i =0; i< s.size(); ++i)
       {
           if( store.find(s[i]) == store.end() && visited[ t[i] ] == false )
           {
               store[ s[i] ] = t[i];
               visited[ t[i] ] = true;
           }
           else if( store[s[i]] != t[i] )
           {
               return false;
           }
       }
        
        return true;
    }
};