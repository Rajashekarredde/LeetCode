class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count = 0, sum = 0;
        unordered_map<int, int> store;
        int n = nums.size();
        
        for( int i = 0; i<n; ++i )
        {
             sum+= nums[i];
            
            if( sum == k ) count++;
            
            if( store.find( sum - k) != store.end() )
            {
                count = store[ sum -  k] + count;
            }
            
            if( store.find( sum ) != store.end() )
            {
               store[sum]++;
            }
            else
            {
               store[sum] = 1;
            }
        }
        return count;
                     
    }
};