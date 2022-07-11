class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
         vector< int > ans;
         int r =0, c = 0;
         int last_row = matrix.size() - 1;
         int last_col = matrix[0].size() - 1;
         
         while( r <=  last_row && c <= last_col )
         {
             for( int i =c; i<= last_col; ++i  )
                 ans.push_back( matrix[r][i] );
             r++;
             
             for( int i = r; i<= last_row; ++i )
                 ans.push_back( matrix[i][last_col]);
            last_col--;
             
             if( r <= last_row )
             {
                 for( int i = last_col; i>= c; i -- )
                     ans.push_back( matrix[last_row][i]);
                 last_row--;
             }
             
             if( c <= last_col )
             {
                 for( int i = last_row; i>=r; i-- )
                     ans.push_back( matrix[i][c] );
                 c++;
             }
         }
        return ans;
    }
};