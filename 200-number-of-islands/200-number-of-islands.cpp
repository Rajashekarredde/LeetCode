class Solution {
public: 
    void solve( vector< vector<char> >&grid, int i, int j, int row, int col )
    {
        if( i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1' )
            return ;
        
        grid[i][j] = '2';
        
        int d_row[] = {1, 0, -1, 0};
        int d_col[] = {0, 1, 0, -1};
        
        for( int k = 0; k < 4; k++ )
            solve( grid, d_row[k] + i, d_col[k]+j, row, col );
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for( int i = 0; i<n; i++ )
        {
            for( int j = 0; j<m; j++ )
            {
                if( grid[i][j] == '1' )
                {
                    count++;
                    solve( grid, i, j, n, m );
                }
            }
        }
        return count;
    }
};