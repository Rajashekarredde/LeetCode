class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        vector< vector<int> >dp( text1.length(), vector<int>( text2.length(), -1 ) );
        return solver( text1, text2, 0, 0, dp );
    }
    
    int solver( string &s, string &t, int i, int j , vector< vector<int> >&dp )
    {
        if( i == s.length() )
            return 0;
        if( j == t.length() )
            return 0;
        
        if( dp[i][j] != -1 )
            return dp[i][j];
        
        int ans = 0;
        if( s[i] == t[j] )
            ans = 1+ solver( s, t, i+1, j+1, dp );
        else
            ans = max( solver( s, t, i, j+1, dp), solver( s, t, i+1, j, dp) );
        
        return dp[i][j] = ans;
    }
       
};