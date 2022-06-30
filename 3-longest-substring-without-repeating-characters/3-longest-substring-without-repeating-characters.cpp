class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
       unordered_set< char > store;
        
        int i =0, j=0, n = s.length();
        int ans =0;
        
        while( j < n )
        {
            if( store.find( s[j] ) == store.end( ) )
            {
                store.insert( s[j++] );
                ans = max( ans, j - i);
            }
            else
            {
                store.erase( s[i++] );
            }
        }
        return ans;
    }
};