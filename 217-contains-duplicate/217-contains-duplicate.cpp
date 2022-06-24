class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map< int, int> store;
        int n = nums.size();
        
        for( int i =0; i<n ; i++ )
        {
            if( store.find( nums[i]) == store.end() )
            {
                store[ nums[i] ] = 1;
            }
            else
            {
                store[nums[i]]++;
            }
        }
        
        for( auto it = store.begin(); it != store.end(); ++it )
        {
            if( it->second > 1 )
            {
                return true;
            }
        }
        return false;
    }
};