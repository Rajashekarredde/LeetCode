class Solution 
{
    public :
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {        
        int rows = mat.size();
        int cols = mat[0].size();
        int i =0, j =0, k = 1;
        vector<int> res(rows*cols);
        res[0] = mat[i][j];
        bool dir = true;
        
        while( i != rows - 1 || j != cols - 1)
        {
            if( dir )
            {

                if(  j == cols - 1 )
                {
                    i++; dir = false;
                }
                else if( i == 0 )
                {
                    j++; dir = false;
                }
                else
                {
                    i--; j++;
                }
            }
            else
            {
               
                if( i == rows - 1)
                {
                    j++; dir = true;
                }
                else if( j == 0 )
                {
                    i++; dir = true;
                }
                else
                {
                    i++; j--;
                }
                
            }
            res[k++] = mat[i][j];
        }
        return res;
    }
};