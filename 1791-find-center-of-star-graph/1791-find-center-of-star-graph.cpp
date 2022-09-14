class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        unordered_map< int, int> mp;
        int n = edges.size();
        for( int i = 0; i<n; ++i )
        {
            for( int j = 0; j<2; j++ )
            {
                if( mp.find( edges[i][j] ) == mp.end() )
                    mp[edges[i][j]] = 1;
                else
                    mp[ edges[i][j]]++;
            }
        }
        
        for( auto it: mp )
        {
            if( it.second == n )
                return it.first;
        }
        return 0;
    }
};