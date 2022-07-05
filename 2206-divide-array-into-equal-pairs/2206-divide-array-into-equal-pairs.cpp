class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        unordered_map< int, int> store;
        int count = 0;
        int n = nums.size();
        
        for( int i = 0; i<n; ++i )
        {
            if( store.find( nums[i] ) == store.end() )
                store[ nums[i] ] = 1;
            else
                store[ nums[i] ]++;
        }
        
        for( auto itr = store.begin(); itr != store.end(); ++itr )
        {
            if( itr->second%2 == 0 )
            {
                count += itr->second/2;
            }
        }
        
        if( ( nums.size()/2 ) == count )
            return true ;
        else 
                return false;
    }
};