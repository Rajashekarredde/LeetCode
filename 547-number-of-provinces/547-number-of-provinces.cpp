class Solution {
public:
    void bfs( vector< vector<int> >&graph, int node, vector<int>&visited )
    {
        queue<int> q;
        q.push( node );
        visited[node] = 1;
        while( !q.empty() )
        {
            int temp = q.front();
            q.pop();
            for( auto it : graph[temp] )
            {
                if(!visited[it] )
                {
                    q.push( it);
                    visited[it] = 1;
                }
            }
                
        }
    }
    
    int findCircleNum(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int>visited(n+1, 0);
        vector< vector<int> >grid(n+1);
        
        for( int i = 0; i<n; i++ )
        {
            for( int j = 0; j<graph[i].size(); ++j )
            {
                if( graph[i][j] == 1 && i != j )
                    grid[i+1].push_back( j+1);
            }
        }
        
        int count = 0;        
        for( int i = 1; i<=n; ++i )
        {
            if( !visited[i] )
            {
                bfs( grid, i, visited );
                count++;
            }
        }
        return count;
    }
};