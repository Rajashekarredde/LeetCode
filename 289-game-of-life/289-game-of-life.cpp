class Solution {
public:
    
    void gameOfLife(vector<vector<int>>& board) 
    {
        int r = board.size();
        int c = board[0].size();
        int count;
        
        for( int i=0; i<r; ++i )
        {
            for( int j =0; j<c; ++j )
            {
                 count = 0;
                 for( int k=i-1; k<i+2; ++k )
                 {
                    for( int l =j-1; l<j+2; ++l )
                 {
                    if( (k == i && l == j ) || k < 0 || l < 0 ||
                         k == r || l == c )
                         continue;
                     if( board[k][l] == 1 || board[k][l] == 3 )
                         count++;
                  }
                  }
                
                if( board[i][j] )
                {
                     if( count == 2 || count == 3 )
                         board[i][j] = 3;
                }
                else
                {
                    if(count == 3 )
                        board[i][j] = 2;
                }
            }
        }
        
        for( int i=0; i<r; ++i )
        {
            for( int j =0; j<c; ++j )
            {
                if( board[i][j] == 1 )
                   board[i][j] = 0;
                else if( ( board[i][j] == 2 ) || (board[i][j] == 3 ) )
                   board[i][j] = 1;
            }
        }
    }
};