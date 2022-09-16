class Solution {
public:
int solver( string &a, int i, string &b, int j, vector< vector<int> >&dp )
{
    if( i == a.length() )
        return 0;
    if( j == b.length() )
        return 0;
    
    if( dp[i][j] != -1 )
        return dp[i][j];
    
    int ans = 0;
    if( a[i] == b[j] )
        ans = 1 + solver( a, i+1, b, j+1, dp );
    else
    {
        ans = max( solver( a, i+1, b, j, dp ),
                   solver( a, i, b, j+1, dp ) );
    } 
    return dp[i][j] = ans;
}

int minInsertions(string t) 
{
    string s = t;
    reverse( t.begin(), t.end() );
    int n = s.length();
    vector< vector<int> >dp(n, vector<int>(n, -1) );
    int ans = solver( s, 0, t, 0, dp );
    
    return t.size() - ans;
}
};