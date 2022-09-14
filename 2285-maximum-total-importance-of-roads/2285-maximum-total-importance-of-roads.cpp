class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        vector< int >adj[n];
        int len = roads.size();
        for( int i = 0; i<len; i++ )
        {
            adj[ roads[i][0] ].push_back( roads[i][1] );
            adj[ roads[i][1] ].push_back( roads[i][0] );
        }
        
        vector<int> store; 
        for(auto i:adj)
        {
            int size=i.size();
            store.push_back(size);
        }
        
        sort( store.begin(), store.end(),  greater<int>() );
        long long dis = n;
        long long sum = 0;
        for( auto it: store )
        {
            sum += ( it * dis );
            dis--;
        }
        return sum;
    }
};