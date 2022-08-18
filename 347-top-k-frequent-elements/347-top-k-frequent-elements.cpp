class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map< int, int> store;
        for( int i = 0; i<nums.size(); ++i )
        {
            if( store.find( nums[i] ) == store.end() )
                store[ nums[i] ] = 1;
            else
                store[ nums[i] ]++;
        }
        
        priority_queue< pair<int, int> > pq;
        
        for( auto it : store )
        {
           pq.push({it.second, it.first} );
        }
        
        int i =0;
        vector<int> ans;
        while( i < k )
        {
            ans.push_back( pq.top().second );
            pq.pop();
            i++;
        }
        return ans;
    }
};