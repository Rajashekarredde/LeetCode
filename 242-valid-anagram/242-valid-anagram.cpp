class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        vector < int > store( 256, 0 );
        
        for ( int i = 0; i< s.length(); ++ i )
        {
            store[ s[i] ]++;
        }
        
        for( int i = 0; i< t.length(); ++ i )
        {
            store[ t[i] ]--;
        }
        
        for( int i = 0; i< store.size(); ++ i)
        {
            if( store[i] != 0 )
            {
                return false;
            }
        }
        
        return true;
    }
};