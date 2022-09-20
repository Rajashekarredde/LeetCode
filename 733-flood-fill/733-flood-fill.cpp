class Solution {
public:
    void dfs( vector<vector<int>>& image, int sr, int sc, int row, int col, int color, int source )
    {
        if( sr < 0 || sr >= row || sc < 0 || sc >= col || image[sr][sc] != source )
            return;
        
        image[sr][sc] = color;
        
        int d_row[] = {1, 0, -1, 0};
        int d_col[] = {0, 1, 0, -1};
        
        for( int i=0; i<4; ++i )
        {
            dfs( image, sr+d_row[i], sc+d_col[i], row, col, color, source );
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if( color == image[sr][sc] )
            return image;
        
        int sourceColor = image[sr][sc];
        int rows = image.size();
        int cols = image[0].size();
        dfs( image, sr, sc, rows, cols, color, sourceColor );
        return image;
    }
};