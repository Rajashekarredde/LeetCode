class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector< vector<int> >dp(m, vector<int>(n, -1 ) );
        int ans = solver( dp, m, n, 0, 0 );
        return ans;
    }
    
    int solver( vector<vector<int>>&dp, int m, int n, int i, int j )
    {
        if( i == (m-1) && j ==(n-1) )
            return 1;
        else if( i >= m || j >= n )
            return 0;
        
        if( dp[i][j] != -1 )
            return dp[i][j];
        return dp[i][j] = solver( dp, m, n, i+1, j) +  solver( dp, m, n, i, j+1) ;
    }
};