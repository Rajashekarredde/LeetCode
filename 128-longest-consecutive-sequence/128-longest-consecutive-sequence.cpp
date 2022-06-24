class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set< int >store;
        int n = nums.size();
        
        if(n==0)
        {
            return 0; 
        }
        if(n==1)
        {
            return 1;
        } 
        
        for( int i=0; i<n; ++i )
        {
            if( store.find(nums[i]) == store.end() )
            {
                store.insert( nums[i] );
            }
        }
        
        int count = 0;
        int ans =0;
        
        for( int i =0; i<n ; ++i )
        {
            if( store.find( nums[i] - 1 ) == store.end() )
            {
                count = 0;
                while( store.find( nums[i] + count ) != store.end() )
                {
                    count++;
                }
                ans = max( ans, count );
            }
        }
        return ans;
    }
};