class Solution {
public:
    bool bfs(  vector<vector<int>> graph, vector<int> &color, int node )
    {
        queue<int> q;
        q.push( node );
        color[node] = 1;
     while( !q.empty() )
     {
        int temp = q.front();
        q.pop();
         
        for( auto it : graph[temp] )
        {
            if( color[it] == -1)
            {
                q.push( it );
                color[it] = 1 - color[temp];
            }
            else if( color[it] == color[temp] )
                return false;
        }
      }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> color( n, -1 );
        for( int i = 0; i<n; ++i  )
        {
            if( color[i] == -1 )
            {
                if( !bfs(graph, color, i ) )
                    return false;
            }
        }
        return true;
    }
};