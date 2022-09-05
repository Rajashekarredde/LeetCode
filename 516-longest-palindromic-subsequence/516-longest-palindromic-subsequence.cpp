class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        string t = s;
        reverse( t.begin(), t.end() );
        vector< vector<int> >dp( s.length(), vector<int>( t.length(), -1 ) );
        return solve( s, t, 0, 0, dp );
    }
    
    int solve( string &s, string &t, int i, int j, 
                    vector< vector<int> >&dp )
    {
        if( i == s.length() )
            return 0;
        if( j == t.length() )
            return 0;
        if( dp[i][j] != -1 )
            return dp[i][j];
        int ans= 0;
        
        if( s[i] == t[j] )
            ans = 1+ solve( s, t, i+1, j+1, dp );
        else
            ans = max( solve( s, t, i+1, j, dp ), solve( s, t, i, j+1, dp ) );
        
        return dp[i][j] = ans;
    }

};