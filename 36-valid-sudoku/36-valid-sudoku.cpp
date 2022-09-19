class Solution {
public:
    bool isValid( int row, int col, char c, vector< vector<char> >&board )
    {        
        int row_count = 0, col_count = 0, grid_count = 0;
        for( int i =0; i<9; i++ )
        {
            if( c == board[row][i] )
                row_count++;
            
            if( c == board[i][col] )
                col_count++;
            
            if( board[ 3 * (row/3) + i/3 ][3 * (col/3) + i%3] == c )
                grid_count++;
        }
        
        if( row_count != 1 || col_count != 1 || grid_count != 1 )
            return false;
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for( int i = 0; i<9; ++i )
        {
            for( int j = 0; j<9; j++ )
            {
                if( board[i][j] == '.')
                    continue;
                
                if( !isValid(i, j, board[i][j], board ) )
                {
                    return false;
                }
            }
        }
        return true;
    }
};