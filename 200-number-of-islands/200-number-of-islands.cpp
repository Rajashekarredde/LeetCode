class Solution {
public:
    void solver( int i, int j, int r, int c, vector< vector<char> >&grid )
    {
        if( i < 0 || i >=r || j < 0 || j >= c || grid[i][j] != '1' )
            return;
        grid[i][j] = '2';
        
        int d_row[] = {1, 0, -1, 0 };
        int d_col[] = {0, 1, 0, -1};
        for( int k = 0; k<4; k++ )
        {
            solver( i+d_row[k], j+d_col[k], r, c, grid );
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<int>q;
        int count = 0;
        
        for( int i = 0; i<n; ++i )
        {
            for( int j = 0; j<m; ++j )
            {
                if( grid[i][j] == '1' )
                {
                   solver(i,j, n, m, grid );
                   count++;
                }
            }
        }
        return count;
    }
};