class Solution {
public:
    
    int solver( string &s1, string &s2, int i, int j, vector< vector<int> >&dp )
    {
        if( i < 0 ) return j + 1;
        if( j < 0 ) return i + 1;
        
        if( dp[i][j] != -1 )
            return dp[i][j];
        
        if( s1[i] == s2[j] ) return dp[i][j] = solver( s1, s2, i-1, j-1, dp );
        else
        {
            return dp[i][j] = 1 + min(  solver(s1, s2, i-1, j, dp),
                             min( solver( s1, s2, i, j-1, dp),
                                  solver( s1, s2, i-1, j-1, dp )));
        }
    }
    
    int minDistance(string s1, string s2) 
    {
        int n = s1.length();
        int m = s2.length();
        vector< vector<int> >dp( n, vector<int>(m, -1));
        return solver( s1, s2, n-1, m-1, dp );
    }
};