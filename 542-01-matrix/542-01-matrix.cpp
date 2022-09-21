class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vector< vector<int> >vis(n, vector<int>(m, 0) );
        vector< vector<int> >dis(n, vector<int>(m, 0) );
        queue< pair< pair<int, int>, int > >q;
        for( int i = 0; i<n; i++ )
        {
            for( int j = 0; j<m; j++ )
            {
                if( mat[i][j] == 0 )
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int d_row[] = {1, 0, -1, 0};
        int d_col[] = {0, 1, 0, -1};
        
        while( !q.empty() )
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            dis[r][c] = steps;
            
            for( int k = 0; k<4; k++ )
            {
                int t_r = d_row[k] + r;
                int t_c = d_col[k] + c;
                if( t_r >= 0 && t_r < n && t_c >= 0 && t_c < m && vis[t_r][t_c] != 1 )
                {
                    q.push({{t_r, t_c}, steps+1});
                    vis[t_r][t_c] = 1;
                }
            }
        }
        return dis;
    }
};