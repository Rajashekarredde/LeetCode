class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
         int k = trust.size();

        if( k < n -1 )
             return -1;
         
         vector<int> visited( n +1, 0);
         for( int i =0; i<k; ++i )
         {
             visited[ trust[i][0] ] = -1;
             
             if( visited[ trust[i][1] ] != -1)
             {
                 visited[ trust[i][1] ]++;
             }
         }
        
        k= visited.size();
        for( int i =1; i<k ; ++i )
        {
            if( visited[i] == n- 1) return i;
        }
        
        return -1;
    }
};