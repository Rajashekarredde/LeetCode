class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length();
        int ans= 0;
        
        for( int i = 0; i<n; i++ )
        {
            ans += solve( s, i, i );
            ans += solve( s, i, i+1 );
        }
        return ans;
    }
    
    int solve( string s, int l, int r)
    {
        int n = s.length();
        int count = 0;
        while( l >=0 && r < n && s[l] == s[r] )
        {
            count++;
            l--;
            r++;
        }
        return count;
    }
};